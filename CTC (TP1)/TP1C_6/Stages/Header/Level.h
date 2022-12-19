#ifndef _LEVEL_H
#define _LEVEL_H

#include "../../BaseClasses/Header/Player.h"
#include "Stage.h"
#include <stdbool.h>

class Level: public Stage
{
    private:
        double score;
    public:
        Level();
        Level(Player player);
        
        double getScore();
        void setScore(double score);

        void backgroundMove();
        void entityInstance();
        GLboolean addEntity(Entity* e);
        void stageKeyboard();
        void pressedButton();
};


#endif