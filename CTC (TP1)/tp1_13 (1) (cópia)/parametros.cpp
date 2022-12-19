#include "parametros.h"

GLuint endGame = -1;
GLboolean on_off[7] = {0,0,0,0,0,0,0};
GLboolean hitBox = true;
GLfloat aspectRatio;

vector<entidade> entityList;
vector<entidade> shotsList;

GLuint aviaoDisplayList, aviaoDisplayList1, aviaoDisplayList2, shotDisplayList;