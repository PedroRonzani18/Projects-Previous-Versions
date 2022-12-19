#include "../Header/Mesh.h"
/*
Mesh::Mesh(Vertex * vertxArray, const unsigned& numVertices, GLuint* indexArray, const unsigned& numIndicies)
{
    this->initVertexData(vertxArray, numVertices, indexArray, numIndicies);
    this->initVAO();
    this->initModelMatrix();
}

void Mesh::initVertexData(Vertex * vertxArray, const unsigned& numVertices, GLuint* indexArray, const unsigned& numIndicies)
{
    for(size_t i=0; i<numVertices; i++)
    {
        this->vertices.push_back(vertxArray[i]);
    }

    for(size_t i=0; i<numIndicies; i++)
    {
        this->indices.push_back(indexArray[i]);
    }
}

void Mesh::render()
{
    //Bind VAO
    glBindVertexArray(this->VAO);

    glDrawElements(GL_TRIANGLES,this->indices.size(),GL_UNSIGNED_INT,0);
}

void Mesh::update()
{

}

void Mesh::initVAO()
{
    //Create VAO
    glCreateVertexArrays(1, &this->VAO);
    glBindVertexArray(this->VAO);

    //GEN VBO AND BIND AND SEND DATA
    glGenBuffers(1, &this->VBO);
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, this->nrOfVertices * sizeof(Vertex), this->vertexArray, GL_STATIC_DRAW);

    //GEN EBO AND BIND AND SEND DATA
    if (this->nrOfIndices > 0)
    {
        glGenBuffers(1, &this->EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->nrOfIndices * sizeof(GLuint), this->indexArray, GL_STATIC_DRAW);
    }

    //SET VERTEXATTRIBPOINTERS AND ENABLE (INPUT ASSEMBLY)
    //Position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position));
    glEnableVertexAttribArray(0);
    //Color
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, color));
    glEnableVertexAttribArray(1);
    //Texcoord
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texCoord));
    glEnableVertexAttribArray(2);
    //Normal
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
    glEnableVertexAttribArray(3);

    //BIND VAO 0
    glBindVertexArray(0);
}

void Mesh::initModelMatrix()
{
    this->position = glm::vec3(0.f);
    this->rotation = glm::vec3(0.f);
    this->scale = glm::vec3(1.f);

    this->ModelMatrix = glm::mat4(1.f);
    this->ModelMatrix = glm::translate(this->ModelMatrix, this->position);
    this->ModelMatrix = glm::rotate(this->ModelMatrix, glm::radians(this->rotation.x), glm::vec3(1.f, 0.f, 0.f));
    this->ModelMatrix = glm::rotate(this->ModelMatrix, glm::radians(this->rotation.y), glm::vec3(0.f, 1.f, 0.f));
    this->ModelMatrix = glm::rotate(this->ModelMatrix, glm::radians(this->rotation.z), glm::vec3(0.f, 0.f, 1.f));
    this->ModelMatrix = glm::scale(this->ModelMatrix, this->scale);
}
*/