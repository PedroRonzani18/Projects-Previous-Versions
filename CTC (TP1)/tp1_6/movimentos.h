#ifndef _MOVIMENTOS_H
#define _MOVIMENTOS_H

using namespace std;

// Se o tiro não tiver sido acionado, sua hitbox se move junto do player
void shotHitboxMovement(int e);

// Altera o valor do ponto central do player e sua hitbox
void movimentacaoJogador();

// Altera o valor do ponto central dos NPCS
void movimentaNPC(int e);

void movimentaShots();

void movimentaShotsHitbox();

void atirar();

// Garante que o player nunca saia da tela.
int dentroTela(entidade* e);

#endif