//
//-----------------------------------------------------------------------------
//Filename:    Team.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/26/17.
//-----------------------------------------------------------------------------
//

#ifndef CLIENTQT_TEAM_HPP
#define CLIENTQT_TEAM_HPP


#include <QtCore/QVector>


namespace zappy {
    class Player;

    struct Team {
        QString teamName;
        QVector<Player *> players;
        unsigned int uniqid;
    };
}


#endif //CLIENTQT_TEAM_HPP
