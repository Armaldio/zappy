//
//-----------------------------------------------------------------------------
//Filename:    Player.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/23/17.
//-----------------------------------------------------------------------------
//

#include "Player.hpp"

zappy::Player::Player(unsigned int x, unsigned int y) : _pos(x, y) {
    _inventaire = new Inventaire();
}

zappy::Player::~Player() {
    delete (_inventaire);
}

zappy::Inventaire *zappy::Player::getInventaire() {
    return _inventaire;
}

const sf::Vector2f &zappy::Player::getPosition() const {
    return _pos;
}

void zappy::Player::setPosition(sf::Vector2f const &pos) {
    _pos = pos;
}
