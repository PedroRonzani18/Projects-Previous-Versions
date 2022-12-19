#include "../Header/Stage.h"
#include <stdio.h>

Stage::Stage(){}


void Stage::setAmmountOfButtons(){
    this->ammountOfButtons = this->getEntities().size();
}

void Stage::drawEntities(){
    for(Entity e : entities)
    {
        glPushMatrix();
            glTranslatef(e.getMidPoint().getX(),
                         e.getMidPoint().getY(),
                         0);
            if(typeid(e) == typeid(MovableEntity))
                glRotatef(reinterpret_cast<MovableEntity*>(&e)->getAngle(), 0, 0 ,1);
            glCallList(e.getDisplayListModel());
        glPopMatrix();
    }  
}