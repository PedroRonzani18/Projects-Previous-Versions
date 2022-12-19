#ifndef _Vertex_H
#define _Vertex_H

#include <glm/glm.hpp>

class Vertex{
    public:
        glm::vec3 position;
        glm::vec3 color;
        glm::vec2 texCoord;
        glm::vec3 normal;
};

#endif