#ifndef _MOVIMENTOS_H
#define _MOVIMENTOS_H

using namespace std;

// Altera o valor do ponto central do player e sua hitbox
void playerGeneralMovement();

// altera o valor do ponto central dos inimigos
// controla o movimento dos inimigos
void enemyModelMovement(entidade* e);

void generalHitboxMovement(entidade* e);

void shotsGeneralMovement();

void enemyGeneralMovement();

void movimentaShots();

void shotsReposiotioning();

void shotsHitboxMovement();

// Ativa e altera os valores dos vertices da hitbox dos NPC
void enemyHitboxMovement(entidade* e);

void atirar();

// Garante que o player nunca saia da tela.
int dentroTela(entidade* e);

#endif