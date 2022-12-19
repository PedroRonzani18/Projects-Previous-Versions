#ifndef _PARAMETROS_H
#define _PARAMETROS_H

#include <GL/freeglut.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

using namespace std;

/*Vetor que idntifica se as teclas estão ligadas ou desligadas:
    [0] = w / cima
    [1] = s / baixo
    [2] = d / direita
    [3] = a / esquerda
    [4] = - / _
    [5] = + / =
*/
extern GLboolean on_off[7];

// EG = 1: game over.
extern GLuint endGame;

// Variável que ativa ou desativa o desenho da 'hitbox' de cada entidade.
extern GLboolean hitBox;

// Variavel da razão aspecto da tela.
extern GLfloat aspectRatio;

// Struct de um ponto com 2 coordenadas(x,y).
typedef struct VERTICE
{
    double x,y;
}vertice;

// Struct que contém os dados das entidades.
typedef struct ENTIDADE
{
    double x_max, x_min; // Valores maximos e minimos que x e y podem alcançar 
    double y_max, y_min; // baseados nas coordenadas extremas do desenho.
    double x_move, y_move; // Unidade de movimento nos eixos x e y ("velocidade" da entidade).
    int ladoHorizontal, ladoVertical; // LH = 1: anda na horizontal. 
                                      // LV = 1: anda na vertical.
    vertice centro;  // Coordenadas do ponto central.

    vertice hitbox[4]; // Modelo de hitbox do objeto
    vertice alteredHitbox[4]; // Modelo alterado por rotação e translação do objeto
    
    vertice resize; // Escalas de redimensionamento das coordenadas.
    double angularSpeed; // Velocidade angular do objeto
    double vetorialSpeed; // Velocidade vetorial do objeto
    double angulo;
    GLboolean onScreen; // Objeto se econtra dentro da caixa de visualização ou não.
    GLuint model; // ID da displayList de desenho.
    double bulletSpeed;
    GLuint continuar;
    GLboolean drawHitbox;
}
entidade;

// Vector que armazena as Structs das entidades.
extern vector<entidade> entityList;

// Vector que armazena as Structs dos tiros.
extern vector<entidade> shotsList;

// ID das displaylists de desenho.
extern GLuint aviaoDisplayList, aviaoDisplayList1, aviaoDisplayList2, shotDisplayList;

#endif