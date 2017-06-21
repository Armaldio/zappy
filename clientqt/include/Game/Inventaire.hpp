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
    static const int _nbMat = 7;
    sf::Vector2f _pos;
    int _returnAllmat[_nbMat];

public:
    enum MAT {
        NOURRITURE = 0,
        LINEMATE,
        DERAUMERE,
        SIBUR,
        MENDIANE,
        PHIRAS,
        THYSTAME
    };


    Inventaire(const sf::Vector2f & position = {0, 0});

    virtual ~Inventaire();

    const sf::Vector2f &getPos() const;

    void setPos(const sf::Vector2f &_pos);

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

    const int *getAllMat() const;

    int getNbMat() const;
};


#endif //CLIENTQT_BOX_HPP
