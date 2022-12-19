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
    Stage currentStage;
    int state; //Variável de verificação de estado atual 
               //0 = menu
               //1 = ajuda
               //2 = level 1

public:
    StageManager();

    Stage& getCurrentStage();
    void setCurrentStage(Stage& currentStage);
    
    int getState();
    void setState(int state);

    int gameOverVerify();
    int colision();
    void initializePlayer();
    void gameInit();
};

#endif