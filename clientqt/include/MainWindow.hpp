#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <RenderCanvas.hpp>
#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event) override;

    void resizeEvent(QResizeEvent *event) override;

private slots:

    void on_quitButton_pressed();

    void on_connectionButton_pressed();

private:
    Ui::MainWindow *ui;
    zappy::RenderCanvas *renderCanvas;
    bool _firstShow;
};

#endif // MAINWINDOW_H
