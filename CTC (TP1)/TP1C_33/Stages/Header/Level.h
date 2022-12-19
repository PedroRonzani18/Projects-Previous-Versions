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

        void drawAndMove() override;
        int stageKeyboard() override;
        void backgroundMove();

        void player_EnemyProjectileColision();
        void player_EnemyColision();
        void playerProjectile_EnemyColision();
        void player_ColectibleColision();
        void verifyEnemyDeath();


        void remover() override;
        void colider() override;
        void callWaves() override;
};


#endif