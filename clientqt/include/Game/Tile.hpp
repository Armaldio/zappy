//
//-----------------------------------------------------------------------------
//Filename:    Tile.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/20/17.
//-----------------------------------------------------------------------------
//

#ifndef CLIENTQT_MAPSQUARE_HPP
#define CLIENTQT_MAPSQUARE_HPP


#include <SFML/Graphics/RectangleShape.hpp>
#include "Inventaire.hpp"

namespace zappy {
    class Tile : public Inventaire {
    public:
        sf::RectangleShape rectangleShape;
        sf::RectangleShape matShape[10];

        Tile();

        Tile(unsigned int x, unsigned int y);

        virtual ~Tile();
    };
}


#endif //CLIENTQT_MAPSQUARE_HPP
