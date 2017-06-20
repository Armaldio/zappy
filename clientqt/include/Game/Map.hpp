//
//-----------------------------------------------------------------------------
//Filename:    Game.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/20/17.
//-----------------------------------------------------------------------------
//

#ifndef CLIENTQT_MAP_HPP
#define CLIENTQT_MAP_HPP

#include <Game/Inventaire.hpp>
#include <vector>
#include <mutex>
#include <QtCore/QSize>
#include "MapSquare.hpp"
#include "Player.hpp"

namespace zappy {
    class Map {
    private:
        std::vector<MapSquare *> _mapSquares;
        std::vector<Player *> _players;
        QSize _mapSize;

    public:
        Map(QSize const &size);

        virtual ~Map();

        std::vector<MapSquare *> &getMapSquares();

        std::vector<Player *> &getPlayers();

        void addPlayer(Player *player);
    };
}


#endif //CLIENTQT_MAP_HPP
