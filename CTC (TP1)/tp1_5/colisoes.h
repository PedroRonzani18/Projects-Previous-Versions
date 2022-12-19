#ifndef _COLISOES_H
#define _COLISOES_H

#include "inicializa.h"

using namespace std;

void shotHitbox(int e);

int voceVenceu();

void removeHitbox(entidade* e);

// Ativa e altera os valores dos vertices da hitbox dos NPC
void enemyHitbox(entidade* e);

// Detecta colisões
int colisaoGeral(entidade* e1, entidade* e2);

// Escreve "Game Over" quando o programa acaba
void escreveTexto(void * font, char *s, float x, float y);

#endif