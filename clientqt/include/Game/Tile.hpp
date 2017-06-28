//
//-----------------------------------------------------------------------------
//Filename:    Tile.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/23/17.
//-----------------------------------------------------------------------------
//

#ifndef CLIENTQT_TILE_HPP
#define CLIENTQT_TILE_HPP


#include <SFML/System.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Inventaire.hpp"

namespace zappy {
    class Tile {
    private:
        Inventaire *_inventaire;
        sf::Vector2f _pos;
        bool _isHighlighted;
        bool _isBusy;

    public:
        // gui
        sf::RectangleShape rectangleShape;
        sf::RectangleShape matShape[7];


    public:
        Tile(unsigned int x = 0, unsigned int y = 0);

        virtual ~Tile();

        Inventaire *getInventaire();

        const sf::Vector2f &getPosition() const;

        void setPosition(const sf::Vector2f &_pos);

        void setHightlight(bool value);

        void togleHighlight();

        bool isHilghlighted() const;


        bool isBusy() const;

        void setBusy(bool occuped);
    };
}


#endif //CLIENTQT_TILE_HPP
