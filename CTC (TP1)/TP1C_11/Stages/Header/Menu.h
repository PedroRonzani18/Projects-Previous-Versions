#ifndef _MENU_H
#define _MENU_H

#include "Stage.h"
#include "../../GenaralFiles/Header/globalParameters.h"
#include "../../BaseClasses/Header/Button.h"

class Menu: public Stage {

    private:
        Button focusButton;

    public:
        Menu();

        Menu(const int& background);

        Button& getFocusButton(){return this->focusButton;}
        void setFocusButton(const Button& focusButton){this->focusButton = focusButton;}
};



#endif