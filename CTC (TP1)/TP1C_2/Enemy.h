#ifndef _ENEMY_H
#define _ENEMY_H

#include "MovableEntity.h"
#include "Ballistic.h"

class Enemy: public MovableEntity, public Ballistic{
    private:
        double killValue; // valor em pontos de matar o inimigo

    public:
        Enemy() = default; // construtor default
        double getKillValue();
        void setKillValue(double killValue);

        Projectile* fire();
};  

#endif