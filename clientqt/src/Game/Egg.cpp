//
//-----------------------------------------------------------------------------
//Filename:    Egg.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/26/17.
//-----------------------------------------------------------------------------
//

#include "Egg.hpp"

const sf::Vector2f &zappy::Egg::getPosition() const {
    return _pos;
}

void zappy::Egg::setPosition(const sf::Vector2f &_pos) {
    Egg::_pos = _pos;
}

unsigned int zappy::Egg::getId() const {
    return _id;
}

void zappy::Egg::setId(unsigned int _id) {
    Egg::_id = _id;
}

unsigned int zappy::Egg::getPlayerId() const {
    return _player_id;
}

void zappy::Egg::setPlayerId(unsigned int _player_id) {
    Egg::_player_id = _player_id;
}

zappy::Egg::Egg(unsigned int id, unsigned player_id, int x, int y) : _pos(x, y), _id(id), _player_id(player_id) {

}

zappy::Egg::~Egg() {

}
