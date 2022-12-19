#ifndef _MENU_H
#define _MENU_H

#include "Stage.h"
#include "../../GeneralFiles/Header/globalParameters.h"
#include "../../BaseClasses/Header/Button.h"

class Menu: public Stage {

    public:
        Menu();

        int stageKeyboard() override;
};



#endif