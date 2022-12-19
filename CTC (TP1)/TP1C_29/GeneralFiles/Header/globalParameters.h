#ifndef _GLOBALPARAMETERS_H
#define _GLOBALPARAMETERS_H

#include <GL/freeglut.h>

extern int keys[6];
extern int sposition;
extern int flag;
extern int tempo;
extern int cont;

extern int top, bottom, left, right;

extern GLuint idTexturaFun;

extern GLuint idTextureAbobora;


template<typename Base, typename T>
extern inline bool instanceof(const T *ptr) {
   return dynamic_cast<const Base*>(ptr) != nullptr;
}

#endif