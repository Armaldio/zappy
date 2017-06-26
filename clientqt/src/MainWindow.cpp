#include <QtEvents>
#include <RenderCanvas.hpp>
#include <Scene/SceneManager.hpp>
#include <Network/Network.hpp>
#include <iostream>
#include <src/Game/Game.hpp>
#include <include/Scene/GameScene.hpp>
#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _firstShow(false),
    _isSession(false),
    _runnerThread(nullptr),
    renderCanvas(nullptr)
{
    ui->setupUi(this);

    setFixedSize(1024, 768);
    ui->renderFrame->show();
    zappy::SceneManager::get_instance_ptr()->loadAllRessources();
    connect(this, SIGNAL(logIsupdated(const std::string *)), this, SLOT(on_updated_log(const std::string *)));
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
        ui->logsBrowser->clear();
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
    ui->logsBrowser->append(command->c_str());
    game->fexecute(*command);
    delete(command);
}