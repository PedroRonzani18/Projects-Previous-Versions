#include "../Header/Material.h"

// Construtor de um material com parâmetros específicos
Material::Material(float* ambient, float* difuse, float* espec, float shine)
{
    for(int i=0; i<4; i++)
    {
        this->matAmbient[i] = ambient[i];
        this->matDifuse[i] = difuse[i];
        this->matEspec[i] = espec[i];
    }

    this->matShininess = shine;
}