#ifndef _LEVEL_H
#define _LEVEL_H

#include "../../BaseClasses/Header/Player.h"
#include "../../BaseClasses/Header/Enemy.h"
#include "../../BaseClasses/Header/Colectible.h"
#include "../../BaseClasses/Header/Boss.h"
#include "../../GeneralFiles/Header/drawings.h"
#include "../../GeneralFiles/Header/colisionManager.h"
#include "../../GeneralFiles/Header/globalParameters.h"
#include "../../GeneralFiles/Header/Wave.h"

#include "Stage.h"
#include <stdbool.h>

class Level: public Stage
{
    private:
        double score;

    public:
        Level();
        
        double getScore(){return this->score;}
        void setScore(double score){this->score = score;}

        void movements() override;
        int stageKeyboard() override;
        void drawEntities() override;
        void backgroundMove();

        void colider() override;
        void callWaves() override;
};


#endif