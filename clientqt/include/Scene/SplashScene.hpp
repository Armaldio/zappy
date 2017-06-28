//
//-----------------------------------------------------------------------------
//Filename:    SplashScene.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/20/17.
//-----------------------------------------------------------------------------
//

#ifndef CLIENTQT_SPLASHSCENE_HPP
#define CLIENTQT_SPLASHSCENE_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <Scene/Scene.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

namespace zappy {
    class SplashScene : public Scene {
    private:
        sf::CircleShape _circleShape;
        sf::Font _font;
        sf::Text _title;
        sf::Uint16 _fadeColor;

    public:
        SplashScene(sf::RenderWindow *renderWindow, const std::string &stateName);

        ~SplashScene() override;

        void resize(unsigned int width, unsigned int height) override;

        void loadRessources() override;

        void unloadRessources() override;

        void update(sf::Event const &event) override;

        void draw(const sf::Time &elapsedTime) override;

    };
}


#endif //CLIENTQT_SPLASHSCENE_HPP
