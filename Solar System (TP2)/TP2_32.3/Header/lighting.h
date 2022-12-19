#ifndef _LIGHTING_H
#define _LIGHTING_H

#include "Coord.h"
#include <GL/freeglut.h>

class Lighting
{
    public:
        Lighting(){this->alteravel = 0;}
        Lighting(int alteravel, double d, double m, double e, GLenum glLightConst);
        Lighting(double r, double g, double b, GLenum glLightConst);

        double d,e,m,s;
        double r,g,b;

        int hasAtenuation;
        int lightLigada;
        int lighGeralLigada;
        int alteravel;

        // Propriedades das fontes de luz
        float lightAmb[4];    // ??
        float lightDif[4];  // intensidade da difusa do branco
        float lightSpec[4]; // intensidade da especular do branco
        float lightPos[4];  // posição ?? da luz
        float globAmb[4];

        // Propriedades do material da esfera
        float matAmbAndDif[4];   // cor ambiente e difusa: branca (ambiente = cor | )
        float matSpec[4];    // cor especular: branca

        GLenum glLightConst;

        void atualizaPropriedadesLuz();
        void lightingInfo();
};



#endif