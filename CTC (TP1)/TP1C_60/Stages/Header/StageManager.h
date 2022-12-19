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
        Stage* menu;
        Stage* ajuda;
        Stage* level;
        int currentLevel;

    public:
        StageManager();

        Stage* getCurrentStage(){return this->currentStage;}
        void setCurrentStage(Stage* currentStage){this->currentStage = currentStage;}

        Stage* getMenu(){return this->menu;}
        void setmenu(Stage* menu){this->menu = menu;}

        Stage* getAjuda(){return this->ajuda;}
        void setAjuda(Stage* ajuda){this->ajuda = ajuda;}

        Stage* getLevel(){return this->level;}
        void setLevel(Stage* level){this->level = level;}

        int getCurrentLevel(){return this->currentLevel;}
        void setCurrentLevel(const int& currentLevel){this->currentLevel = currentLevel;}

        void keyboardOfStage();
        void movements();
        void timer();
        void initLevel();

        void callWave();
        int gameOverVerify();
        void colision();
        void gameInit();
};

#endif