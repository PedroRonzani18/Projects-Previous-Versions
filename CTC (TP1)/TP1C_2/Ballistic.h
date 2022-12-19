#ifndef _BALLISTIC_H
#define _BALLISTIC_H
// classe -abstrata- que define entidades que atiram

#include "Projectile.h"

class Ballistic{
    private:
        double alteredFireRate; 
        Projectile currentProjectile;

    public:
        virtual Projectile* fire(); // instancia um novo projectile que será futuramente adicionado na lista de entidades
                            
};


#endif