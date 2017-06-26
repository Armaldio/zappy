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
        : Scene(renderWindow, name), /* _map(nullptr), */
          _lastX(0), _lastY(0), _lastDiffX(0), _lastDiffY(0), _zoomAmount(1.1f), _currentZoom(1.0f) {
    _ratio.x = 0;
    _ratio.y = 0;
    _game = zappy::Game::get_instance_ptr();
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

        _characterTexture.loadFromFile("assets/items.png", sf::IntRect(5 * 34, 26 * 34, 32, 32));
        _eggTexture.loadFromFile("assets/items.png", sf::IntRect(6 * 34, 26 * 34, 32, 32));

        _recShape.setFillColor(sf::Color::Green);
        _initialized = true;
        resize(0, 0);
    }
}

void zappy::GameScene::zoomViewAt(sf::Vector2i pixel, sf::RenderWindow& window, float zoom)
{
    std::cout << "view zoom: " << zoom << std::endl;
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
    _initialized = 0;
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
    if (!_game->isMapped())
        return;

    auto &blocks = _game->getTiles();

    for (auto block : blocks) {
        const sf::Vector2f pos(((block->getPosition().x) * _ratio.x + 1 * block->getPosition().x),
                               ((block->getPosition().y) * _ratio.y + 1 * block->getPosition().y));
        block->rectangleShape.setPosition(pos);
        block->rectangleShape.setSize(_ratio);
        if (block->isHilghlighted())
            block->rectangleShape.setFillColor(sf::Color::Red);
        else
            block->rectangleShape.setFillColor(sf::Color::White);
        block->rectangleShape.setTexture(&_tileTextures[1]);
        _renderWindow->draw(block->rectangleShape);

        const float sizeSquare = _ratio.x / 12.f;
        const auto inventaire = block->getInventaire();
        for (int i = 0; i < 7; ++i) {
            if (inventaire->getMaterial((const Inventaire::TypeMaterial) i) == 0)
                continue;
            block->matShape[i].setPosition(pos.x + 10 + (i % 5) * (sizeSquare + 10),
                                           pos.y + sizeSquare + ((int)(i / 5)) * (sizeSquare + 10));
            block->matShape[i].setSize(sf::Vector2f(sizeSquare, sizeSquare));
            block->matShape[i].setTexture(&_matTextures[i]);
            _renderWindow->draw(block->matShape[i]);
        }
    }

    auto &players = _game->getPlayers();
    for (auto player : players) {
        const auto inventaire = player->getInventaire();
        const auto realPosition = player->getPosition();
        const sf::Vector2f pos(((realPosition.x) * _ratio.x + 1 * realPosition.x + _ratio.x / 2),
                               ((realPosition.y) * _ratio.y + 1 * realPosition.y + _ratio.y / 2));
        const float squareSize = _ratio.x / 2;
        player->characterShape.setPosition(pos);
        player->characterShape.setSize({squareSize, squareSize});
        player->characterShape.setOrigin({squareSize / 2, squareSize / 2});
        player->characterShape.setTexture(&_characterTexture);
        _renderWindow->draw(player->characterShape);
    }

    auto &eggs = _game->getEggs();
    for (auto egg : eggs) {
        const auto realPosition = egg->getPosition();
        const sf::Vector2f pos(((realPosition.x) * _ratio.x + 1 * realPosition.x + _ratio.x / 2),
                              ((realPosition.y) * _ratio.y + 1 * realPosition.y + _ratio.y / 2));

        const float squareSize = _ratio.x / 2;
        egg->corpShape.setPosition(pos);
        egg->corpShape.setSize({squareSize, squareSize});
        egg->corpShape.setOrigin({squareSize / 2, squareSize / 2});
        egg->corpShape.setTexture(&_characterTexture);
        _renderWindow->draw(egg->corpShape);
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
