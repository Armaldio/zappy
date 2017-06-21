//
//-----------------------------------------------------------------------------
//Filename:    GameScene.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/20/17.
//-----------------------------------------------------------------------------
//

#ifndef CLIENTQT_GAMESCENE_HPP
#define CLIENTQT_GAMESCENE_HPP

#include <Game/Map.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Scene.hpp"

namespace zappy {
    class GameScene : public Scene {
    private:
        Map *_map;
        sf::Texture _tileTextures[10];
        sf::Texture _matTextures[10];
        sf::RectangleShape _recShape;
        sf::Vector2f _ratio;

        sf::View _cameraView;
        sf::View _gameView;

        int _lastX;
        int _lastY;
        int _lastDiffX;
        int _lastDiffY;

        float _zoomAmount;
        float _currentZoom;

    public:
        GameScene(sf::RenderWindow *renderWindow, const std::string &name);

        void loadRessources() override;

        void unloadRessources() override;

        void update(sf::Event const &event) override;

        void draw() override;

        void resize(unsigned int width, unsigned int height) override;

        void zoomViewAt(sf::Vector2i pixel, sf::RenderWindow &window, float zoom);


    };
};

#endif //CLIENTQT_GAMESCENE_HPP
