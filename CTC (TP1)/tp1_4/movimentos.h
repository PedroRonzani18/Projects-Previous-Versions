#ifndef _MOVIMENTOS_H
#define _MOVIMENTOS_H

using namespace std;

// Altera o valor do ponto central do player e sua hitbox
void movimentacaoJogador();

// Altera o valor do ponto central dos NPCS
void movimentaNPC(int e);

void movimentaShots();

void atirar();

// Garante que o player nunca saia da tela.
int dentroTela(entidade* e);

// Ativa e altera os valores dos vertices da hitbox dos tiros
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