#include "../Header/Entity.h"
#include "../../GeneralFiles/Header/drawings.h"
#include <stdio.h>
#include <SOIL/SOIL.h>

Entity::Entity()
{
        this->hitbox.resize(4);
        this->alteredHitbox.resize(4);
}

void Entity::setHitbox(){
        this->hitbox[0].setX(this->max.getX());
        this->hitbox[0].setY(this->max.getY());
        this->hitbox[1].setX(this->min.getX());
        this->hitbox[1].setY(this->max.getY());
        this->hitbox[2].setX(this->min.getX()); 
        this->hitbox[2].setY(this->min.getY());
        this->hitbox[3].setX(this->max.getX());
        this->hitbox[3].setY(this->min.getY());
}


void Entity::setDisplayListModel(void model())
{
        this->displayListModel = glGenLists(1);
        glNewList(this->displayListModel, GL_COMPILE);

                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, this->textureModel);
                        model();
                glDisable(GL_TEXTURE_2D);

        glEndList();
}

void Entity::setTextureModel(const char* arquivo)
{
        this->textureModel = loadTexture(arquivo);
}