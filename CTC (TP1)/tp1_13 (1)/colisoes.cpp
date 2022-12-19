#include "inicializa.h"
#include "colisoes.h"

using namespace std;

void shotHitbox(int e)
{
    if(!shotsList[e].onScreen) // coloca a hitbox na posição inicial
    {
        for(int i=0; i<4; i++)
        {
            shotsList[e].alteredHitbox[i].x = shotsList[e].hitbox[i].x + shotsList[e].centro.x;
            shotsList[e].alteredHitbox[i].y = shotsList[e].hitbox[i].y + shotsList[e].centro.y;
        }
    }
}

void removeHitbox(entidade* e)
{
    for(int i=0; i<4; i++)
    {
        e->alteredHitbox[i].x = 0;
        e->alteredHitbox[i].y = 0;
    }
}

void confereEndGame()
{
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
    for(int i=1; i < entityList.size(); i++)
    {
        if(entityList[i].onScreen) // se houver algum inimigo vivo, o jogo continua
            return 0;
    }
    return 1; // se ninguem está na tela, retorna que acabou
}

int colisaoGeral(entidade* e1, entidade* e2)
{
    vertice iniDiag, fimDiag, iniLado, fimLado, deltaVet;
    double l=0, d1=0, d2=0;
    int overlap = 0;
    iniDiag.x = e1->centro.x;
    iniDiag.y = e1->centro.y;
    
    for(int i=0; i<4; i++)
    {
        deltaVet.x = 0;
        deltaVet.y = 0;

        fimDiag.x = e1->alteredHitbox[i].x;
        fimDiag.y = e1->alteredHitbox[i].y;

        for(int j=0, s=1; j<4; j++, s=(j+1)%4) 
        {
            iniLado = e2->alteredHitbox[j];
            fimLado = e2->alteredHitbox[s];
    
            l = (fimLado.x - iniLado.x) * (iniDiag.y - fimDiag.y) - (iniDiag.x - fimDiag.x) * (fimLado.y - iniLado.y);

            d1 = ((iniLado.y - fimLado.y) * (iniDiag.x - iniLado.x) + (fimLado.x - iniLado.x) * (iniDiag.y - iniLado.y)) / l;

            d2 = ((iniDiag.y - fimDiag.y) * (iniDiag.x - iniLado.x) + (fimDiag.x - iniDiag.x) * (iniDiag.y - iniLado.y)) / l;

            if((0.0 <= d1 && d1 < 1.0) && (0.0 <= d2 && d2 < 1.0))
            {
                deltaVet.x += (1.0 - d1) * (fimDiag.x - iniDiag.x);
                deltaVet.y += (1.0 - d1) * (fimDiag.y - iniDiag.y);
                overlap = 1;
            }

            //ACHO Q É ESSE O PROBLEMA
            e1->centro.x += deltaVet.x * -1;
            e1->centro.y += deltaVet.y * -1;
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