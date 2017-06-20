//
//-----------------------------------------------------------------------------
//Filename:    Inventaire.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/20/17.
//-----------------------------------------------------------------------------
//

#ifndef CLIENTQT_BOX_HPP
#define CLIENTQT_BOX_HPP


#include <SFML/System/Vector2.hpp>

class Inventaire {
protected:
    sf::Vector2i _pos;
    int _nourriture;
    int _linemate;
    int _deraumere;
    int _sibur;
    int _mendiane;
    int _phiras;
    int _thystame;

public:
    Inventaire();

    virtual ~Inventaire();

    const sf::Vector2i &getPos() const;

    void setPos(const sf::Vector2i &_pos);

    int getNourriture() const;

    void setNourriture(int _nourriture);

    int getLinemate() const;

    void setLinemate(int _linemate);

    int getDeraumere() const;

    void setDeraumere(int _deraumere);

    int getSibur() const;

    void setSibur(int _sibur);

    int getMendiane() const;

    void setMendiane(int _mendiane);

    int getPhiras() const;

    void setPhiras(int _phiras);

    int getThystame() const;

    void setThystame(int _thystame);
};


#endif //CLIENTQT_BOX_HPP
