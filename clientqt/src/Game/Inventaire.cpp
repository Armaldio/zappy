//
//-----------------------------------------------------------------------------
//Filename:    Inventaire.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/20/17.
//-----------------------------------------------------------------------------
//

#include "Game/Inventaire.hpp"

const sf::Vector2i &Inventaire::getPos() const {
    return _pos;
}

void Inventaire::setPos(const sf::Vector2i &_pos) {
    Inventaire::_pos = _pos;
}

int Inventaire::getNourriture() const {
    return _nourriture;
}

void Inventaire::setNourriture(int _nourriture) {
    Inventaire::_nourriture = _nourriture;
}

int Inventaire::getLinemate() const {
    return _linemate;
}

void Inventaire::setLinemate(int _linemate) {
    Inventaire::_linemate = _linemate;
}

int Inventaire::getDeraumere() const {
    return _deraumere;
}

void Inventaire::setDeraumere(int _deraumere) {
    Inventaire::_deraumere = _deraumere;
}

int Inventaire::getSibur() const {
    return _sibur;
}

void Inventaire::setSibur(int _sibur) {
    Inventaire::_sibur = _sibur;
}

int Inventaire::getMendiane() const {
    return _mendiane;
}

void Inventaire::setMendiane(int _mendiane) {
    Inventaire::_mendiane = _mendiane;
}

int Inventaire::getPhiras() const {
    return _phiras;
}

void Inventaire::setPhiras(int _phiras) {
    Inventaire::_phiras = _phiras;
}

int Inventaire::getThystame() const {
    return _thystame;
}

void Inventaire::setThystame(int _thystame) {
    Inventaire::_thystame = _thystame;
}

Inventaire::Inventaire() : _deraumere(0),
                         _linemate(0),
                         _mendiane(0),
                         _nourriture(0),
                         _phiras(0),
                         _pos(0, 0),
                         _sibur(0),
                         _thystame(0) {

}

Inventaire::~Inventaire() {

}
