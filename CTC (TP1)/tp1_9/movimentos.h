#ifndef _MOVIMENTOS_H
#define _MOVIMENTOS_H

using namespace std;

// Altera o valor do ponto central do player e sua hitbox
void playerMovement();

// altera o valor do ponto central dos inimigos
// controla o movimento dos inimigos
void enemyMovement(Entity* e);

void movimentaShots();

void shotsReposiotioning();

void shotsHitboxMovement();

// Ativa e altera os valores dos vertices da hitbox dos NPC
void enemyHitboxMovement(Entity* e);

void atirar();

// Garante que o player nunca saia da tela.
int dentroTela(Entity* e);

#endif