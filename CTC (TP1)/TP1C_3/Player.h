#ifndef _PLAYER_H
#define _PLAYER_H

#include "MovableEntity.h"
#include "Ballistic.h"
#include "Projectile.h"

class Player: public MovableEntity, public Ballistic
{
    private:
        GLboolean shield; // permite que player colida com 1 shot e não perca vida

    public:
        Player();

        GLboolean getShield();
        void setShield(GLboolean shied);

        //Projectile* fire();
};

#endif