    #ifndef _DRAWINGS_H
#define _DRAWINGS_H

#include <GL/freeglut.h>
#include <SOIL/SOIL.h>

#include "Planet.h"
#include "Moon.h"
#include "Sol.h"
#include "Camera.h"
#include <memory>

void drawSolidSphere(double radius, int stacks, int columns);
    
GLuint loadTexture(const char* arquivo);

void createTextures();

void drawCorpse(std::shared_ptr<Planet> p, double time);
void drawCorpse(std::shared_ptr<Moon>  moon, double time);
void drawCorpse(std::shared_ptr<Sol>  moon, double time);
void drawCamera(std::shared_ptr<Camera> camera);

//void configuraTextures();

#endif