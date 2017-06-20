//
//-----------------------------------------------------------------------------
//Filename:    Invetaire.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/20/17.
//-----------------------------------------------------------------------------
//

#include "Inventaire.hpp"

const sf::Vector2i &Invetaire::get_pos() const {
    return _pos;
}

void Invetaire::setPos(const sf::Vector2i &_pos) {
    Invetaire::_pos = _pos;
}

int Invetaire::getNourriture() const {
    return _nourriture;
}

void Invetaire::setNourriture(int _nourriture) {
    Invetaire::_nourriture = _nourriture;
}

int Invetaire::getLinemate() const {
    return _linemate;
}

void Invetaire::setLinemate(int _linemate) {
    Invetaire::_linemate = _linemate;
}

int Invetaire::getDeraumere() const {
    return _deraumere;
}

void Invetaire::setDeraumere(int _deraumere) {
    Invetaire::_deraumere = _deraumere;
}

int Invetaire::getSibur() const {
    return _sibur;
}

void Invetaire::setSibur(int _sibur) {
    Invetaire::_sibur = _sibur;
}

int Invetaire::getMendiane() const {
    return _mendiane;
}

void Invetaire::setMendiane(int _mendiane) {
    Invetaire::_mendiane = _mendiane;
}

int Invetaire::getPhiras() const {
    return _phiras;
}

void Invetaire::setPhiras(int _phiras) {
    Invetaire::_phiras = _phiras;
}

int Invetaire::getThystame() const {
    return _thystame;
}

void Invetaire::setThystame(int _thystame) {
    Invetaire::_thystame = _thystame;
}

Invetaire::Invetaire() : _deraumere(0),
                         _linemate(0),
                         _mendiane(0),
                         _nourriture(0),
                         _phiras(0),
                         _pos(0, 0),
                         _sibur(0),
                         _thystame(0) {

}

Invetaire::~Invetaire() {

}
