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
#include <tuple>

class Level: public Stage
{
    private:
        double score;
        //primeiro int e o tipo da colisao o segundo salva o endereco (&) das entidades envolvidas na colisao
        //se for 1: colisao dos tiros do player com o inimido
        //se for 2: colisao dos tiros dos inimigos com o player
        //se for 3: colisao dos inimigos com o player
        //se for 4: colidiu coletavel com player

        std::vector<std::tuple<int, void*, void*>> collisions;

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
        void collisionHandler() override;
};


#endif