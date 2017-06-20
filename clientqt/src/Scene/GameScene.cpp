//
//-----------------------------------------------------------------------------
//Filename:    GameScene.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/20/17.
//-----------------------------------------------------------------------------
//

#include <iostream>
#include "include/Scene/GameScene.hpp"

zappy::GameScene::GameScene(sf::RenderWindow *renderWindow, const std::string &name)
        : Scene(renderWindow, name), _map(nullptr) {
    _ratio.x = 0;
    _ratio.y = 0;
    _map = new Map(QSize(10, 10));
}

void zappy::GameScene::loadRessources() {
    if (!_initialized) {
        _recShape.setFillColor(sf::Color::Green);
        _initialized = true;
        resize();
    }
}

void zappy::GameScene::unloadRessources() {

}

void zappy::GameScene::update() {

}

void zappy::GameScene::draw() {
    if (_map == nullptr)
        return;
    auto &blocks = _map->getMapSquares();

    for (auto block : blocks) {
        const sf::Vector2f pos(((block->getPos().x) * _ratio.x + 10 * block->getPos().x),
                               ((block->getPos().y) * _ratio.y + 10 * block->getPos().y));
        block->rectangleShape.setPosition(pos);
        block->rectangleShape.setSize(_ratio);
        block->rectangleShape.setFillColor(sf::Color::Red);
        _renderWindow->draw(block->rectangleShape);
    }
}

void zappy::GameScene::resize() {
    _ratio.x = _renderWindow->getSize().x;
    _ratio.x /= 10;
    _ratio.y = _renderWindow->getSize().y;
    _ratio.y /= 10;
    _recShape.setSize(_ratio);
}
