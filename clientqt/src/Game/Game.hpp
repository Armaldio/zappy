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
#include "Player.hpp"
#include "Tile.hpp"
#include "Singleton.hpp"
#include "Team.hpp"

namespace zappy {
    class Game : public zappy::Singleton<Game> {
    private:
        std::vector<Player *> _players;
        std::vector<Tile *> _tiles;
        QVector<Team> _teams;
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

        void addPlayer(Player *player);

        std::vector<Player *> &getPlayers();

        std::vector<Tile *> &getTiles();

        bool isMapped() const;

        bool isFail() const;

        const QVector<Team> &getTeams() const;
    };
}


#endif //CLIENTQT_GAME_HPP
