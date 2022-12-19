#ifndef _STAGEMANAGER_H
#define _STAGEMANAGER_H

#include "Stage.h"
#include "Menu.h"
#include "Ajuda.h"
#include "Level.h"

#include "../../GenaralFiles/Header/colisionManager.h"
#include "../../GenaralFiles/Header/drawings.h"

class StageManager {

    private:
        Stage* currentStage;
        std::vector<Stage*> stagesList; // vector com os stages Ajuda, Menu e Levels

    public:
        StageManager();

        Stage* getCurrentStage(){return this->currentStage;}
        void setCurrentStage(Stage* currentStage){this->currentStage = currentStage;}

        void stageKeyboard();
        void ajudaKeyboardManager();
        void levelKeyboardManager();

        void menuKeyboardManager();

        void initializeStages();

        int gameOverVerify();
        int colision();
        void initializePlayer();
        void gameInit();
};

#endif