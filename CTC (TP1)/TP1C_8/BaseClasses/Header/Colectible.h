#ifndef _COLECTIBLE_H
#define _COLECTIBLE_H

#include "MovableEntity.h"

class Colectible: public MovableEntity{
    private:
        int type;

    public:
        Colectible();
        Colectible(const int& displayListModel, const OrderedPair& max, const OrderedPair& min, const double& resize, const OrderedPair& velocity, 
        const double& angle, const double& angularSpeed, const double& hp, const int& moveType, const int& angularMoveType, 
        const int& type);

        int getType(){return this->type;}
        void setType(const int& type){this->type = type;}

        void upgradeManager(Colectible c);
};

#endif
