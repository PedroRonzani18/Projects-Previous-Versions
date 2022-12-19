#ifndef _ENEMY_H
#define _ENEMY_H

#include "MovableEntity.h"
#include "Ballistic.h"
#include "Projectile.h"
#include "../../GeneralFiles/Header/colisionManager.h"

class Enemy: public MovableEntity, public Ballistic{
    protected:
        double killValue; // valor em pontos de matar o inimigo
        int dropPercentage; //probbilidade do inimigo dropar um coletavel 
        GLboolean onscreenTestable;
        int typeMove;
        
        void move1();

    public:
        Enemy(){}

        Enemy(int type);

        int getTypeMove(){return this->typeMove;}
        void setTypeMove(const int& typeMove){this->typeMove = typeMove;}

        double getKillValue(){return this->killValue;}
        void setKillValue(const double& killValue){this->killValue = killValue;}

        int getDropPercentage(){return this->dropPercentage;}
        void setDropPercentage(const int& dropPercentage){this->dropPercentage = dropPercentage;}

        GLboolean getOnscreenTestable(){return this->onscreenTestable;}
        void setOnscreenTestable(const GLboolean& onscreenTestable){this->onscreenTestable = onscreenTestable;}

        void move() override;
        void scaleMove(const double& scale) override;
        std::vector<Projectile> fire() override;
};  

#endif