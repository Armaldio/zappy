#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <RenderCanvas.hpp>
#include <QMainWindow>
#include <thread>
#include <QtWidgets/QTableWidgetItem>
#include <src/Model/TeamTableModel.hpp>
#include <src/Model/PlayerTableModel.hpp>
#include <src/Model/TileTableModel.hpp>
#include <src/Model/EggTableModel.hpp>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

protected:
    QString format_server = "<span style=\"display:block; font-size:8pt; font-weight:600; color:green;\">%1</span>";
    QString format_client = "<span style=\"display:block; font-size:8pt; font-weight:600; color:yellow;\">%1</span>";
    QString format_error = "<span style=\"display:block; font-size:8pt; font-weight:600; color:red;\">%1</span>";

    void paintEvent(QPaintEvent *event) override;

    void resizeEvent(QResizeEvent *event) override;

    void initLogsBrowser();

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
    PlayerTableModel _playerTable;
    TileTableModel _tileTable;
    EggTableModel _eggTable;
};

#endif // MAINWINDOW_H
