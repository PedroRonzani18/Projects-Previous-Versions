#ifndef _COLECTIBLE_H
#define _COLECTIBLE_H

#include "MovableEntity.h"

class Colectible: public MovableEntity{
    private:
        int type;

    public:
        Colectible();

        int getType(){return this->type;}
        void setType(const int& type){this->type = type;}

        void move() override;
        void angularMove() override;
        void scaleMove(const double& scale) override;
};

#endif
