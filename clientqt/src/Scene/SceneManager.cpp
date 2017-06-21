//
//-----------------------------------------------------------------------------
//Filename:    SceneManager.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/20/17.
//-----------------------------------------------------------------------------
//

#include <iostream>
#include "Scene/SceneManager.hpp"

zappy::SceneManager::SceneManager() : _currentScene(nullptr) {

}

zappy::SceneManager::~SceneManager() {

}

void zappy::SceneManager::loadRessources() {
    _currentScene->loadRessources();
}

void zappy::SceneManager::unloadRessources() {
    _currentScene->unloadRessources();
}

void zappy::SceneManager::update(sf::Event const &event) {
    _currentScene->update(event);
}

void zappy::SceneManager::draw() {
    _currentScene->draw();
}

zappy::Scene *zappy::SceneManager::getCurrentScene() {
    return _currentScene;
}

zappy::Scene *zappy::SceneManager::selectScene(std::string const &name) {
    for (auto scene : _scenes)
        if (scene->getName() == name)
            return scene;
    return nullptr;
}

bool zappy::SceneManager::addScene(zappy::Scene *scene) {
    if (scene == nullptr)
        return false;
    for (auto sc : _scenes)
        if (sc == scene || sc->getName() == scene->getName())
            return false;
    _scenes.push_back(scene);
    if (_scenes.size() == 1)
        _currentScene = _scenes.back();
    return true;
}

void zappy::SceneManager::loadAllRessources() {
    for (auto scene : _scenes)
        scene->loadRessources();
}

void zappy::SceneManager::unloadAllRessources() {
    for (auto scene : _scenes)
        scene->unloadRessources();
}

bool zappy::SceneManager::runScene(std::string const &name) {
    for (auto scene : _scenes) {
        if (scene->getName() == name) {
            _currentScene = scene;
            return true;
        }
    }
    throw std::runtime_error("runScene invalid name ref!");
    return false;
}

void zappy::SceneManager::resize(unsigned int width, unsigned int height) {
    _currentScene->resize(width, height);
}
