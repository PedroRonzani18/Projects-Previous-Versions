#ifndef _BALLISTIC_H
#define _BALLISTIC_H

#include "Projectile.h"

class Ballistic{
    protected:
        
        Projectile currentProjectile; //modelo do tiro atual
        int numberOfShots; // numero de tiros lançados por vez (1, 2, 3)

    public:
        
        Ballistic();

        Ballistic(const double& alteredFireRate, const Projectile& currentProjectile, const int& numberOfShots);

        Projectile getCurrentProjectile(){return this->currentProjectile;}
        void setCurrentProjectile(const Projectile& currentProjectile){this->currentProjectile = currentProjectile;}

        int getNumberOfShots(){return this->numberOfShots;}
        void setNumberOfShots(const int& numberOfShots){this->numberOfShots = numberOfShots;}

        virtual std::vector<Projectile> fire() = 0;
};


#endif