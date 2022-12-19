#ifndef _GLOBALPARAMETERS_H
#define _GLOBALPARAMETERS_H

#include <GL/freeglut.h>
#include <SDL2/SDL_mixer.h>
#include <vector>
#include "Keyboard.h"
#include <memory>

extern float razaoAspecto;
extern double tempo;
extern Keyboard* keys;
extern std::vector<GLuint> texturesId;
extern int buttons[];

#endif