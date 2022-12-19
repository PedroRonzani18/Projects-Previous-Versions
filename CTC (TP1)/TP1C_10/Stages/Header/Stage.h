#ifndef _STAGE_H
#define _STAGE_H

#include "../../BaseClasses/Header/Entity.h"
#include "../../BaseClasses/Header/Button.h"

#include <vector>

class Stage 
{
    private:
        int focus;
        int ammountOfButtons;
        int background;
        std::vector<Entity> entities;
        Button focusButton;
        

    public:

        Stage();

        virtual void stageKeyboard();

        int getFocus(){return focus;}
        void setFocus(int focus){this->focus = focus;}

        int getAmmountOfButtons(){return ammountOfButtons;}
        void setAmmountOfButtons();

        int getBackgound(){return background;}
        void setBackground(const int& background){this->background = background;}

        std::vector<Entity>& getEntities(){return entities;}
        virtual void addEntity(const Entity& e){this->entities.push_back(e);}
        Entity& getEntity(const int& pos){return entities[pos];}

        Button& getFocusButton(){return this->focusButton;}
        void setFocusButton(const Button& focusButton){this->focusButton = focusButton;}
};

#endif