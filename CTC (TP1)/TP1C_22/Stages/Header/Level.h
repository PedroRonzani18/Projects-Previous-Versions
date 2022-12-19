#ifndef _LEVEL_H
#define _LEVEL_H

#include "../../BaseClasses/Header/Player.h"
#include "../../BaseClasses/Header/Enemy.h"
#include "../../BaseClasses/Header/Colectible.h"
#include "../../BaseClasses/Header/Boss.h"
#include "../../GeneralFiles/Header/drawings.h"
#include "../../GeneralFiles/Header/colisionManager.h"

#include "Stage.h"
#include <stdbool.h>

class Level: public Stage
{
    private:
        double score;

        void drawPlayer();
        void drawBoss();
        void drawEnemies();
        void drawProjectiles();
        void drawColectibles();

    public:
        Level();
        
        double getScore(){return this->score;}
        void setScore(double score){this->score = score;}

        int stageKeyboard() override;
        void drawEntities() override;
        void backgroundMove();

        void colider() override;
};


#endif