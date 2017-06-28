//
//-----------------------------------------------------------------------------
//Filename:    Game.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/23/17.
//-----------------------------------------------------------------------------
//

#ifndef CLIENTQT_GAME_HPP
#define CLIENTQT_GAME_HPP


#include <vector>
#include <map>
#include <functional>
#include <QtCore/QVector>
#include <QtCore/QMap>
#include "Player.hpp"
#include "Tile.hpp"
#include "Singleton.hpp"
#include "Team.hpp"
#include "Egg.hpp"

namespace zappy {
    class Game : public zappy::Singleton<Game> {
    private:
        QMap<unsigned int, Player *> _players;
        QMap<unsigned int, Egg *> _eggs;
        QMap<std::string , Team *> _teams;
        QVector<Team *> _vTeams;
        QVector<Player *> _vPlayers;
        QVector<Tile *> _vTiles;
        QVector<Egg *> _vEggs;

        std::map<std::string, std::function<void(const std::string &)>> _functions;
        unsigned int _width;
        unsigned int _heigth;
        unsigned int _serverTime;
        bool _isMapped;

    private:
        bool _isFail;

    public:
        Game();

        virtual ~Game();

        void function_welcome(const std::string &);

        void function_msz(const std::string &);

        void function_bct(const std::string &);

        void function_tna(const std::string &);

        void function_pnw(const std::string &);

        void function_ppo(const std::string &);

        void function_plv(const std::string &);

        void function_pin(const std::string &);

        void function_pex(const std::string &);

        void function_pbc(const std::string &);

        void function_pic(const std::string &);

        void function_pie(const std::string &);

        void function_pfk(const std::string &);

        void function_pdr(const std::string &);

        void function_pgt(const std::string &);

        void function_pdi(const std::string &);

        void function_enw(const std::string &);

        void function_eht(const std::string &);

        void function_ebo(const std::string &);

        void function_sgt(const std::string &);

        void function_seg(const std::string &);

        void function_smg(const std::string &);

        void function_suc(const std::string &);

        void function_sbp(const std::string &);

        bool fexecute(const std::string &);

        void createMap(unsigned int width, unsigned int height);

        void destroyMap();

        QVector<Player *> &getPlayers();

        QVector<Egg *> &getEggs();

        QVector<Tile *> &getTiles();

        QVector<Team *> &getTeams();

        bool isMapped() const;

        bool isFail() const;

    };
}


#endif //CLIENTQT_GAME_HPP
