#include "../Header/Stage.h"
#include <stdio.h>
#include "../Header/Menu.h"

Stage::Stage(){}

void Stage::setAmmountOfButtons(){
    this->ammountOfButtons = this->getButtons().size();
}

void Stage::drawButtons()
{
    for(Button b : buttons)
    {
        glPushMatrix();
            glTranslatef(b.getMidPoint().getX(),
                         b.getMidPoint().getY(),
                         0);
            if(typeid(background) == typeid(MovableEntity))
                glRotatef(reinterpret_cast<MovableEntity*>(&b)->getAngle(), 0, 0 ,1);
            glCallList(b.getDisplayListModel());
        glPopMatrix();
    }

    glPushMatrix();
        glTranslatef(focusButton.getMidPoint().getX(),
                    focusButton.getMidPoint().getY(),
                    0);
        glCallList(focusButton.getDisplayListModel());
    glPopMatrix();
    
}