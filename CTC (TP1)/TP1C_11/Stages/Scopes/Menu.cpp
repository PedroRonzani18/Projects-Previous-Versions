#include "../Header/Menu.h"
#include "../../GenaralFiles/Header/globalParameters.h"
#include "../../GenaralFiles/Header/drawings.h"

Menu::Menu() : Stage()
{
    getEntities().resize(0);

    Button startButton;
    startButton.setDisplayListModel(drawMenuButton);
    startButton.setFunctionality(1);
    startButton.setMidPoint(0, 30);
    this->addEntity(startButton);

    Button helpButton;
    helpButton.setDisplayListModel(drawMenuButton);
    helpButton.setFunctionality(2);
    helpButton.setMidPoint(0, -30);
    this->addEntity(helpButton);

    setAmmountOfButtons();

    Button emphasisButton;
    emphasisButton.setDisplayListModel(drawEmphassisMenuButton);
    helpButton.setFunctionality(1);
    emphasisButton.setMidPoint(startButton.getMidPoint().getX(), startButton.getMidPoint().getY());
    this->setFocusButton(emphasisButton);
}