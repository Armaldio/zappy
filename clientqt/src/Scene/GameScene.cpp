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
#include <cmath>
#include <include/Game/GameExeception.hpp>
#include "include/Scene/GameScene.hpp"
#include "include/Game/Animation.hpp"

zappy::GameScene::GameScene(sf::RenderWindow *renderWindow, const std::string &name)
        : Scene(renderWindow, name), /* _map(nullptr), */
          _lastX(0), _lastY(0), _lastDiffX(0), _lastDiffY(0), _targetZoom(0),
          _currentZoom(0), _previousZoom(0), _zooming(false), _lerpFactor(0.1f) {
    _ratio.x = 0;
    _ratio.y = 0;
    _game = zappy::Game::get_instance_ptr();
}

void zappy::GameScene::loadRessources() {
    if (!_initialized) {


        if (!_characterTexture.loadFromFile("assets/character.png"))
            throw GameException("Failed to load player spritesheet!");
        if (!_loadingTexture.loadFromFile("assets/loading.png"))
            throw GameException("Failed to load player spritesheet!");

        // Down
        _walkingAnimation[0].setSpriteSheet(_characterTexture);
        _walkingAnimation[0].addFrame(sf::IntRect(32, 0, 32, 32));
        _walkingAnimation[0].addFrame(sf::IntRect(64, 0, 32, 32));
        _walkingAnimation[0].addFrame(sf::IntRect(32, 0, 32, 32));
        _walkingAnimation[0].addFrame(sf::IntRect( 0, 0, 32, 32));

        // Left
        _walkingAnimation[3].setSpriteSheet(_characterTexture);
        _walkingAnimation[3].addFrame(sf::IntRect(32, 32, 32, 32));
        _walkingAnimation[3].addFrame(sf::IntRect(64, 32, 32, 32));
        _walkingAnimation[3].addFrame(sf::IntRect(32, 32, 32, 32));
        _walkingAnimation[3].addFrame(sf::IntRect( 0, 32, 32, 32));

        // Right
        _walkingAnimation[1].setSpriteSheet(_characterTexture);
        _walkingAnimation[1].addFrame(sf::IntRect(32, 64, 32, 32));
        _walkingAnimation[1].addFrame(sf::IntRect(64, 64, 32, 32));
        _walkingAnimation[1].addFrame(sf::IntRect(32, 64, 32, 32));
        _walkingAnimation[1].addFrame(sf::IntRect( 0, 64, 32, 32));

        // Up
        _walkingAnimation[2].setSpriteSheet(_characterTexture);
        _walkingAnimation[2].addFrame(sf::IntRect(32, 96, 32, 32));
        _walkingAnimation[2].addFrame(sf::IntRect(64, 96, 32, 32));
        _walkingAnimation[2].addFrame(sf::IntRect(32, 96, 32, 32));
        _walkingAnimation[2].addFrame(sf::IntRect( 0, 96, 32, 32));

        // Loading
        _loadingAnimation.setSpriteSheet(_loadingTexture);
        for (int i = 0; i < 3240; i += 135) {
            _loadingAnimation.addFrame(sf::IntRect(i, 0, 135, 135));
        }

        _renderWindow->setMouseCursorVisible(true);
        _tileTextures[0].loadFromFile("assets/ground.png", sf::IntRect(32, 32, 32, 32));
        _tileTextures[1].loadFromFile("assets/ground.png", sf::IntRect(64, 32, 32, 32));
        _tileTextures[2].loadFromFile("assets/ground.png", sf::IntRect(128, 32, 32, 32));
        _tileTextures[3].loadFromFile("assets/ground.png", sf::IntRect(5 * 32, 3 * 32, 32, 32));

        _matTextures[0].loadFromFile("assets/items.png", sf::IntRect(0 * 34, 15 * 34, 32, 32));
        _matTextures[1].loadFromFile("assets/items.png", sf::IntRect(1 * 34, 15 * 34, 32, 32));
        _matTextures[2].loadFromFile("assets/items.png", sf::IntRect(2 * 34, 15 * 34, 32, 32));
        _matTextures[3].loadFromFile("assets/items.png", sf::IntRect(3 * 34, 15 * 34, 32, 32));
        _matTextures[4].loadFromFile("assets/items.png", sf::IntRect(4 * 34, 15 * 34, 32, 32));
        _matTextures[5].loadFromFile("assets/items.png", sf::IntRect(5 * 34, 15 * 34, 32, 32));
        _matTextures[6].loadFromFile("assets/items.png", sf::IntRect(6 * 34, 15 * 34, 32, 32));

        _eggTexture.loadFromFile("assets/items.png", sf::IntRect(6 * 34, 26 * 34, 32, 32));

        _recShape.setFillColor(sf::Color::Green);
        _initialized = true;
        resize(0, 0);
    }
}

void zappy::GameScene::zoomViewAt(sf::Vector2i pixel, sf::RenderWindow &window, float zoom) {
    std::cout << "view zoom: " << zoom << std::endl;
    const sf::Vector2f beforeCoord{window.mapPixelToCoords(pixel)};
    sf::View view{window.getView()};
    view.zoom(zoom);
    window.setView(view);
    const sf::Vector2f afterCoord{window.mapPixelToCoords(pixel)};
    const sf::Vector2f offsetCoords{beforeCoord - afterCoord};
    view.move(offsetCoords);
    window.setView(view);
}


void zappy::GameScene::unloadRessources() {
    _initialized = 0;
}

void zappy::GameScene::update(sf::Event const &event) {
    switch (event.type) {
        case sf::Event::MouseMoved:
            if ((_lastX && _lastY) || (_lastDiffX || _lastDiffY)) {
                _lastDiffY = _lastY - event.mouseMove.y;
                _lastDiffX = _lastX - event.mouseMove.x;
                _cameraView.move(_lastDiffX, _lastDiffY);
                _targetCenter = _cameraView.getCenter();
            }
            _lastX = event.mouseMove.x;
            _lastY = event.mouseMove.y;
            break;
        case sf::Event::MouseButtonReleased:
            _lastDiffY = _lastDiffX = _lastX = _lastY = 0;
            break;
        case sf::Event::MouseWheelMoved:
            _zooming = true;

            if (event.mouseWheel.delta > 0)
                _targetZoom = 1.3f;
            else if (event.mouseWheel.delta)
                _targetZoom = 0.8f;

            _currentZoom = 1.0f;
            _previousZoom = _currentZoom;

            _currentCenter = _cameraView.getCenter();
            _targetCenter = _cameraView.getCenter();
            break;
    }

}

void zappy::GameScene::draw(const sf::Time &elapsedTime) {
    if (!_game->isMapped())
        return;

    _renderWindow->setView(_cameraView);

    if (_zooming) {
        _currentZoom = lerp(_lerpFactor, _currentZoom, _targetZoom);
        _cameraView.zoom(1.0f + (_currentZoom - _previousZoom));

        _currentCenter.x = lerp(_lerpFactor, _currentCenter.x, _targetCenter.x);
        _currentCenter.y = lerp(_lerpFactor, _currentCenter.y, _targetCenter.y);
        _cameraView.setCenter(_currentCenter);

        _previousZoom = _currentZoom;

        if (fabs(_targetZoom - _currentZoom) < 0.01f)
            _zooming = false;
    }

    auto &blocks = _game->getTiles();

    const int offsetTile = 0;
    const int offsetMat = 5;
    const int matByline = 4;

    for (auto block : blocks) {
        const sf::Vector2f pos(((block->getPosition().x) * _ratio.x + offsetTile * block->getPosition().x),
                               ((block->getPosition().y) * _ratio.y + offsetTile * block->getPosition().y));
        block->rectangleShape.setPosition(pos);
        block->rectangleShape.setSize(_ratio);

        if (block->isHilghlighted() && _game->isDebug())
            block->rectangleShape.setFillColor(sf::Color::Red);
        else
            block->rectangleShape.setFillColor(sf::Color::White);

        if (block->isBusy() && _game->isDebug())
            block->rectangleShape.setTexture(&_tileTextures[1]);
        else
            block->rectangleShape.setTexture(&_tileTextures[3]);
        _renderWindow->draw(block->rectangleShape);

        const float sizeSquare = _ratio.x / 6.f;
        const auto inventaire = block->getInventaire();
        for (int i = 0; i < 7; ++i) {
            if (inventaire->getMaterial((const Inventaire::TypeMaterial) i) == 0)
                continue;
            block->matShape[i].setPosition(pos.x + offsetMat + (i % matByline) * (sizeSquare + offsetMat),
                                           pos.y + sizeSquare + ((int) (i / matByline)) * (sizeSquare + offsetMat));
            block->matShape[i].setSize(sf::Vector2f(sizeSquare, sizeSquare));
            block->matShape[i].setTexture(&_matTextures[i]);
            _renderWindow->draw(block->matShape[i]);
        }
    }

    auto &players = _game->getPlayers();
    for (auto player : players) {
        const auto inventaire = player->getInventaire();
        const auto realPosition = player->getPosition();
        const sf::Vector2f pos(((realPosition.x) * _ratio.x + offsetTile * realPosition.x + _ratio.x / 2),
                               ((realPosition.y) * _ratio.y + offsetTile * realPosition.y + _ratio.y / 2));
        const float squareSize = _ratio.x / 2;
        if (player->isCollecting()) {
            // Player
            player->animatedSprite.play(_walkingAnimation[player->getOrientation() % 4]);
            player->animatedSprite.setPosition(pos);
            player->animatedSprite.setOrigin({squareSize / 2, squareSize / 2});
            player->animatedSprite.setSize({squareSize, squareSize});

            // Progress
            player->animatedLoading.play(_loadingAnimation);
            player->animatedLoading.setSize({squareSize / 4, squareSize / 4});
            player->animatedLoading.setPosition(pos);
            player->animatedLoading.setOrigin({squareSize / 2, 0});
            player->animatedLoading.update(elapsedTime);

            // Render
            _renderWindow->draw(player->animatedSprite);
            _renderWindow->draw(player->animatedLoading);
        }
        else {
            // Player
            player->animatedSprite.play(_walkingAnimation[player->getOrientation() % 4]);
            player->animatedSprite.setPosition(pos);
            player->animatedSprite.setOrigin({squareSize / 2, squareSize / 2});
            player->animatedSprite.setSize({squareSize, squareSize});
            player->animatedSprite.update(elapsedTime);

            // Render
            _renderWindow->draw(player->animatedSprite);
        }

    }

    auto &eggs = _game->getEggs();
    for (auto egg : eggs) {
        const auto realPosition = egg->getPosition();
        const sf::Vector2f pos(((realPosition.x) * _ratio.x + offsetTile * realPosition.x + _ratio.x / 2),
                               ((realPosition.y) * _ratio.y + offsetTile * realPosition.y + _ratio.y / 2));

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
    _ratio.x /= 2;
    _ratio.y = _renderWindow->getSize().y;
    _ratio.y /= 2;
    _recShape.setSize(_ratio);
    _cameraView.setSize(_renderWindow->getSize().x, _renderWindow->getSize().y);
    _cameraView.setCenter(_renderWindow->getSize().x, _renderWindow->getSize().y);
    _renderWindow->setView(_cameraView);

}

float zappy::GameScene::lerp(float value, float start, float end) {
    return start + (end - start) * value;
}
