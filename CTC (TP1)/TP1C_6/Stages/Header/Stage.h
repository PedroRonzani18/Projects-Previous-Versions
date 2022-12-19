#ifndef _STAGE_H
#define _STAGE_H

#include "../../BaseClasses/Header/Entity.h"

#include <vector>

class Stage {
    private:
        int cdStage;
        int background;

        std::vector<Entity> entities;

    public:

        Stage();

        Stage(const int& cdStage, const int& background);

        virtual void stageKeybord(){}
        
        int getCdStage(){return this->cdStage;}
        void setCdStage(const int& cdStage){this->cdStage = cdStage;}

        int getBackgound(){return background;}
        void setBackground(const int& background){this->background = background;}

        std::vector<Entity>& getEntities(){return entities;}
        void addEntity(const Entity& e){this->entities.push_back(e);}
        Entity& getEntity(const int& pos){return entities[pos];}
};

#endif