#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <RenderCanvas.hpp>
#include <QMainWindow>
#include <thread>
#include <QtWidgets/QTableWidgetItem>
#include <include/Model/TeamTableModel.hpp>
#include <include/Model/PlayerTableModel.hpp>
#include <include/Model/TileTableModel.hpp>
#include <include/Model/EggTableModel.hpp>
#include <include/Model/MessageTableModel.hpp>

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

    void on_saveLogButton_clicked();

    void on_debugcheckBox_stateChanged(int arg1);

    void on_audiocheckBox_stateChanged(int arg1);

    void on_hideBoardcheckBox_stateChanged(int arg1);

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
    MessageTableModel _messageTable;
};

#endif // MAINWINDOW_H
