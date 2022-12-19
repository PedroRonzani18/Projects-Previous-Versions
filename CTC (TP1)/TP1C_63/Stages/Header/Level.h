#ifndef _LEVEL_H
#define _LEVEL_H

#include "../../BaseClasses/Header/Player.h"
#include "../../BaseClasses/Header/Enemy.h"
#include "../../BaseClasses/Header/Colectible.h"
#include "../../BaseClasses/Header/Boss.h"
#include "../../BaseClasses/Header/Score.h"
#include "../../GeneralFiles/Header/drawings.h"
#include "../../GeneralFiles/Header/colisionManager.h"
#include "../../GeneralFiles/Header/globalParameters.h"
#include "../../GeneralFiles/Header/Wave.h"

#include "Stage.h"
#include <stdbool.h>
#include <tuple>

class Level: public Stage
{
    private:
        void remover();

        Enemy* smallestDistanceEnemyPlayer(MovableEntity* m1);
                
    public:
        Level(){}

        Level(const int& l);

        void drawAndMove() override;
        int stageKeyboard() override;
        void drawScore();

        void verifyDeath();
        void timeCounter() override;

        
        void colider() override;
        void callWaves() override;
        void initBackgrounds() override {}
        void initBackgrounds(const int& typeBackground) override;

};


#endif