#ifndef _GLOBALPARAMETERS_H
#define _GLOBALPARAMETERS_H

#include <GL/freeglut.h>

extern double aspectRatio;
extern int keys[6];
extern GLuint aviaoDisplayList, aviaoDisplayList1, aviaoDisplayList2, shotDisplayList, buttonDisplayList;
extern int sposition;
extern int flag;
extern int tempo;


template<typename Base, typename T>
extern inline bool instanceof(const T *ptr) {
   return dynamic_cast<const Base*>(ptr) != nullptr;
}

#endif