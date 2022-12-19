#ifndef _AJUDA_H
#define _AJUDA_H

#include "Stage.h"
#include "../../GeneralFiles/Header/globalParameters.h"


class Ajuda: public Stage
{
    public:
        Ajuda();
        
        void movements() override;
        int stageKeyboard() override;
        void drawEntities() override;
        void colider()override{}
        void callWaves() override {}
};

#endif