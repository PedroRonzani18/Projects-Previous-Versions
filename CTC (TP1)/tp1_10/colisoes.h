#ifndef _COLISOES_H
#define _COLISOES_H

#include "inicializa.h"

using namespace std;

void shotHitbox(int e);

void confereEndGame();

int voceVenceu();

void removeHitbox(Entity* e);

// Detecta colisões
int colisaoGeral(Entity* e1, Entity* e2);

// Escreve "Game Over" quando o programa acaba
void escreveTexto(void * font, char *s, float x, float y);

#endif