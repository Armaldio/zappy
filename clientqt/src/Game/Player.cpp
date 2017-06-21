//
//-----------------------------------------------------------------------------
//Filename:    Player.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/20/17.
//-----------------------------------------------------------------------------
//

#include "Game/Player.hpp"

zappy::Player::Player(const sf::Vector2f &position) : _inventaire(new Inventaire(position)) {

}

zappy::Player::~Player() {
    if (_inventaire)
        delete(_inventaire);
}

Inventaire *zappy::Player::getInventaire() const {
    return _inventaire;
}
