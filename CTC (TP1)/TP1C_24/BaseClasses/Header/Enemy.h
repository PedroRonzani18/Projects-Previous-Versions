#ifndef _ENEMY_H
#define _ENEMY_H

#include "MovableEntity.h"
#include "Ballistic.h"

class Enemy: public MovableEntity, public Ballistic{
    protected:
        double killValue; // valor em pontos de matar o inimigo

    public:
        Enemy();

        double getKillValue(){return this->killValue;}
        void setKillValue(const double& killValue){this->killValue = killValue;}

        void move() override;
        void scaleMove(const double& scale) override;
        std::vector<Projectile> fire() override;
};  

#endif