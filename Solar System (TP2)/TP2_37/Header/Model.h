#ifndef _MODEL_H
#define _MODEL_H

#include <vector>
#include <string>
#include <GL/freeglut.h>

#include "Vertex.h"
#include "Texture.h"

class Model 
{
    private:
        std::vector<Vertex> loadObject(const char* fileName);

    public:
        // Model data
        std::vector<Vertex> vertices;
        Texture texture;

        Model(std::vector<Vertex> vertices, Texture texture);
        Model(const char* fileObj, const char* fileTexture);
};

#endif