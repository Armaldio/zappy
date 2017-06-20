#include <RenderCanvas.hpp>
#include <Scene/SceneManager.hpp>
#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(1024, 768);
    renderCanvas = new zappy::RenderCanvas(ui->renderFrame, QPoint(0, 0), QSize(ui->renderFrame->geometry().size()), 0);
    renderCanvas->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete renderCanvas;
}

void MainWindow::on_quitButton_pressed()
{
    close();
}

void MainWindow::on_connectionButton_pressed()
{
    auto sceneManager = zappy::SceneManager::get_instance_ptr();

    sceneManager->loadAllRessources();
    sceneManager->runScene("gameScene");
}
