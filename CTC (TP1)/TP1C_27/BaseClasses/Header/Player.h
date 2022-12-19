#ifndef _PLAYER_H
#define _PLAYER_H

#include "MovableEntity.h"
#include "Ballistic.h"

class Player: public MovableEntity, public Ballistic
{
    private:
        GLboolean imortality; // permite que player colida com 1 shot e não perca vida
        double alteredFireRate; // fire rate alterado por coletável
        
    public:
        Player();

        GLboolean getShield(){return imortality;}
        void setImortality(const GLboolean& shied){this->imortality = imortality;}

        void move() override; // movimentação padrão da entidade
        void scaleMove(const double& scale) override;

        std::vector<Projectile> fire() override;

        double getAlteredFireRate(){return alteredFireRate;}
        void setAlteredFireRate(const double& alteredFireRate){this->alteredFireRate = alteredFireRate;}

        void upgradeManager(int upgradeType);
};

#endif