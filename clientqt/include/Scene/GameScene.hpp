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
        sf::RectangleShape _recShape;
        sf::Vector2f _ratio;

    public:
        GameScene(sf::RenderWindow *renderWindow, const std::string &name);

        void loadRessources() override;

        void unloadRessources() override;

        void update() override;

        void draw() override;

        void resize() override;
    };
};

#endif //CLIENTQT_GAMESCENE_HPP
