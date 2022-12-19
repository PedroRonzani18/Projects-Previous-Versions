#include "../Header/Menu.h"
#include "../../GeneralFiles/Header/globalParameters.h"
#include "../../GeneralFiles/Header/drawings.h"
#include <stdio.h>
#include <typeinfo>

Menu::Menu()
{
    getButtons().resize(0);

    Button startButton;
    startButton.setDisplayListModel(textures[5]);
    startButton.setCurrentPosition(1);
    startButton.setMidPoint(0,-40);
    this->addButton(startButton);

    Button helpButton;
    helpButton.setDisplayListModel(textures[0]);
    helpButton.setCurrentPosition(2);
    helpButton.setMidPoint(0,-70);
    this->addButton(helpButton);

    setAmmountOfButtons();

    Button emphasisButton;
    emphasisButton.setDisplayListModel(textures[8]);
    emphasisButton.setCurrentPosition(1);
    emphasisButton.setMidPoint(startButton.getMidPoint().getX() -60, startButton.getMidPoint().getY());
    this->setFocusButton(emphasisButton);

    getBackgrounds().resize(0);

    Background b1;
    b1.setDisplayListModel(textures[30]);
    b1.setMidPoint(0,0);
    backgrounds.push_back(b1);

}

int Menu::stageKeyboard()
{
    int auxFocus = this->getFocusButton().getCurrentPosition();

    if (tempo%13 == 0) // >_<
    {
        if (keys[0])
        {
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
                    getFocusButton().setMidPoint(b.getMidPoint().getX()-60,b.getMidPoint().getY());
                }
            }
        }

        if (keys[1])
        {
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
                    getFocusButton().setMidPoint(b.getMidPoint().getX()-60,b.getMidPoint().getY());
                }
            }
        }

        if (keys[4])
        {
            printf("space dentro do menu\n");

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
    return -1;
}

void Menu::drawButtons()
{
    for(Button b : getButtons())
    {
        glPushMatrix();
            glTranslatef(b.getMidPoint().getX(),
                         b.getMidPoint().getY(),
                         0);
            glCallList(b.getDisplayListModel());
        glPopMatrix();
    }

    glPushMatrix();
        glTranslatef(getFocusButton().getMidPoint().getX(),
                    getFocusButton().getMidPoint().getY(),
                    0);
        glCallList(getFocusButton().getDisplayListModel());
    glPopMatrix();
    
}

void Menu::drawBackgroundMenu()
{
    for(Background b : getBackgrounds())
    {
        glPushMatrix();
            glTranslatef(b.getMidPoint().getX(),
                         b.getMidPoint().getY(),
                         0);
            glCallList(b.getDisplayListModel());
        glPopMatrix();
    }
    
}

void Menu::drawAndMove()
{
    drawBackgroundMenu();
    drawButtons();
}