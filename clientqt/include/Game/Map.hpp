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
#include "Tile.hpp"
#include "Player.hpp"

namespace zappy {
    class Map {
    private:
        std::vector<Tile *> _mapSquares;
        std::vector<Player *> _players;
        QSize _mapSize;

    public:
        Map(QSize const &size);

        virtual ~Map();

        std::vector<Tile *> &getTiles();

        std::vector<Player *> &getPlayers();

        void addPlayer(Player *player);
    };
}


#endif //CLIENTQT_MAP_HPP
