#ifndef _MODEL_H
#define _MODEL_H

#include <vector>
#include <string>
#include <GL/freeglut.h>

#include "Vertex.h"
#include "Texture.h"

class Model 
{
    public:
        // Model data
        std::vector<Vertex> vertices;
        Texture texture;

        Model(std::vector<Vertex> vertices, Texture texture);
};

#endif