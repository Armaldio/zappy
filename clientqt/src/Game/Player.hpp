//
//-----------------------------------------------------------------------------
//Filename:    Player.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/23/17.
//-----------------------------------------------------------------------------
//

#ifndef CLIENTQT_PLAYER_HPP
#define CLIENTQT_PLAYER_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Inventaire.hpp"

namespace zappy {
    class Player {
    private:
        unsigned int _id;
        int _level;
        int _orientation;
        Inventaire *_inventaire;
        sf::Vector2f _pos;

    public:
        // gui
        sf::RectangleShape characterShape;

    public:
        Player(unsigned int id, int level, int orientation, unsigned int x, unsigned int y);

        virtual ~Player();

        Inventaire *getInventaire();

        const sf::Vector2f & getPosition() const;

        void setPosition(sf::Vector2f const& pos);

        const std::string &get_name() const;

        void set_name(const std::string &_name);

        int getOrientation() const;

        void setOrientation(int _orientation);

        int getLevel() const;

        void setLevel(int _level);
    };
}

#endif //CLIENTQT_PLAYER_HPP
