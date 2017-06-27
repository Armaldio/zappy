//
//-----------------------------------------------------------------------------
//Filename:    Inventaire.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/23/17.
//-----------------------------------------------------------------------------
//

#ifndef CLIENTQT_ARESSOURCES_HPP
#define CLIENTQT_ARESSOURCES_HPP


namespace zappy {
    class Inventaire {
    protected:
        int _materials[7];

    public:
        enum TypeMaterial {
            Nourriture = 0,
            Linemate,
            Deraumere,
            Sibur,
            Mendiane,
            Phiras,
            Thystame
        };

        Inventaire();

        virtual ~Inventaire();

        Inventaire(const Inventaire & other);

        Inventaire &operator=(const Inventaire & other);

        int getMaterial(const TypeMaterial type);

        void setMaterial(const TypeMaterial type, const int value);

        int getNourriture(void) const;

        int getLinemate(void) const;

        int getDeraumere(void) const;

        int getSibur(void) const;

        int getMendiane(void) const;

        int getPhiras(void) const;

        int getThystame(void) const;

        void setNourriture(int value);

        void setLinemate(int value);

        void setDeraumere(int value);

        void setSibur(int value);

        void setMendiane(int value);

        void setPhiras(int value);

        void setThystame(int value);
    };
}


#endif //CLIENTQT_ARESSOURCES_HPP
