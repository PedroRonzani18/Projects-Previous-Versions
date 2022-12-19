#ifndef _MODEL_H
#define _MODEL_H

#include <vector>
#include <string>
#include <GL/freeglut.h>

#include "Vertex.h"
#include "Texture.h"
#include "Object.h"
#include "Parser.h"

class Model : public Object
{
    private:
        std::vector<Vertex> loadObject(const char* fileName);

    public:
        std::vector<Vertex> vertices;
        Texture texture;
        const char* modelo;
        float size;

        Model(const char* fileObj, const char* fileTexture);
        Model(const char* fileName);
};

#endif