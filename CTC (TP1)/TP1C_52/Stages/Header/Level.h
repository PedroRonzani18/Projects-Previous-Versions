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
        //primeiro int e o tipo da colisao
        //se for 1: colisao dos tiros do player com o inimido
        //se for 2: colisao dos tiros dos inimigos com o player
        //se for 3: colisao dos inimigos com o player
        //se for 4: colidiu coletavel com player
        //segundo int e a posicao no vetor do inimigo que colidiu 
        //terceiro int e a posicao no vetor do projetil que colidiu 
        //quarto int e a posicao no vetor do coletavel que colidiu 

        void remover();

        Enemy* smallestDistanceEnemyPlayer(MovableEntity* m1);
                
    public:
        Level();
        
        double getScore(){return this->score;}
        void setScore(double score){this->score = score;}

        void drawAndMove() override;
        int stageKeyboard() override;
        void backgroundMove();

        void verifyDeath();
        void timeCounter() override;

        
        void colider() override;
        void callWaves() override;
        void initBackgrounds() override;

};


#endif