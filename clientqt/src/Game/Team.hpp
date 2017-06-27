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
#include "Player.hpp"

namespace zappy {
    struct Team {
        const QString teamName;
        QVector<Player *> players;
    };
}


#endif //CLIENTQT_TEAM_HPP
