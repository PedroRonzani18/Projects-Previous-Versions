#include "../Header/Stage.h"
#include <stdio.h>

Stage::Stage()
{
}

void Stage::setAmmountOfButtons(){
    this->ammountOfButtons = this->getEntities().size();
}