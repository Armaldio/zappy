//
//-----------------------------------------------------------------------------
//Filename:    Scene.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/20/17.
//-----------------------------------------------------------------------------
//

#ifndef CLIENTQT_SCENE_HPP
#define CLIENTQT_SCENE_HPP

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>

namespace zappy {
    class Scene {
    protected:
        sf::RenderWindow *_renderWindow;
        std::string _stateName;
        bool _initialized;
    public:
        Scene(sf::RenderWindow *renderWindow, const std::string &name);

        virtual ~Scene();

    public:

        virtual void loadRessources() = 0;

        virtual void unloadRessources() = 0;

        virtual void update() = 0;

        virtual void draw() = 0;

        virtual void resize() = 0;

        const std::string &getName() const;
    };
};

#endif //CLIENTQT_SCENE_HPP
