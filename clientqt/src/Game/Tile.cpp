//
//-----------------------------------------------------------------------------
//Filename:    Tile.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/23/17.
//-----------------------------------------------------------------------------
//

#include "Tile.hpp"

zappy::Tile::Tile(unsigned int x, unsigned int y) : _pos(x, y) {
    _inventaire = new Inventaire();
}

zappy::Tile::~Tile() {
    delete (_inventaire);
}

zappy::Inventaire *zappy::Tile::getInventaire() {
    return _inventaire;
}

const sf::Vector2f &zappy::Tile::getPosition() const {
    return _pos;
}

void zappy::Tile::setPosition(const sf::Vector2f &pos) {
    Tile::_pos = pos;
}
