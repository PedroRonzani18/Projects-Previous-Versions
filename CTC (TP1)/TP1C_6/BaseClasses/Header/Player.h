#ifndef _PLAYER_H
#define _PLAYER_H

#include "MovableEntity.h"
#include "Ballistic.h"

class Player: public MovableEntity, public Ballistic
{
    private:
        GLboolean shield; // permite que player colida com 1 shot e não perca vida

    public:
        Player();
        Player(const int& displayListModel, const OrderedPair& max, const OrderedPair& min, const double& resize, const OrderedPair& velocity, 
        const double& angle, const double& angularSpeed, const double& hp, const int& moveType, const int& angularMoveType, 
        const double& alteredFireRate, const Projectile& currentProjectile, const int& numberOfShots, const GLboolean& shield);       

        GLboolean getShield(){return shield;}
        void setShield(const GLboolean& shied){this->shield = shield;}

        Projectile& fire() override;
};

#endif