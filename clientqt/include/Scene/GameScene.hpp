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

#include "Scene.hpp"

namespace zappy {
    class GameScene : public Scene {
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
