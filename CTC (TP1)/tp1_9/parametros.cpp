#include "parametros.h"

GLuint endGame = 0;
GLboolean on_off[7] = {0,0,0,0,0,0,0};
GLboolean hitBox = true;
GLfloat aspectRatio;

vector<Entity> entityList;
vector<Entity> shotsList;

GLuint aviaoDisplayList, aviaoDisplayList1, aviaoDisplayList2, shotDisplayList;