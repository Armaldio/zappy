//
//-----------------------------------------------------------------------------
//Filename:    Inventaire.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/23/17.
//-----------------------------------------------------------------------------
//

#include "include/Game/Inventaire.hpp"

zappy::Inventaire::Inventaire() {
    for (int i = 0; i < 7; ++i) {
        _materials[i] = 0;
    }
}

zappy::Inventaire::~Inventaire() {

}

zappy::Inventaire::Inventaire(const zappy::Inventaire &other) {
    for (int i = 0; i < 7; ++i) {
        _materials[i] = other._materials[i];
    }
}

zappy::Inventaire &zappy::Inventaire::operator=(const zappy::Inventaire &other) {
    for (int i = 0; i < 7; ++i) {
        _materials[i] = other._materials[i];
    }
    return *this;
}

int zappy::Inventaire::getMaterial(const zappy::Inventaire::TypeMaterial type) {
    return _materials[type];
}

int zappy::Inventaire::getNourriture(void) const {
    return _materials[Nourriture];
}

int zappy::Inventaire::getLinemate(void) const {
    return _materials[Linemate];
}

int zappy::Inventaire::getDeraumere(void) const {
    return _materials[Deraumere];
}

int zappy::Inventaire::getSibur(void) const {
    return _materials[Sibur];
}

int zappy::Inventaire::getMendiane(void) const {
    return _materials[Mendiane];
}

int zappy::Inventaire::getPhiras(void) const {
    return _materials[Phiras];
}

int zappy::Inventaire::getThystame(void) const {
    return _materials[Thystame];
}

void zappy::Inventaire::setNourriture(int value) {
    _materials[Nourriture] = value;
}

void zappy::Inventaire::setLinemate(int value) {
    _materials[Linemate] = value;
}

void zappy::Inventaire::setDeraumere(int value) {
    _materials[Deraumere] = value;
}

void zappy::Inventaire::setSibur(int value) {
    _materials[Sibur] = value;
}

void zappy::Inventaire::setMendiane(int value) {
    _materials[Mendiane] = value;
}

void zappy::Inventaire::setPhiras(int value) {
    _materials[Phiras] = value;
}

void zappy::Inventaire::setThystame(int value) {
    _materials[Thystame] = value;
}

void zappy::Inventaire::setMaterial(const zappy::Inventaire::TypeMaterial type, const int value) {
    _materials[type] = value;
}
