#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include "MovableEntity.h"

class Projectile: public MovableEntity{
    private:
        //undefined image
        double damage;
        double defaultFireRate;

        //owner == 1 ? owner = player : owner = enemy 
        int owner; // dono do tiro. usado na hora de analizar colisões

    public:
        Projectile(); // construtor default
        Projectile(const int& displayListModel, const OrderedPair& max, const OrderedPair& min, const double& resize, const OrderedPair& velocity, 
        const double& angle, const double& angularSpeed, const double& hp, const int& moveType, const int& angularMoveType, const double& damage, 
        const double& defaultFireRate, const int& owner);

        double getDamage();
        void setDamage(const double& damage);

        double getDefaultFireRate();
        void setDefaultFireRate(const double& defaultFireRate);

        int getOwner();
        void setOwner(const int& owner);
};

#endif