#include "../Header/Menu.h"
#include "../../GenaralFiles/Header/globalParameters.h"
#include "../../GenaralFiles/Header/drawings.h"

Menu::Menu() : Stage()
{
    Button startButton;
    startButton.setDisplayListModel(drawMenuButton);
    startButton.setFunctionality(1);
    startButton.setMidPoint(0, 30);

    Button helpButton;
    startButton.setDisplayListModel(drawMenuButton);
    helpButton.setFunctionality(2);
    helpButton.setMidPoint(0, -30);

    getEntities().resize(0);

    this->addEntity(startButton);
    this->addEntity(helpButton);
}

Menu::Menu(const int& backgraund) : Stage(backgraund)
{
}