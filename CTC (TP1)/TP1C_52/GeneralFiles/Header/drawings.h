#ifndef _DRAWINGS_H
#define _DRAWINGS_H

#include "../../BaseClasses/Header/MovableEntity.h"
#include <SOIL/SOIL.h>

extern std::vector<GLuint> textures;

void initializeTextures();

GLuint loadTexture(const char* arquivo);

void drawMenuArrow();
void desenhaPlayer();
void drawPlane1();
void drawPlane2();
void drawShot();
void drawBackground3();
void drawBackground2();

void templateSquare(double x, double y, GLuint id);

void drawAjudaButton();
void drawDeaultShot();
void drawBackground();
void drawStartButton();

void drawExplosionAnimation(OrderedPair mid);
void carregaSpritesExplosão();
void drawEmphassisMenuButton();

void drawModel(MovableEntity* m);
void drawHitbox(MovableEntity* m);

void abobora();

//void inicializaDisplayLists();


#endif