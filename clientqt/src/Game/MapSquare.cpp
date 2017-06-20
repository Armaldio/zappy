//
//-----------------------------------------------------------------------------
//Filename:    MapSquare.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/20/17.
//-----------------------------------------------------------------------------
//

#include <iostream>
#include "Game/MapSquare.hpp"

zappy::MapSquare::MapSquare() {

}

zappy::MapSquare::~MapSquare() {

}

zappy::MapSquare::MapSquare(unsigned int x, unsigned int y) {
    _pos.y = y;
    _pos.x = x;
    std::cout << "Create pos = " << x << " - " << y << std::endl;
}
