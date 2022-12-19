#include "../Header/Menu.h"
#include "../../GeneralFiles/Header/globalParameters.h"
#include "../../GeneralFiles/Header/drawings.h"
#include <stdio.h>

Menu::Menu()
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
    emphasisButton.setFunctionality(1);
    emphasisButton.setMidPoint(startButton.getMidPoint().getX(), startButton.getMidPoint().getY());
    this->setFocusButton(emphasisButton);
}

int Menu::stageKeyboard()
{
    int auxFocus = this->getFocusButton().getFunctionality();
  
    if(flag)
    {
        if(keys[0])
        {
            flag=0;
            printf("cima dentro do menu\n");
            if(auxFocus > 1)
                this->getFocusButton().setFunctionality(auxFocus - 1);
            else
                this->getFocusButton().setFunctionality(this->getAmmountOfButtons());

            //printf("AuxFocus: %d\n", this->getCurrentStage().getFocusButton().getFunctionality());
        }

        if(keys[1])
        {
            flag=0;
            printf("baixo dentro do menu\n");
            if(auxFocus < this->getAmmountOfButtons())
                this->getFocusButton().setFunctionality(auxFocus + 1);
            else
                this->getFocusButton().setFunctionality(1);
                
            //printf("AuxFocus: %d\n", this->getCurrentStage().getFocusButton().getFunctionality());
        }



        if(keys[4])
        {
            printf("space dentro do menu\n");
            flag=0;
            
            switch(this->getFocusButton().getFunctionality())
            {
                case 1: // LEVEL
                    printf("Entrei no level\n");
                    return 2;
                    
                    break;
                
                case 2: // AJUDA
                    printf("Entrei na ajuda\n");
                    return 1;
                    break;
            }
        }
    }     
    return 0;
}