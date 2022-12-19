#ifndef _DRAWINGS_H
#define _DRAWINGS_H

#include "../../BaseClasses/Header/MovableEntity.h"
#include <SOIL/SOIL.h>

extern std::vector<GLuint> textures;

void initializeTextures();

GLuint loadTexture(const char* arquivo);

void desenhaPlayer();
void drawPlane1();
void drawPlane2();
void drawShot();

void drawAjudaButton();
void drawMenuButton();
void drawDeaultShot();
void drawBackground();
void drawBackground2();
void drawStartButton();

void drawEmphassisMenuButton();

void drawModel(MovableEntity* m);
void drawHitbox(MovableEntity* m);

void abobora();

//void inicializaDisplayLists();


#endif