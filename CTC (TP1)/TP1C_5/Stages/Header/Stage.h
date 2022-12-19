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
        Stage(int cdStage, int background);


        virtual void stageKeybord();
        
        int getCdStage();
        void setCdStage(int cdStage);

        int getBackgound();
        void setBackground(int background);

        std::vector<Entity>* getEntities();
        void addEntity(Entity* e);

        Entity* getEntity(int pos);
};

#endif