//
//-----------------------------------------------------------------------------
//Filename:    Inventaire.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/20/17.
//-----------------------------------------------------------------------------
//

#include "Game/Inventaire.hpp"

const sf::Vector2f &Inventaire::getPos() const {
    return _pos;
}

void Inventaire::setPos(const sf::Vector2f &_pos) {
    Inventaire::_pos = _pos;
}

int Inventaire::getNourriture() const {
    return _returnAllmat[NOURRITURE];
}

void Inventaire::setNourriture(int _nourriture) {
    Inventaire::_returnAllmat[NOURRITURE] = _nourriture;
}

int Inventaire::getLinemate() const {
    return _returnAllmat[LINEMATE];
}

void Inventaire::setLinemate(int _linemate) {
    Inventaire::_returnAllmat[LINEMATE] = _linemate;
}

int Inventaire::getDeraumere() const {
    return _returnAllmat[DERAUMERE];
}

void Inventaire::setDeraumere(int _deraumere) {
    Inventaire::_returnAllmat[DERAUMERE] = _deraumere;
}

int Inventaire::getSibur() const {
    return _returnAllmat[SIBUR];
}

void Inventaire::setSibur(int _sibur) {
    Inventaire::_returnAllmat[SIBUR] = _sibur;
}

int Inventaire::getMendiane() const {
    return _returnAllmat[MENDIANE];
}

void Inventaire::setMendiane(int _mendiane) {
    Inventaire::_returnAllmat[MENDIANE] = _mendiane;
}

int Inventaire::getPhiras() const {
    return _returnAllmat[PHIRAS];
}

void Inventaire::setPhiras(int _phiras) {
    Inventaire::_returnAllmat[PHIRAS] = _phiras;
}

int Inventaire::getThystame() const {
    return _returnAllmat[THYSTAME];
}

void Inventaire::setThystame(int _thystame) {
    Inventaire::_returnAllmat[THYSTAME] = _thystame;
}

Inventaire::Inventaire(const sf::Vector2f & position) : _pos(position) {
    for (int i = 0; i < getNbMat(); ++i) {
        _returnAllmat[i] = 0;
    }
}

Inventaire::~Inventaire() {

}

int Inventaire::getNbMat() const {
    return _nbMat;
}

const int *Inventaire::getAllMat() const {
    return _returnAllmat;
}
