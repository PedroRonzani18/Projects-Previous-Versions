#include "../Header/lighting.h"
#include "../Header/globalParameters.h"
#include <iostream>

/*Luz não alterável mas cor customizável*/
Lighting::Lighting(double r, double g, double b, GLenum glLightConst)
{
    this->alteravel = 0;

    this->glLightConst = glLightConst;
    this->r = r;
    this->g = g;
    this->b = b;
    
    lightLigada = 1;
    lighGeralLigada = 1;

    for(int i=0; i<3 ; i++)
    {
        lightAmb[i] = 0;
        lightSpec[i] = 0;
        lightPos[i] = 0;
        globAmb[i] = 0;
        matAmbAndDif[i] = 1;
        matSpec[i] = 1;
    }

    lightDif[0] = r;
    lightDif[1] = g;
    lightDif[2] = b;
    lightDif[3] = 1;

    lightAmb[3] = 1;
    lightSpec[3] = 1;
    lightPos[3] = 1;
    globAmb[3] = 1;
    matAmbAndDif[3] = 1;
    matSpec[3] = 1; 

    hasAtenuation = 1;

    glEnable(glLightConst);
}

/*luz branca alterável*/
Lighting::Lighting(int alteravel, double d, double m, double e, GLenum glLightConst)
{
    this->d = d;
    this->m = m;
    this->e = e;
    this->glLightConst = glLightConst;
    
    lightLigada = 1;
    lighGeralLigada = 1;

    for(int i=0; i<3 ; i++)
    {
        lightAmb[i] = 0;
        lightDif[i] = d;
        lightSpec[i] = e;
        lightPos[i] = 0;
        globAmb[i] = m;
        matAmbAndDif[i] = 1;
        matSpec[i] = 1;
    }

    lightAmb[3] = 1;
    lightDif[3] = 1;
    lightSpec[3] = 1;
    lightPos[3] = 1;
    globAmb[3] = 1;
    matAmbAndDif[3] = 1;
    matSpec[3] = 1;    

    this->alteravel = 1;
    hasAtenuation = 0;

    glEnable(glLightConst);
}

void Lighting::configuraMateriais()
{
    glEnable(GL_COLOR_MATERIAL);

    // Definindo as propriedades do material
    //glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, matAmbAndDif);
    //glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
    //glMaterialf (GL_FRONT, GL_SHININESS, 0);
    //glMaterialf(GL_FRONT, GL_EMISSION, 128);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}

void Lighting::atualizaPropriedadesLuz()
{
    //printf("Alt: %d\n",alteravel);

    globAmb[0] = 0;
    globAmb[1] = 0;
    globAmb[2] = 0;
    globAmb[3] = 0;

    if(alteravel)
    {
        if(0 < m) m += -keys->x * 0.05;
        if(m < 1) m +=  keys->z * 0.05;

        if(0 < d) d += -keys->v * 0.05;
        if(d < 1) d +=  keys->c * 0.05;

        if(0 < e) e += -keys->n * 0.05;
        if(e < 1) e +=  keys->b * 0.05;

        for(int i=0; i<3; i++) 
        {
            lightDif[i] = d;
            lightSpec[i] = e;
            lightAmb[i] = m;
        }
    }
    
    else
    {
        for(int i=0; i<3; i++)
        {
            lightSpec[i] = 0;
            lightAmb[i] = 0;
        }
        lightDif[0] = r;
        lightDif[1] = g;
        lightDif[2] = b; 
        lightDif[3] = 1;
    }

    /* Propriedades da fonte de luz LIGHT0 */
    glLightfv(glLightConst, GL_AMBIENT, lightAmb); // rgb da luz ambiente
    glLightfv(glLightConst, GL_DIFFUSE, lightDif);
    glLightfv(glLightConst, GL_SPECULAR, lightSpec);    
    glLightfv(glLightConst, GL_POSITION, lightPos);

    if(hasAtenuation)
        glLightf(glLightConst, GL_QUADRATIC_ATTENUATION, 0.8);     

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb); // Luz ambiente global
}

// Escreve uma cadeia de caracteres
void writeOnScreen(void *font, char *string)
{
    char *c;
    for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}

void Lighting::lightingInfo()
{
    glDisable(GL_LIGHTING);

    char* dados = (char*)malloc(100 * sizeof(char));

    glRasterPos3f(-0.85 * razaoAspecto, 0.8, -2.0);
    sprintf(dados, "    FONTE DE LUZ DO SOL");
    writeOnScreen(GLUT_BITMAP_8_BY_13, dados);

    glRasterPos3f(-0.85 * razaoAspecto, 0.74, -2.0);
    sprintf(dados, "* Componente Ambiente (Z/X) : %0.2f", m);
    writeOnScreen(GLUT_BITMAP_8_BY_13, dados);

    glRasterPos3f(-0.85 * razaoAspecto, 0.68, -2.0);
    sprintf(dados, "* Componente Difusa (C/V) : %0.2f", d);
    writeOnScreen(GLUT_BITMAP_8_BY_13, dados);

    glRasterPos3f(-0.85 * razaoAspecto, 0.62, -2.0);
    sprintf(dados, "* Componente Especular (B/N) : %0.2f", e);
    writeOnScreen(GLUT_BITMAP_8_BY_13, dados);

    glRasterPos3f(-0.85 * razaoAspecto, 0.56, -2.0);
    sprintf(dados, "* Estado da Luz solar (K): %s", lightLigada ? "Ligada" : "Desligada");
    writeOnScreen(GLUT_BITMAP_8_BY_13, dados);

    glRasterPos3f(-0.85 * razaoAspecto, 0.44, -2.0);
    sprintf(dados, "    FONTE DE LUZ DOS PLANETAS");
    writeOnScreen(GLUT_BITMAP_8_BY_13, dados);

    glRasterPos3f(-0.85 * razaoAspecto, 0.38, -2.0);
    sprintf(dados, "* Luzes da Terra, Marte, Saturno (L) : %s", lighGeralLigada ? "Ligada" : "Desligada");
    writeOnScreen(GLUT_BITMAP_8_BY_13, dados);

    free(dados);
}