#ifndef _STAGEMANAGER_H
#define _STAGEMANAGER_H

#include "Stage.h"
#include "Menu.h"
#include "Ajuda.h"
#include "Level.h"
#include "colisionManager.h"

class StageManager {

private:
    Stage currentStage;
    int state; //Variável de verificação de estado atual 

public:
    StageManager()
    {
        this->state = 0;
    };

    int colision();
    int gameOverVerify();
    
    int getState();
    void setState(int state);

    void gameInit();
};

#endif