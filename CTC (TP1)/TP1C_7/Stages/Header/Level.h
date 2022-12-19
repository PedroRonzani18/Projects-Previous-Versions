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
        //Level();
        //Level(const int& background);
        
        double getScore(){return this->score;}
        void setScore(double score){this->score = score;}

        void backgroundMove();
        void entityInstance();
        GLboolean addEntity(Entity* e);
        void stageKeyboard();
        void pressedButton();
};


#endif