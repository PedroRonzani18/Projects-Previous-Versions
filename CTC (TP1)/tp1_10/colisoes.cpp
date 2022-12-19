#include "inicializa.h"
#include "colisoes.h"

using namespace std;

void shotHitbox(int e)
{
    printf("Conteudo shotHitbox: %d\n",shotsList[0].model);

    if(!shotsList[e].getOnScreen()) // coloca a hitbox na posição inicial
    {
        vertice* auxHitbox;

        for(int i=0; i<4; i++)
        {   
            auxHitbox[i].x = shotsList[e].getHitbox()[i].x + shotsList[e].getCentroX();
            auxHitbox[i].y = shotsList[e].getHitbox()[i].y + shotsList[e].getCentroY();
/*
            shotsList[e].alteredHitbox[i].x = shotsList[e].hitbox[i].x + shotsList[e].centro.x;
            shotsList[e].alteredHitbox[i].y = shotsList[e].hitbox[i].y + shotsList[e].centro.y;*/
        }

        shotsList[e].setAlteredHitbox(auxHitbox);
        free(auxHitbox);
    }
}

void removeHitbox(Entity* e)
{
    printf("Conteudo removeHitbox: %d\n",shotsList[0].model);

    vertice* auxHitbox;

    for(int i=0; i<4; i++)
    {
        auxHitbox[i].x = 0;
        auxHitbox[i].y = 0;
/*
        e->alteredHitbox[i].x = 0;
        e->alteredHitbox[i].y = 0;*/
    }

    e->setAlteredHitbox(auxHitbox);
    free(auxHitbox);
}

void confereEndGame()
{
    printf("Conteudo confereEndGame: %d\n",shotsList[0].model);

    if(endGame==1){
        endGame = 0;
        inicializaPosicoes();
        inicializaOnScreen();
    }

    if(endGame==2){
        endGame = 0;
        inicializaPosicoes();
        inicializaOnScreen();
    }
}

int voceVenceu()
{
    printf("Conteudo vocevenceu: %d\n",shotsList[0].model);

    for(int i=1; i < entityList.size(); i++)
    {
        if(entityList[i].getOnScreen()) // se houver algum inimigo vivo, o jogo continua
            return 0;
    }
    return 1; // se ninguem está na tela, retorna que acabou
}

int colisaoGeral(Entity* e1, Entity* e2)
{
    vertice iniDiag, fimDiag, iniLado, fimLado, deltaVet;
    double l=0, d1=0, d2=0;
    int overlap = 0;

    iniDiag.x = e1->getCentroX();
    iniDiag.y = e1->getCentroY();
    
    for(int i=0; i<4; i++)
    {
        deltaVet.x = 0;
        deltaVet.y = 0;

        fimDiag.x = e1->getAlteredHitbox()[i].x;
        fimDiag.y = e1->getAlteredHitbox()[i].y;
/*
        fimDiag.x = e1->alteredHitbox[i].x;
        fimDiag.y = e1->alteredHitbox[i].y;*/

        for(int j=0, s=1; j<4; j++, s=(j+1)%4) 
        {
            iniLado = e2->getAlteredHitbox()[j];
            fimLado = e2->getAlteredHitbox()[s];
/*
            iniLado = e2->alteredHitbox[j];
            fimLado = e2->alteredHitbox[s];*/

            l = (fimLado.x - iniLado.x) * (iniDiag.y - fimDiag.y) - (iniDiag.x - fimDiag.x) * (fimLado.y - iniLado.y);

            d1 = ((iniLado.y - fimLado.y) * (iniDiag.x - iniLado.x) + (fimLado.x - iniLado.x) * (iniDiag.y - iniLado.y)) / l;

            d2 = ((iniDiag.y - fimDiag.y) * (iniDiag.x - iniLado.x) + (fimDiag.x - iniDiag.x) * (iniDiag.y - iniLado.y)) / l;

            if((0.0 <= d1 && d1 < 1.0) && (0.0 <= d2 && d2 < 1.0))
            {
                deltaVet.x += (1.0 - d1) * (fimDiag.x - iniDiag.x);
                deltaVet.y += (1.0 - d1) * (fimDiag.y - iniDiag.y);
                overlap = 1;
            }

            e1->setCentroX(e1->getCentroX() + (deltaVet.x * -1));
            e1->setCentroY(e1->getCentroX() + (deltaVet.y * -1));
/*
            e1->centro.x += deltaVet.x * -1;
            e1->centro.y += deltaVet.y * -1;*/
        }
    }
    return overlap;
}

void escreveTexto(void * font, char *s, float x, float y)
{
    glPushMatrix();
        glLoadIdentity();
        glRasterPos2d(x - 20, y);

        for (int i = 0; i < strlen(s); i++) 
            glutBitmapCharacter(font, s[i]);
    glPopMatrix();
}