//
//-----------------------------------------------------------------------------
//Filename:    Scene.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/20/17.
//-----------------------------------------------------------------------------
//

#include <iostream>
#include "include/Scene/Scene.hpp"

zappy::Scene::Scene(sf::RenderWindow *renderWindow, const std::string &name)
        :_renderWindow(renderWindow),  _stateName(name), _initialized(false) {
    std::cout << "Scene name = " << name << std::endl;
}

zappy::Scene::~Scene() {

}

const std::string &zappy::Scene::getName() const {
    return _stateName;
}
