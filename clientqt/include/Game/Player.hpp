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
#include <include/Game/Animation.hpp>
#include <queue>
#include "Inventaire.hpp"
#include "Team.hpp"

namespace zappy {
    class Player {
    private:
        Team *_team;
        unsigned int _id;
        int _level;
        int _orientation;
        Inventaire *_inventaire;
        sf::Vector2f _pos;
        bool _isCollecting;
        bool _isIncantation;
        bool _isLaying;

    public:
        // gui
        sf::RectangleShape characterShape;
        sf::RectangleShape textBackgroundShape;
        AnimatedSprite animatedSprite;
        AnimatedSprite animatedLoading;
        std::vector<AnimatedText *> animatedTexts;

    public:
        Player(unsigned int id, int level, int orientation, unsigned int x, unsigned int y);

        virtual ~Player();

        Inventaire *getInventaire();

        const sf::Vector2f & getPosition() const;

        void setPosition(sf::Vector2f const& pos);

        int getOrientation() const;

        void setOrientation(int _orientation);

        int getLevel() const;

        void setLevel(int _level);

        void setCollecting(bool value);

        bool isCollecting() const;

        void setIncantation(bool value);

        bool isIncantation() const;

        void setLaying(bool value);

        bool isLaying() const;

        unsigned int getId() const;

        void setId(unsigned int _id);

        Team *getTeam() const;

        void setTeam(Team *team);

        void addMessage(const sf::String &message);
    };
}

#endif //CLIENTQT_PLAYER_HPP
