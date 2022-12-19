#ifndef _ENEMY_H
#define _ENEMY_H

#include "MovableEntity.h"
#include "Ballistic.h"

class Enemy: public MovableEntity, public Ballistic{
    private:
        double killValue; // valor em pontos de matar o inimigo

    public:
        Enemy(); // construtor default
        Enemy(const int& displayListModel, const OrderedPair& max, const OrderedPair& min, const double& resize, const OrderedPair& velocity, 
        const double& angle, const double& angularSpeed, const double& hp, const int& moveType, const int& angularMoveType, 
        const double& alteredFireRate, const Projectile& currentProjectile, const int&  numberOfShots, const double& killValue);    

        double getKillValue();
        void setKillValue(const double& killValue);

        Projectile& fire();
};  

#endif