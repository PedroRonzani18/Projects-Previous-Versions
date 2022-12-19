#ifndef _MENU_H
#define _MENU_H

#include "Stage.h"
#include "../../GeneralFiles/Header/globalParameters.h"
#include "../../BaseClasses/Header/Button.h"

class Menu: public Stage {

    private:
        void drawButtons();

    public:
        Menu();
        
        void movements() override;
        int stageKeyboard() override;
        void drawEntities() override;
        void colider()override{}
};

#endif