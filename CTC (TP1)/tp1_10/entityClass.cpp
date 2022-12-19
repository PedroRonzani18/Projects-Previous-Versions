#include "entityClass.h"
#include <stdio.h>

double Entity::Entity::getX_Max(){return this->x_max;}
void Entity::Entity::setX_Max(double x_max){this->x_max = x_max;}

double Entity::getX_Min(){return this->x_min;}
void Entity::setX_Min(double x_min){this->x_min = x_min;}

double Entity::getY_Max(){return this->y_max;}
void Entity::setY_Max(double y_max){this->x_max = x_max;}

double Entity::getY_Min(){return this->y_min;}
void Entity::setY_Min(double y_min){this->y_min = y_min;}

double Entity::getX_Move(){return this->x_move;}
void Entity::setX_Move(double x_move){this->x_move = x_move;}

double Entity::getY_Move(){return this->y_move;}
void Entity::setY_Move(double y_move){this->y_move = y_move;}

int Entity::getLadoHorizontal(){return this->ladoHorizontal;}
void Entity::setLadoHorizontal(int ladoHorizontal){this->ladoHorizontal = ladoHorizontal;}

int Entity::getLadoVertical(){return this->ladoVertical;}
void Entity::setLadoVertical(int ladoVertical){this->ladoVertical = ladoVertical;}

double Entity::getCentroX(){return this->centro.x;}
void Entity::setCentroX(double centroX){this->centro.x = centroX;}

double Entity::getCentroY(){return this->centro.y;}
void Entity::setCentroY(double centroY){this->centro.y = centroY;}

vertice* Entity::getHitbox(){return this->hitbox;}
void Entity::setHitbox(vertice hitbox[])
{
    for(int i=0; i< 4; i++)
        this->hitbox[i] = hitbox[i];
}

vertice* Entity::getAlteredHitbox(){return this->alteredHitbox;}
void Entity::setAlteredHitbox(vertice* aleredHitbox)
{
    for(int i=0; i< 4; i++)
        this->alteredHitbox[i] = alteredHitbox[i];
    }

double Entity::getResizeX(){return this->resize.x;}
void Entity::setResizeX(double resize){this->resize.x = resize;}

double Entity::getResizeY(){return this->resize.y;}
void Entity::setResizeY(double resize){this->resize.y = resize;}

double Entity::getAngularSpeed(){return this->angularSpeed;}
void Entity::setAngularSpeed(double angularSpeed){this->angularSpeed = angularSpeed;}

double Entity::getVetorialSpeed(){return this->vetorialSpeed;}
void Entity::setVetorialSpeed(double vetorialSpeed){this->vetorialSpeed = vetorialSpeed;}

double Entity::getAngulo(){return this->angulo;}
void Entity::setAngulo(double angulo){this->angulo = angulo;}

GLboolean Entity::getOnScreen(){return this->onScreen;}
void Entity::setOnScreen(GLboolean getOnScreen){this->onScreen = onScreen;}

GLuint Entity::getModel(){return this->model;}
void Entity::setModel(GLuint model){this->model = model;}

double Entity::getBulletSpeed(){return this->bulletSpeed;}
void Entity::setBulletSpeed(double bulletSpeed){this->bulletSpeed = bulletSpeed;}

int Entity::getContinuar(){return this->continuar;}
void Entity::setContinuar(int continuar){this->continuar = continuar;}

GLboolean Entity::getDrawHitbox(){return this->drawHitbox;}
void Entity::setDrawHitbox(GLboolean drawHitbox){this->drawHitbox = drawHitbox;}