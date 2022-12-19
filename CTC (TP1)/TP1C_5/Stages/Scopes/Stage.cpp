#include "../Header/Stage.h"

Stage::Stage()
{}

Stage::Stage(int cdStage, int background)
{
    this->cdStage = cdStage;
    this->background = background;
}

void Stage::stageKeybord()
{
    
}

int Stage::getCdStage()
{
    return this->cdStage;
}
void Stage::setCdStage(int cdStage)
{
    this-> cdStage = cdStage;

}

int Stage::getBackgound()
{
    return this->background;
}
void Stage::setBackground(int background)
{
    this->background = background;
}

std::vector<Entity>* Stage::getEntities()
{
    return &this->entities;
}

Entity* Stage::getEntity(int pos){
    return &entities[pos];
}

void Stage::addEntity(Entity* e)
{
    this->entities.push_back(*e);
}