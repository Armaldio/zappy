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

#include <SFML/Graphics/RectangleShape.hpp>
#include <include/Game/Game.hpp>
#include <include/Game/Animation.hpp>
#include "Scene.hpp"

namespace zappy {
    class GameScene : public Scene {

    private:
        zappy::Game *_game;
        sf::Texture _tileTextures[10];
        sf::Texture _matTextures[10];
        sf::Texture _characterTexture;
        sf::Texture _loadingTexture;
        sf::Texture _eggTexture;
        sf::RectangleShape _recShape;
        sf::Vector2f _ratio;
        sf::Font _font;

        sf::View _cameraView;
        sf::View _gameView;

        zappy::Animation _walkingAnimation[16];
        zappy::Animation _loadingAnimation;

        int _lastX;
        int _lastY;
        int _lastDiffX;
        int _lastDiffY;

        sf::Vector2f _sizePixelsMap;

        sf::Vector2f _currentCenter;
        sf::Vector2f _targetCenter;
        float _targetZoom;
        float _currentZoom;
        float _previousZoom;
        bool _zooming;
        bool _autoCenter;

        float _lerpFactor;


    public:
        GameScene(sf::RenderWindow *renderWindow, const std::string &name);

        void loadRessources() override;

        void unloadRessources() override;

        void update(sf::Event const &event) override;

        void draw(const sf::Time &elapsedTime) override;

        void resize(unsigned int width, unsigned int height) override;

        void zoomViewAt(sf::Vector2i pixel, sf::RenderWindow &window, float zoom);

        float lerp(float value, float start, float end);

        void setAutoCenter(bool value);
    };
};

#endif //CLIENTQT_GAMESCENE_HPP
