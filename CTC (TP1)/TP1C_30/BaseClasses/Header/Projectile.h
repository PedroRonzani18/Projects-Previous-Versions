#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include "MovableEntity.h"
#include "../../GeneralFiles/Header/drawings.h"

class Projectile: public MovableEntity{
    private:
        //undefined image
        double damage;
        double defaultFireRate;

        //owner == 1 ? owner = player : owner = enemy 
        int owner; // dono do tiro. usado na hora de analizar colisões

    public:
        Projectile();

        double getDamage(){return damage;}
        void setDamage(const double& damage){this->damage = damage;}

        double getDefaultFireRate(){return defaultFireRate;}
        void setDefaultFireRate(const double& defaultFireRate){this->defaultFireRate = defaultFireRate;}

        int getOwner(){return owner;}
        void setOwner(const int& owner){this->owner = owner;}

        void move() override;
        void straightMove(); // projecile anda para frente
        void scaleMove(const double& scale) override;
};

#endif