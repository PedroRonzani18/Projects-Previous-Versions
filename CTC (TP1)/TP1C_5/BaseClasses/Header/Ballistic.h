#ifndef _BALLISTIC_H
#define _BALLISTIC_H
// classe -abstrata- que define entidades que atiram

#include "Projectile.h"

class Ballistic{
    private:
        double alteredFireRate; 
        Projectile currentProjectile; //modelo do tiro atual
        int numberOfShots;

    public:
        
        Ballistic();

        Ballistic(const double& alteredFireRate, const Projectile& currentProjectile, const int& numberOfShots);

        double getAlteredFireRate();
        void setAlteredFireRate(const double& alteredFireRate);

        Projectile& getCurrentProjectile();
        void setCurrentProjectile(const Projectile& currentProjectile);

        int getNumberOfShots();
        void setNumberOfShots(const int& numberOfShots);

        virtual Projectile& fire() = 0; // instancia um novo projectile que será futuramente adicionado na lista de entidades
                                        // para criar uma função realmente virtual tem que ser = 0;
                                        // classe mãe: apenas .h
                                        // classe filha: .h e .cpp
};


#endif