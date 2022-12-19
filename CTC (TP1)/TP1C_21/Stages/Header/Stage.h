#ifndef _STAGE_H
#define _STAGE_H

#include "../../BaseClasses/Header/Entity.h"
#include "../../BaseClasses/Header/Button.h"
#include "../../BaseClasses/Header/MovableEntity.h"

#include <vector>

class Stage 
{
    private:
        int ammountOfButtons;
        int background;
        std::vector<Button> buttons;
        Button focusButton;

    public:
        Stage();

        virtual int stageKeyboard() = 0;

        void drawButtons();

        int getAmmountOfButtons(){return ammountOfButtons;}
        void setAmmountOfButtons();

        int getBackgound(){return background;}
        void setBackground(const int& background){this->background = background;}

        std::vector<Button> getButtons(){return buttons;}
        virtual void addButton(const Button& b){this->buttons.push_back(b);}
        Entity getButton(const int& pos){return buttons[pos];}

        Button& getFocusButton(){return this->focusButton;}
        void setFocusButton(const Button& focusButton){this->focusButton = focusButton;}
};

#endif