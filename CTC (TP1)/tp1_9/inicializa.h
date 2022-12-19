#ifndef _INICIALIZA_H
#define _INICIALIZA_H

#include "parametros.h"

// Determina os parâmetros iniciais de cada entidade e os armazena dentro do vector entityList
void listaStructsEntidades();

// Determina os parâmetros iniciais de cada tiro e os armazena dentro do vector shotsList
void listaStructsShots();

// Cria displayLists de desenho de cada objeto
void inicializar();

// Cria as displaylists de desenho
void inicializaDisplayLists();

// Define os valores das coordenadas centrais default de cada entidade
void inicializaPosicoes();

void inicializaOnScreen();

void posicaoInicialInimigos();

void posicaoInicialShots();

// Define a escala de todas as coordenadas de cada entidade
void inicializaEscala();

// Cria uma Hitbox para todas as entidades
void inicializaHitbox();

#endif