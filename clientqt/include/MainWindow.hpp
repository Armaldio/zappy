#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <RenderCanvas.hpp>
#include <QMainWindow>
#include <thread>
#include <QtWidgets/QTableWidgetItem>

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

    void on_updated_log(const std::string *);

signals:
    void logIsupdated(const std::string *);


private:
    Ui::MainWindow *ui;
    zappy::RenderCanvas *renderCanvas;
    bool _firstShow;
    bool _isSession;
    std::thread *_runnerThread;
    void _runner();
    QVector<QTableWidgetItem *> _teamItems;
};

#endif // MAINWINDOW_H
