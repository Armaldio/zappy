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


        if (!_font.loadFromFile("arial.ttf"))
        {
            // error...
        }
        _title.setFont(_font);
        _title.setCharacterSize(120);
        _title.setStyle(sf::Text::Regular);
        _title.setFillColor(sf::Color(0, 255, 255));
        _title.setString("Zappy");
        _initialized = true;
        resize();
    }
}

void zappy::SplashScene::unloadRessources() {
    _initialized = false;
}

void zappy::SplashScene::update() {
    static int b = 0;

    b = (b + 255 / 60) % 255;
    _circleShape.setFillColor(sf::Color(0, b, 0));
}

void zappy::SplashScene::draw() {
    _renderWindow->draw(_circleShape);
    _renderWindow->draw(_title);
}

void zappy::SplashScene::resize() {
    _title.setPosition(_renderWindow->getSize().x / 2,
                       _renderWindow->getSize().y / 2);
}
