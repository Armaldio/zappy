//
//-----------------------------------------------------------------------------
//Filename:    KeyConverter.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/19/17.
//-----------------------------------------------------------------------------
//

#ifndef CLIENTQT_KEYCONVERTER_HPP
#define CLIENTQT_KEYCONVERTER_HPP

#include <SFML/Window/Keyboard.hpp>
#include <QKeyEvent>

namespace qsf {
    /**
     * Convert QtKey to SFML Key Event
     * @param QtKey
     * @return sf::Kye
     */
    sf::Keyboard::Key QtKeyToSFML(int QtKey);
}


#endif //CLIENTQT_KEYCONVERTER_HPP
