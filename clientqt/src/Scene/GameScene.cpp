//
//-----------------------------------------------------------------------------
//Filename:    GameScene.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/20/17.
//-----------------------------------------------------------------------------
//

#include <iostream>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "include/Scene/GameScene.hpp"

zappy::GameScene::GameScene(sf::RenderWindow *renderWindow, const std::string &name)
        : Scene(renderWindow, name), _map(nullptr),
          _lastX(0), _lastY(0), _lastDiffX(0), _lastDiffY(0), _zoomAmount(1.1f), _currentZoom(1.0f) {
    _ratio.x = 0;
    _ratio.y = 0;
    _map = new Map(QSize(10, 10));
}

void zappy::GameScene::loadRessources() {
    if (!_initialized) {
        _tileTextures[0].loadFromFile("assets/ground.png", sf::IntRect(32, 32, 32, 32));
        _tileTextures[1].loadFromFile("assets/ground.png", sf::IntRect(64, 32, 32, 32));
        _tileTextures[2].loadFromFile("assets/ground.png", sf::IntRect(128, 32, 32, 32));

        _matTextures[0].loadFromFile("assets/items.png", sf::IntRect(0 * 34, 15 * 34, 32, 32));
        _matTextures[1].loadFromFile("assets/items.png", sf::IntRect(1 * 34, 15 * 34, 32, 32));
        _matTextures[2].loadFromFile("assets/items.png", sf::IntRect(2 * 34, 15 * 34, 32, 32));
        _matTextures[3].loadFromFile("assets/items.png", sf::IntRect(3 * 34, 15 * 34, 32, 32));
        _matTextures[4].loadFromFile("assets/items.png", sf::IntRect(4 * 34, 15 * 34, 32, 32));
        _matTextures[5].loadFromFile("assets/items.png", sf::IntRect(5 * 34, 15 * 34, 32, 32));
        _matTextures[6].loadFromFile("assets/items.png", sf::IntRect(6 * 34, 15 * 34, 32, 32));

        _recShape.setFillColor(sf::Color::Green);
        _initialized = true;
        resize(0, 0);
    }
}

void zappy::GameScene::zoomViewAt(sf::Vector2i pixel, sf::RenderWindow& window, float zoom)
{
    const sf::Vector2f beforeCoord{ window.mapPixelToCoords(pixel) };
    sf::View view{ window.getView() };
    view.zoom(zoom);
    window.setView(view);
    const sf::Vector2f afterCoord{ window.mapPixelToCoords(pixel) };
    const sf::Vector2f offsetCoords{ beforeCoord - afterCoord };
    view.move(offsetCoords);
    window.setView(view);
}


void zappy::GameScene::unloadRessources() {

}

void zappy::GameScene::update(sf::Event const &event) {
    switch (event.type) {
        case sf::Event::MouseMoved:
            if ((_lastX && _lastY) || (_lastDiffX || _lastDiffY))
            {
                _lastDiffY = _lastY - event.mouseMove.y;
                _lastDiffX = _lastX - event.mouseMove.x;
                _cameraView.move(_lastDiffX, _lastDiffY);;
            }
            _renderWindow->setView(_cameraView);
            zoomViewAt({ _lastDiffY, _lastDiffX }, *_renderWindow, _currentZoom);
            _lastX = event.mouseMove.x;
            _lastY = event.mouseMove.y;
            break;
        case sf::Event::MouseButtonReleased:
            _lastDiffY = _lastDiffX = _lastX = _lastY = 0;
            break;
        case sf::Event::MouseWheelMoved:
            _renderWindow->setView(_cameraView);
            if (event.mouseWheel.delta > 0)
                _currentZoom = (1.f / (_zoomAmount + abs(event.mouseWheel.delta)));
            else if (event.mouseWheel.delta < 0)
                _currentZoom = (_zoomAmount + abs(event.mouseWheel.delta));
            zoomViewAt({_lastX, _lastY}, *_renderWindow, _currentZoom);
            break;
    }

}

void zappy::GameScene::draw() {
    if (_map == nullptr)
        return;
    auto &blocks = _map->getTiles();

    for (auto block : blocks) {
        const sf::Vector2f pos(((block->getPos().x) * _ratio.x + 1 * block->getPos().x),
                               ((block->getPos().y) * _ratio.y + 1 * block->getPos().y));
        block->rectangleShape.setPosition(pos);
        block->rectangleShape.setSize(_ratio);
        block->rectangleShape.setFillColor(sf::Color::White);
        block->rectangleShape.setTexture(&_tileTextures[1]);
        _renderWindow->draw(block->rectangleShape);

        const float sizeSquare = _ratio.x / 12.f;
        const auto materials = block->getAllMat();
        for (int i = 0; i < block->getNbMat(); ++i) {
            if (materials[i] == 0)
                continue;
            block->matShape[i].setPosition(pos.x + 10 + (i % 5) * (sizeSquare + 10),
                                           pos.y + sizeSquare + ((int)(i / 5)) * (sizeSquare + 10));
            block->matShape[i].setSize(sf::Vector2f(sizeSquare, sizeSquare));
            block->matShape[i].setTexture(&_matTextures[i]);
            _renderWindow->draw(block->matShape[i]);
        }


    }
}

void zappy::GameScene::resize(unsigned int width, unsigned int height) {
    _ratio.x = _renderWindow->getSize().x;
    _ratio.x /= 4;
    _ratio.y = _renderWindow->getSize().y;
    _ratio.y /= 4;
    _recShape.setSize(_ratio);
    _cameraView.setSize(_renderWindow->getSize().x, _renderWindow->getSize().y);
    _cameraView.setCenter(_renderWindow->getSize().x, _renderWindow->getSize().y);
    _renderWindow->setView(_cameraView);

}
