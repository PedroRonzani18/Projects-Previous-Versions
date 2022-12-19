#ifndef _STAGEMANAGER_H
#define _STAGEMANAGER_H

#include "Stage.h"
#include "Menu.h"
#include "Ajuda.h"
#include "Level.h"
#include "../../GeneralFiles/Header/Wave.h"

#include "../../GeneralFiles/Header/colisionManager.h"
#include "../../GeneralFiles/Header/drawings.h"

class StageManager {

    private:
        Stage* currentStage;
        std::vector<Stage*> stagesList; // vector com os stages Ajuda, Menu e Levels

    public:
        StageManager();

        Stage* getCurrentStage(){return this->currentStage;}
        void setCurrentStage(Stage* currentStage){this->currentStage = currentStage;}

        void keyboardOfStage();
        void movements();
        void initializeStages();
        void callWave();

        void removeVerify();
        int gameOverVerify();
        void colision();
        void initializePlayer();
        void gameInit();
};

#endif