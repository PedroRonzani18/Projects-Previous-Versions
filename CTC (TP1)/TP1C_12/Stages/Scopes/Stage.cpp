#include "../Header/Stage.h"

Stage::Stage()
{
}

void Stage::setAmmountOfButtons(){
    this->ammountOfButtons = this->getEntities().size();
}