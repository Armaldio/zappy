#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <RenderCanvas.hpp>
#include <QMainWindow>
#include <thread>
#include <QtWidgets/QTableWidgetItem>
#include <src/Model/TeamTableModel.hpp>

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

    void on_changeTimeButton_pressed();

signals:
    void logIsupdated(const std::string *);


private:
    Ui::MainWindow *ui;
    zappy::RenderCanvas *renderCanvas;
    bool _firstShow;
    bool _isSession;
    std::thread *_runnerThread;
    void _runner();
    TeamTableModel _teamTable;
};

#endif // MAINWINDOW_H
