#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include "MovableEntity.h"

class Projectile: public MovableEntity{
    private:
        //undefined image
        double damage;
        double defaultFireRate;
        int owner; // dono do tiro. usado na hora de analizar colisões

    public:
        
        Projectile(double damage, double defaultFireRate, int owner);

        double getDamage();
        void setDamage(double damage);

        double getDefaultFireRate();
        void setDefaultFireRate(double defaultFireRate);

        int getOwner();
        void setOwner(int owner);
};

#endif