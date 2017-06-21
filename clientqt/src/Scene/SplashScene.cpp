//
//-----------------------------------------------------------------------------
//Filename:    SplashScene.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/20/17.
//-----------------------------------------------------------------------------
//

#include "include/Scene/SplashScene.hpp"

zappy::SplashScene::SplashScene(sf::RenderWindow *renderWindow, const std::string &stateName)
        : Scene(renderWindow, stateName) {

}

zappy::SplashScene::~SplashScene() {

}

void zappy::SplashScene::loadRessources() {
    if (!_initialized) {
        _circleShape.setRadius(10);
        _circleShape.setPosition(10, 10);


        if (!_font.loadFromFile("assets/arial.ttf"))
        {
            // error...
        }
        _title.setFont(_font);
        _title.setCharacterSize(120);
        _title.setStyle(sf::Text::Regular);
        _title.setFillColor(sf::Color(255, 0, 10));
        _title.setString("Zappy");
        _initialized = true;
        resize(_renderWindow->getSize().x, _renderWindow->getSize().y);
    }
}

void zappy::SplashScene::unloadRessources() {
    _initialized = false;
}

void zappy::SplashScene::update(sf::Event const &event) {
    _fadeColor = (sf::Uint16) (_fadeColor + 10) % 5100;
    const sf::Uint16 color = (_fadeColor > 2550) ? 2550 - (_fadeColor % 2550) : _fadeColor;
    _circleShape.setFillColor(sf::Color((sf::Uint8) (color / 10), 0, 0));
    _title.setFillColor(sf::Color((sf::Uint8) (color / 10), 0, 0));
}

void zappy::SplashScene::draw() {
    _renderWindow->draw(_circleShape);
    _renderWindow->draw(_title);
}

void zappy::SplashScene::resize(unsigned int width, unsigned int height) {
    _renderWindow->setSize({width, height});

    const sf::FloatRect titleBound = _title.getLocalBounds();
    _title.setOrigin(titleBound.left + titleBound.width / 2.0f,
                     titleBound.top + titleBound.height / 2.0f);

    _title.setPosition(_renderWindow->getSize().x / 2,
                       _renderWindow->getSize().y / 2);
}
