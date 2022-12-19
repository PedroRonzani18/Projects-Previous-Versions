#ifndef _BALLISTIC_H
#define _BALLISTIC_H

#include "Projectile.h"

class Ballistic{
    private:
        double alteredFireRate; 
        Projectile currentProjectile; //modelo do tiro atual
        int numberOfShots;

    public:
        
        Ballistic();

        Ballistic(const double& alteredFireRate, const Projectile& currentProjectile, const int& numberOfShots);

        double getAlteredFireRate(){return alteredFireRate;}
        void setAlteredFireRate(const double& alteredFireRate){this->alteredFireRate = alteredFireRate;}

        Projectile getCurrentProjectile(){return this->currentProjectile;}
        void setCurrentProjectile(const Projectile& currentProjectile){this->currentProjectile = currentProjectile;}

        int getNumberOfShots(){return this->numberOfShots;}
        void setNumberOfShots(const int& numberOfShots){this->numberOfShots = numberOfShots;}

        Projectile fire(){return this->getCurrentProjectile();}
};


#endif