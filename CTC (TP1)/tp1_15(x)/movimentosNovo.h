#ifndef _MOVIMENTOSNOVO_H
#define _MOVIMENTOSNOVO_H


// Garante que a entidade nunca saia da tela.
int dentroTela(entidade* e);

void playerModelMovement();

// Altera o valor do ponto central do player e sua hitbox
void playerMovement();


void enemyModelMovement(entidade* e);
void enemyHitboxMovement(entidade* e);// Ativa e altera os valores dos vertices da hitbox dos NPC

void enemyGeneralMovement();// altera o valor do ponto central dos inimigos
                            // controla o movimento dos inimigos

void colocaShotDentroVector();
void posicionaShotComPlayer();
void shotsAloneMovement(int e);
void retiraShotCasoColisao();
void shotsGeneralMovement();

#endif