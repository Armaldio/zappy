//
//-----------------------------------------------------------------------------
//Filename:    Game.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/20/17.
//-----------------------------------------------------------------------------
//

#include <iostream>
#include "Game/Map.hpp"

zappy::Map::Map(QSize const &size) {
    auto length = size.width() * size.height();

    for (auto i = 0; i < length; i++) {
        _mapSquares.push_back(new MapSquare((unsigned int) (i % size.width()),
                                            (unsigned int) (i / size.width())));
    }
}

zappy::Map::~Map() {

}

std::vector<zappy::MapSquare *> &zappy::Map::getMapSquares() {
    return _mapSquares;
}

std::vector<zappy::Player *> &zappy::Map::getPlayers() {
    return _players;
}

void zappy::Map::addPlayer(zappy::Player *player) {
    _players.push_back(player);
}
