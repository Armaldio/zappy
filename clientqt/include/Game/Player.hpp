//
//-----------------------------------------------------------------------------
//Filename:    Player.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/20/17.
//-----------------------------------------------------------------------------
//

#ifndef CLIENTQT_PLAYER_HPP
#define CLIENTQT_PLAYER_HPP


#include <Game/Inventaire.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

namespace zappy {
    class Player {
    public:
        sf::RectangleShape characterShape;
    protected:
        Inventaire *_inventaire;
    public:
        Player(const sf::Vector2f &position = {0, 0});

        virtual ~Player();

        Inventaire *getInventaire() const;
    };
}


#endif //CLIENTQT_PLAYER_HPP
