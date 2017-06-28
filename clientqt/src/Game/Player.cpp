//
//-----------------------------------------------------------------------------
//Filename:    Player.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/23/17.
//-----------------------------------------------------------------------------
//

#include "include/Game/Player.hpp"

zappy::Player::Player(unsigned int id, int level, int orientation, unsigned int x, unsigned int y) :
        _pos(x, y),
        _level(level),
        _orientation(orientation),
        _id(id),
        animatedLoading(sf::microseconds(5))
{
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

int zappy::Player::getOrientation() const {
    return _orientation;
}

void zappy::Player::setOrientation(int _orientation) {
    Player::_orientation = _orientation;
}

int zappy::Player::getLevel() const {
    return _level;
}

void zappy::Player::setLevel(int _level) {
    Player::_level = _level;
}

void zappy::Player::setCollecting(bool value) {
    _isCollecting = value;
}

bool zappy::Player::isCollecting() const {
    return _isCollecting;
}

unsigned int zappy::Player::getId() const {
    return _id;
}

void zappy::Player::setId(unsigned int id) {
    Player::_id = id;
}
