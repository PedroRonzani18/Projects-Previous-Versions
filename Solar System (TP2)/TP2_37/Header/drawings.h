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

void drawPlanet(std::shared_ptr<Planet> planet, std::shared_ptr<double> time);
void drawMoon(std::shared_ptr<Moon>  moon, std::shared_ptr<double> time);
void drawSun(std::shared_ptr<Sol>  sun, std::shared_ptr<double> time);
void drawCamera(std::shared_ptr<Camera> camera);
void drawCylinder(GLdouble base, GLdouble top, GLdouble height, GLint slices, GLint stacks);


//void configuraTextures();

#endif