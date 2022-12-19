#ifndef _COLECTIBLE_H
#define _COLECTIBLE_H

#include "MovableEntity.h"

class Colectible: public MovableEntity{
    private:
        int type;

    public:
        Colectible() = default;

        int getType();
        void setType(int type);

        void upgradeManager(Colectible c);
};

#endif
