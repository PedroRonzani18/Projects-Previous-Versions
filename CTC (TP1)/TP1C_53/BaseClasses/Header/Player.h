#ifndef _PLAYER_H
#define _PLAYER_H

#include "MovableEntity.h"
#include "Ballistic.h"

class Player: public MovableEntity, public Ballistic
{
    private:
        int imortality; // permite que player colida com 1 shot e não perca vida
        double alteredFireRate; // fire rate alterado por coletável
                                // tempo entre cada tiro
        
    public:
        Player();

        int getImortality(){return imortality;}
        void setImortality(const int& imortality){this->imortality = imortality;}

        void move() override; // movimentação padrão da entidade
        void scaleMove(const double& scale) override;

        std::vector<Projectile> fire() override;
        Projectile createProject(Projectile* auxP, double angle);
        //Projectile createProject(double xPlus, double yPlus, int xVel, int yVel, Projectile* auxP);


        double getAlteredFireRate(){return alteredFireRate;}
        void setAlteredFireRate(const double& alteredFireRate){this->alteredFireRate = alteredFireRate;}

        void upgradeManager(int upgradeType);
};

#endif