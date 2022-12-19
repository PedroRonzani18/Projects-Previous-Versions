#ifndef _OBJLOADER_H
#define _OBJLOADER_H

// STD libs
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

//GLFW
#include <GLFW/glfw3.h>

//OpenGL Math libs
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Own libs
#include "Vertex.h"

static std::vector<Vertex> loadObject(const char* fileName)
{
	//Vertex portions
	std::vector<glm::fvec3> positions;
	std::vector<glm::fvec2> textureCoords;
	std::vector<glm::fvec3> normals;

	//Face vectors
	std::vector<GLfloat> positionIndices;
	std::vector<GLfloat> textureCoordIndices;
	std::vector<GLfloat> normalIndices;

	//Vertex array
	std::vector<Vertex> vertices;

	std::stringstream ss;
	std::ifstream file(fileName);
	std::string line = "";
	std::string prefix = "";
	glm::vec3 temp_vec3;
	glm::vec2 temp_vec2;
	GLint temp_glint = 0;

	//File open error check
	if (!file.is_open())
		std::cout<< "Erro na loadObject: arquivo nao pode ser aberto." << std::endl;
	

	//Read one line at a time
	while (std::getline(file, line))
	{
		//Get the prefix of the line
		ss.clear();
		ss.str(line);
		ss >> prefix;

		if (prefix == "#"){}

		else if (prefix == "o"){}
		else if (prefix == "s"){}
		else if (prefix == "use_mtl"){}

		else if (prefix == "v") //Vertex position
		{
			ss >> temp_vec3.x >> temp_vec3.y >> temp_vec3.z;
			positions.push_back(temp_vec3);
		}

		else if (prefix == "vt")
		{
			ss >> temp_vec2.x >> temp_vec2.y;
			textureCoords.push_back(temp_vec2);
		}

		else if (prefix == "vn")
		{
			ss >> temp_vec3.x >> temp_vec3.y >> temp_vec3.z;
			normals.push_back(temp_vec3);
		}

		else if (prefix == "f")
		{
			int counter = 0;
			while (ss >> temp_glint)
			{
				//Pushing indices into correct arrays
				if (counter == 0)
					positionIndices.push_back(temp_glint);
				else if (counter == 1)
					textureCoordIndices.push_back(temp_glint);
				else if (counter == 2)
					normalIndices.push_back(temp_glint);

				//Handling characters
				if (ss.peek() == '/')
				{
					++counter;
					ss.ignore(1, '/');
				}

				else if (ss.peek() == ' ')
				{
					++counter;
					ss.ignore(1, ' ');
				}

				//Reset the counter
				if (counter > 2)
					counter = 0;
			}	
		}
		else{}
	}

	//Build final vertex array (mesh)
	vertices.resize(positionIndices.size(), Vertex());

	//Load in all indices
	for (size_t i = 0; i < vertices.size(); ++i)
	{
		vertices[i].position = positions[positionIndices[i]-1];
		vertices[i].texCoord = textureCoords[textureCoordIndices[i]-1];
		vertices[i].normal = normals[normalIndices[i] - 1];
		vertices[i].color = glm::vec3(1.f, 1.f, 1.f);
	}

	//DEBUG
	std::cout << "Nr of vertices: " << vertices.size() << "\n";

	return vertices;
}

#endif