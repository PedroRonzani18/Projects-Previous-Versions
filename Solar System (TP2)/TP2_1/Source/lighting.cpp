#include "../Header/lighting.h"
#include "../Header/globalParameters.h"
#include <iostream>

long font = (long)GLUT_BITMAP_8_BY_13;

Lighting::Lighting()
{
    m = 0.2;
    d = 1;
    e = 1;
    s = 50;

    for(int i=0; i<3; i++)
    {
        lightAmb[i] = 0;
        lightDif0[i] = d;
        lightSpec0[i] = e;
        lightPos0[i] = 0;
        globAmb[i] = m;
        matAmbAndDif[i] = 1;
        matSpec[i] = 1;
    }

    lightAmb[3] = 1;
    lightDif0[3] = 1;
    lightSpec0[3] = 1;
    lightPos0[3] = 1;
    globAmb[3] = 1;
    matAmbAndDif[3] = 1;
    matSpec[3] = 1;

    light0Ligada = 1;
}

void Lighting::configuraMateriais()
{
    glEnable(GL_COLOR_MATERIAL);

    // Definindo as propriedades do material
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, matAmbAndDif);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
    glMaterialf(GL_FRONT, GL_SHININESS, 0);
    //glMaterialf(GL_FRONT, GL_EMISSION, 128);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
}

// Escreve uma cadeia de caracteres
void escreveTextoNaTela(void *font, char *string)
{
    char *c;
    for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}

// Converte um número decimal em string
void floatParaString(char * destStr, int precision, float val)
{
    sprintf(destStr,"%f",val);
    destStr[precision] = '\0';
}

void Lighting::informacoesIluminacao(double x, double y, double z)
{
    char theStringBuffer[10];        

    glDisable(GL_LIGHTING);

    glRasterPos3f(x-4.5, y + 1.6, z -2.3);
    escreveTextoNaTela((void*)font, (char*)"Luz ambiente global: ");
    
    glRasterPos3f(x-4.5, y + 1.4, z -2);
    escreveTextoNaTela((void*)font, (char*)"  - Intensidade (Z/X): ");
    floatParaString(theStringBuffer, 4, m);
    escreveTextoNaTela((void*)font, theStringBuffer);

    glRasterPos3f(x-5.55, y + 0.35, z -3.5);
    escreveTextoNaTela((void*)font, (char*)"Luz branca: ");

    glRasterPos3f(x-5.8, y, z -3.5);
    escreveTextoNaTela((void*)font, (char*)"  - Intensidade difusa (C/V): ");
    floatParaString(theStringBuffer, 4, d);
    escreveTextoNaTela((void*)font, theStringBuffer);

    glRasterPos3f(x-5.9, y-0.3, z -3.5);
    escreveTextoNaTela((void*)font, (char*)"  - Intensidade especular (B/N): ");
    floatParaString(theStringBuffer, 4, e);
    escreveTextoNaTela((void*)font, theStringBuffer);

    glRasterPos3f(x-6.3, y-1.3, z -4);
    escreveTextoNaTela((void*)font, (char*)"Material: ");

    glRasterPos3f(x-6.7, y-1.7, z -4);
    escreveTextoNaTela((void*)font, (char*)"  - Expoente shineness (W/A): ");
    floatParaString(theStringBuffer, 5, 50);
    escreveTextoNaTela((void*)font, theStringBuffer);

    glEnable(GL_LIGHTING);

}

void Lighting::atualizaPropriedadesLuz()
{
    if(0 < m) m += -keys->x * 0.05;
    if(m < 1) m +=  keys->z * 0.05;

    if(0 < d) d += -keys->v * 0.05;
    if(d < 1) d +=  keys->c * 0.05;

    if(0 < e) e += -keys->n * 0.05;
    if(e < 1) e +=  keys->b * 0.05;

    for(int i=0; i<3; i++)
        lightDif0[i] = d;

    for(int i=0; i<3; i++)
        lightSpec0[i] = e;

    for(int i=0; i<3; i++)
        globAmb[i] = m;

    


    /* Propriedades da fonte de luz LIGHT0 */
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb); // rgb da luz ambiente
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif0);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec0);    
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);


    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb);        // Luz ambiente global
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, false);// Enable local viewpoint

    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 128);// teria que variarcmom pressionamento de tela

    if(buttons[0] && keys->l)
    {
        if(light0Ligada) light0Ligada = 0;
        else             light0Ligada = 1;

        buttons[0] = 0;

        if(light0Ligada)
            glEnable(GL_LIGHT0);
        else 
            glDisable(GL_LIGHT0);
    }

}