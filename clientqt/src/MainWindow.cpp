#include <QtEvents>
#include <RenderCanvas.hpp>
#include <Scene/SceneManager.hpp>
#include <Network/Network.hpp>
#include <iostream>
#include <include/Game/Game.hpp>
#include <include/Scene/GameScene.hpp>
#include <include/Game/GameExeception.hpp>
#include <QtWidgets/QMessageBox>
#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _teamTable(parent),
    _playerTable(parent),
    _eggTable(parent),
    _tileTable(parent),
    _messageTable(parent),
    _firstShow(false),
    _isSession(false),
    _runnerThread(nullptr),
    renderCanvas(nullptr)
{
    ui->setupUi(this);

    setFixedSize(1024, 768);
    ui->renderFrame->show();
    ui->teamsTable->setModel(&_teamTable);
    ui->playersTable->setModel(&_playerTable);
    ui->eggsTable->setModel(&_eggTable);
    ui->tilesTable->setModel(&_tileTable);
    ui->messagesTable->setModel(&_messageTable);

    zappy::SceneManager::get_instance_ptr()->loadAllRessources();
    connect(this, SIGNAL(logIsupdated(const std::string *)), this, SLOT(on_updated_log(const std::string *)));
    initLogsBrowser();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete renderCanvas;
}

void MainWindow::on_quitButton_pressed()
{
    auto sceneManager = zappy::SceneManager::get_instance_ptr();
    auto network = zappy::Network::get_instance_ptr();

    if (_isSession) {
        initLogsBrowser();
        ui->quitButton->setText("Close");
        ui->statusConnectionLabel->setText("Network: closed");
        _isSession = false;
        network->getIncoming().enqueue(new std::string("Graphic Exit!"));
        network->closeConnection();
        _runnerThread->join();
        delete(_runnerThread);
        sceneManager->runScene("splashScreen");
        sceneManager->unloadRessources();
        sceneManager->loadRessources();
    } else {
        close();
    }
}

void MainWindow::on_connectionButton_pressed()
{
    auto sceneManager = zappy::SceneManager::get_instance_ptr();
    auto network = zappy::Network::get_instance_ptr();

    if (network->getSocket().isValid()) {
        ui->statusConnectionLabel->setText("Network: already connected");

    }
    else if (network->newConnection(ui->hostEdit->text().toStdString(), ui->portEdit->text().toStdString()))
    {
        ui->statusConnectionLabel->setText("Network: success");
        ui->quitButton->setText("Disconnection");
        _isSession = true;
        network->run();
        _runnerThread = new std::thread(&MainWindow::_runner, this);
        sceneManager->loadAllRessources();
        sceneManager->runScene("gameScene");

    }
    else
    {
        network->closeConnection();
        ui->statusConnectionLabel->setText("Network: failed");
    }
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    if (renderCanvas)
        renderCanvas->resize(ui->renderFrame->size());
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    if (!_firstShow) {
        renderCanvas = new zappy::RenderCanvas(ui->renderFrame, QPoint(0, 0), ui->renderFrame->size(), 11);
        renderCanvas->show();
        _firstShow = true;
    }
}

void MainWindow::_runner() {
    std::string *command = nullptr;
    auto network = zappy::Network::get_instance_ptr();

    while (_isSession) {
        command = network->getIncoming().dequeue();
        emit logIsupdated(command);
    }
}

void MainWindow::on_updated_log(const std::string *command) {
    if (command == nullptr)
        return;

    auto game = zappy::Game::get_instance_ptr();

    try {
        const QString qs_command(command->c_str());

        if (game->fexecute(*command))
            ui->logsBrowser->append(format_server.arg(qs_command));
        else
            ui->logsBrowser->append(format_error.arg(qs_command));

        _teamTable.setElements(game->getTeams());
        _playerTable.setElements(game->getPlayers());
        _tileTable.setElements(game->getTiles());
        _eggTable.setElements(game->getEggs());
        _messageTable.setElements(game->getMessages());
    } catch (GameException &e) {
        QMessageBox msgBox;
        QString message;
        message = "GameException: ";
        message +=  e.what();
        msgBox.setText(message);
        msgBox.setInformativeText("Do you want continue ?");
        msgBox.setStandardButtons(QMessageBox::Cancel | QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Cancel);
        int ret = msgBox.exec();
        switch (ret) {
            case QMessageBox::Cancel:
                on_quitButton_pressed();
                break;
        }
    }
    delete(command);
}

void MainWindow::on_changeTimeButton_pressed()
{
    auto network = zappy::Network::get_instance_ptr();

    if (_isSession) {
        const std::string changeTime("sst " + ui->timeEdit->text().toStdString() + "\n");
        const QString qs_command("sst" + ui->timeEdit->text());
        ui->logsBrowser->append(format_client.arg(qs_command));
        network->send(changeTime);
    }
}

void MainWindow::initLogsBrowser() {
    ui->logsBrowser->clear();
}
