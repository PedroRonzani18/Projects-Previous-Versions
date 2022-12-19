#include "../Header/Menu.h"
#include "../../GeneralFiles/Header/globalParameters.h"
#include "../../GeneralFiles/Header/drawings.h"
#include <stdio.h>

Menu::Menu()
{
    getButtons().resize(0);

    Button startButton;
    startButton.setDisplayListModel(drawMenuButton);
    startButton.setCurrentPosition(1);
    startButton.setMidPoint(0, 30);
    this->addButton(startButton);

    Button helpButton;
    helpButton.setDisplayListModel(drawMenuButton);
    helpButton.setCurrentPosition(2);
    helpButton.setMidPoint(0, -30);
    this->addButton(helpButton);

    setAmmountOfButtons();

    Button emphasisButton;
    emphasisButton.setDisplayListModel(drawEmphassisMenuButton);
    emphasisButton.setCurrentPosition(1);
    emphasisButton.setMidPoint(startButton.getMidPoint().getX(), startButton.getMidPoint().getY());
    this->setFocusButton(emphasisButton);
}

int Menu::stageKeyboard()
{
    int auxFocus = this->getFocusButton().getCurrentPosition();

    if (flag)
    {
        if (keys[0])
        {
            flag = 0;
            printf("cima dentro do menu\n");
            if (auxFocus > 1)
                this->getFocusButton().setCurrentPosition(auxFocus - 1);
            else
                this->getFocusButton().setCurrentPosition(this->getAmmountOfButtons());

            // printf("AuxFocus: %d\n", this->getCurrentStage().getFocusButton().getCurrentPosition());
            for (Button b : this->getButtons())
            {
                printf("Func: %d\n", b.getCurrentPosition());
                if (b.getCurrentPosition() == this->getFocusButton().getCurrentPosition())
                {
                    printf("ENTROU 1\n");
                    getFocusButton().setMidPoint(b.getMidPoint().getX(),b.getMidPoint().getY());
                }
            }
        }

        if (keys[1])
        {
            flag = 0;
            printf("baixo dentro do menu\n");
            if (auxFocus < this->getAmmountOfButtons())
            {
                this->getFocusButton().setCurrentPosition(auxFocus + 1);
            }
            else
                this->getFocusButton().setCurrentPosition(1);

            // printf("AuxFocus: %d\nb", this->getCurrentStage().getFocusButton().getCurrentPosition());
            for (Button b : this->getButtons())
            {
                printf("Func: %d\n", b.getCurrentPosition());
                if (b.getCurrentPosition() == this->getFocusButton().getCurrentPosition())
                {
                    printf("ENTROU 2\n");
                    getFocusButton().setMidPoint(b.getMidPoint().getX(),b.getMidPoint().getY());
                }
            }
        }

        if (keys[4])
        {
            printf("space dentro do menu\n");
            flag = 0;

            switch (this->getFocusButton().getCurrentPosition())
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