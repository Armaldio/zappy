#include <QtEvents>
#include <RenderCanvas.hpp>
#include <Scene/SceneManager.hpp>
#include <iostream>
#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _firstShow(false)
{
    ui->setupUi(this);

    setFixedSize(1024, 768);
    ui->renderFrame->show();
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
