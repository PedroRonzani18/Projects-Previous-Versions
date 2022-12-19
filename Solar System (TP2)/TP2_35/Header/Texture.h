#ifndef _TEXTURE_H
#define _TEXTURE_H

#include <string>
#include "drawings.h"

class Texture
{
    public:
        GLuint id;
        const char* path;

        Texture(){}
        Texture(const char* path)
        {
            this->id = loadTexture(path);
            this->path = path;
        }

};

#endif