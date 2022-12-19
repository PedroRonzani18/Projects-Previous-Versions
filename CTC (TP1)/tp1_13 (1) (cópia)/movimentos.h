#ifndef _MOVIMENTOS_H
#define _MOVIMENTOS_H

using namespace std;



void playerModelMovement();

// Altera o valor do ponto central do player e sua hitbox
void playerMovement();


void enemyModelMovement(entidade* e);
void enemyHitboxMovement(entidade* e);// Ativa e altera os valores dos vertices da hitbox dos NPC

void enemyGeneralMovement();// altera o valor do ponto central dos inimigos
                            // controla o movimento dos inimigos


void shotsReposiotioning(); // Se o tiro colide com inimigo, ou sai da tela, volta para a posição inicial

void shotsMovementWithPlayer(int e);
void shotsAloneMovement(int e);
void shotsGeneralMovement();

// Garante que a entidade nunca saia da tela.
int dentroTela(entidade* e);

#endif