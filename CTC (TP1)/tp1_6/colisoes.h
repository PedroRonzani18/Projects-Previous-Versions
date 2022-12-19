#ifndef _COLISOES_H
#define _COLISOES_H

#include "inicializa.h"

using namespace std;



// Ativa e altera os valores dos vertices da hitbox dos inimigos SE ESTIVEREM NA TELA
void enemyHitbox(entidade* e);

// "remove" a hitbox de  uma entidade
void removeHitbox(entidade* e);

 // Confere se algum inimigo está vivo
int voceVenceu();

// Detecta colisões
int colisaoGeral(entidade* e1, entidade* e2);

// Escreve "Game Over" quando o programa acaba
void escreveTexto(void * font, char *s, float x, float y);

#endif