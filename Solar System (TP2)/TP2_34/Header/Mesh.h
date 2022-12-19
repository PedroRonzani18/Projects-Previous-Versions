#ifndef _MESH_H
#define _MESH_H

#include <GL/freeglut.h>
#include <iostream>
#include <vector>
#include "Vertex.h"
#include "Material.h"
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Mesh
{
    private:
        Vertex * vertexArray;
        unsigned nrOfVertices;
        GLuint* indexArray;
        unsigned nrOfIndices;

        GLuint VAO;
        GLuint VBO;
        GLuint EBO;

        glm::vec3 position;
        glm::vec3 origin;
        glm::vec3 rotation;
        glm::vec3 scale;

	    glm::mat4 ModelMatrix;

        void initVertexData(Vertex * vertxArray, const unsigned& numVertices, GLuint* indexArray, const unsigned& numIndicies);

        void initVAO();

        void initModelMatrix();

    public:
        Mesh(){}
        Mesh(Vertex * vertxArray, const unsigned& numVertices, GLuint* indexArray, const unsigned& numIndicies);

        void render();
        void update();

};

#endif