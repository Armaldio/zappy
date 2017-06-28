//
//-----------------------------------------------------------------------------
//Filename:    Egg.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/26/17.
//-----------------------------------------------------------------------------
//

#include "include/Game/Egg.hpp"

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

zappy::Player * zappy::Egg::getPlayer() const {
    return _player;
}

void zappy::Egg::setPlayer(Player *player) {
    Egg::_player = player;
}

zappy::Egg::Egg(unsigned int id, Player * player, int x, int y) : _pos(x, y), _id(id), _player(player) {

}

zappy::Egg::~Egg() {

}

const bool zappy::Egg::isLinked() const {
    return _isLinked;
}

void zappy::Egg::setLinked(bool value) {
    _isLinked = value;
}
