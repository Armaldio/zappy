//
//-----------------------------------------------------------------------------
//Filename:    main.cpp
//-----------------------------------------------------------------------------
//
//
// Created by bonett_w on 6/19/17.
//-----------------------------------------------------------------------------
//

#include <RenderCanvas.hpp>
#include <QApplication>
#include <QFrame>
#include <MainWindow.hpp>
#include <sstream>
#include <iostream>

int main(int ac, char **av)
{
    QApplication application(ac, av);
    QCoreApplication::setOrganizationName("Team Zappy");
    QCoreApplication::setApplicationName("Zappy");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);

    MainWindow mainWindow(0);

    mainWindow.resize(800, 600);
    mainWindow.show();

    int ret = application.exec();
    return ret;
}