//
//-----------------------------------------------------------------------------
//Filename:    MapSquare.hpp
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
    class MapSquare : public Inventaire {
    public:
        sf::RectangleShape rectangleShape;

        MapSquare();

        MapSquare(unsigned int x, unsigned int y);

        virtual ~MapSquare();
    };
}


#endif //CLIENTQT_MAPSQUARE_HPP
