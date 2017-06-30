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

zappy::Egg::Egg(unsigned int id, Player * player, int x, int y) : _pos(x, y), _id(id), _player(player) {
    if (player)
        _team = player->getTeam()->teamName.toStdString();
    else
        _team = "Unknown";
}

zappy::Egg::~Egg() {

}

const bool zappy::Egg::isHatch() const {
    return _isHatch;
}

void zappy::Egg::setHatches(bool value) {
    _isHatch = value;
}

zappy::Player *zappy::Egg::getPlayer() const {
    return _player;
}

void zappy::Egg::setPlayer(zappy::Player *player) {
    _player = player;
}

const std::string &zappy::Egg::getTeamName() const {
    return _team;
}

unsigned int zappy::Egg::getPlayerId() const {
    return _player_id;
}

void zappy::Egg::setPlayerId(unsigned int value) {
    _player_id = value;
}
