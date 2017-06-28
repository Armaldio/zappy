//
//-----------------------------------------------------------------------------
//Filename:    Tile.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/23/17.
//-----------------------------------------------------------------------------
//

#include "include/Game/Tile.hpp"

zappy::Tile::Tile(unsigned int x, unsigned int y) : _pos(x, y) {
    _inventaire = new Inventaire();
    _isHighlighted = false;
    _isBusy = false;
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

void zappy::Tile::togleHighlight() {
    _isHighlighted = !_isHighlighted;
}

bool zappy::Tile::isHilghlighted() const {
    return _isHighlighted;
}

void zappy::Tile::setHightlight(bool value) {
    _isHighlighted = value;
}

bool zappy::Tile::isBusy() const {
    return _isBusy;
}

void zappy::Tile::setBusy(bool busy) {
    Tile::_isBusy = busy;
}
