#include "../Header/Stage.h"
#include <stdio.h>
#include "../Header/Menu.h"

Stage::Stage(){}

void Stage::setAmmountOfButtons(){
    this->ammountOfButtons = this->getButtons().size();
}

