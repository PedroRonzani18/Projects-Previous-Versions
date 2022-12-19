#ifndef _MOVIMENTOSNEW_H
#define _MOVIMENTOSNEW_H

int dentroTela(entidade* e);

void generalHitboxMovement(entidade* e, double seuAngulo);

void playerModelMovement();
void playerMovement();



void enemyModelMovement(entidade* e);
void enemyHitboxMovement(entidade* e);
void enemyGeneralMovement();

void colocaShotDentroVector();
void posicionaShotComPlayer();
void shotsAloneMovement(int e);
void retiraShotCasoColisao();
void shotsGeneralMovement();


#endif