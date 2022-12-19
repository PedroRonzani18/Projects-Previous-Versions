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
        int fireRatePeriod;
        int typeTiroManager;
        
    public:
        Player();

        int getImortality(){return imortality;}
        void setImortality(const int& imortality){this->imortality = imortality;}

        void move() override; // movimentação padrão da entidade
        void scaleMove(const double& scale) override;

        std::vector<Projectile> fire() override;

        double getAlteredFireRate(){return alteredFireRate;}
        void setAlteredFireRate(const double& alteredFireRate){this->alteredFireRate = alteredFireRate;}

        int getFireRatePeriod(){return this->fireRatePeriod;}
        void setFireRatePeriod(const int& fireRatePeriod){this->fireRatePeriod = fireRatePeriod;}

        void upgradeManager(int upgradeType);
};

#endif