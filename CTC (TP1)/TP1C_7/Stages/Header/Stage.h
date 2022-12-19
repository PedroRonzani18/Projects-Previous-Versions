#ifndef _STAGE_H
#define _STAGE_H

#include "../../BaseClasses/Header/Entity.h"

#include <vector>

class Stage 
{
    private:
        int focus;
        int ammountOfButtons;
        int background;
        std::vector<Entity> entities;

    public:

        Stage();

        Stage(const int& background);

        virtual void stageKeyboard(){}

        int getFocus(){return focus;}
        void setFocus(int focus){this->focus = focus;}

        int getAmmountOfButtons(){return ammountOfButtons;}
        void setAmmountOfButtons(const int& ammountOfButtons){this->ammountOfButtons = ammountOfButtons;}

        int getBackgound(){return background;}
        void setBackground(const int& background){this->background = background;}

        std::vector<Entity>& getEntities(){return entities;}
        virtual void addEntity(const Entity& e){this->entities.push_back(e);}
        Entity& getEntity(const int& pos){return entities[pos];}
};

#endif