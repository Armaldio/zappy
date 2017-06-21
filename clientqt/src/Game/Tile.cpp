//
//-----------------------------------------------------------------------------
//Filename:    Tile.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/20/17.
//-----------------------------------------------------------------------------
//

#include <iostream>
#include "Game/Tile.hpp"

zappy::Tile::Tile() {

}

zappy::Tile::~Tile() {

}

zappy::Tile::Tile(unsigned int x, unsigned int y) {
    _pos.y = y;
    _pos.x = x;
    std::cout << "Create pos = " << x << " - " << y << std::endl;
}
