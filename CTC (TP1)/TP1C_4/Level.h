#ifndef _LEVEL_H
#define _LEVEL_H

#include "Player.h"
#include <stdbool.h>

class Level
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