#include "../Header/Menu.h"
#include "../../GenaralFiles/Header/globalParameters.h"

Menu::Menu() : Stage()
{
    Button startButton;
    startButton.setDisplayListModel(buttonDisplayList);
    startButton.setFunctionality(1);
    startButton.setMidPoint(0, 30);

    Button helpButton;
    startButton.setDisplayListModel(buttonDisplayList);
    helpButton.setFunctionality(2);
    helpButton.setMidPoint(0, -30);

    this->addEntity(startButton);
    this->addEntity(helpButton);
}

Menu::Menu(const int& backgraund) : Stage(backgraund)
{
}