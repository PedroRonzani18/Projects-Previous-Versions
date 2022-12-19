#ifndef _GLOBALPARAMETERS_H
#define _GLOBALPARAMETERS_H

#include <GL/freeglut.h>
#include <vector>

extern int keys[6];
extern int sposition;
extern int flag, tempo, cont;

extern int top, bottom, left, right;

extern int frames;

template<typename Base, typename T>
extern inline bool instanceof(const T *ptr) {
   return dynamic_cast<const Base*>(ptr) != nullptr;
}

#endif