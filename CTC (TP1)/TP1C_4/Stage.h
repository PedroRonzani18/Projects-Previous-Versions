#ifndef _STAGE_H
#define _STAGE_H

#include "Entity.h"

#include <vector>

class Stage {
    private:
        int cdStage;
        int background;

        std::vector<Entity> entities;
        //Inserir background aqui

    public:
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