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

namespace zappy {
    class Player {
    protected:
        Inventaire *_inventaire;
    public:
        Player();

        virtual ~Player();
    };
}


#endif //CLIENTQT_PLAYER_HPP
