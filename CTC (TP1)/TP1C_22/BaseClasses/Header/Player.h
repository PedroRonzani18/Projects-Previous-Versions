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

        GLboolean getShield(){return shield;}
        void setShield(const GLboolean& shied){this->shield = shield;}

        void move() override; // movimentação padrão da entidade
        void scaleMove(const double& scale) override;
};

#endif