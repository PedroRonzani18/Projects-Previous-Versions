#ifndef _ENTITY_H
#define _ENTITY_H

#include "ponto.h"

class Entity{
    public:
        double x_max, x_min; // Valores maximos e minimos que x e y podem alcançar 
        double y_max, y_min; // baseados nas coordenadas extremas do desenho.
        double x_move, y_move; // Unidade de movimento nos eixos x e y ("velocidade" da entidade).

        Ponto centro;  // Coordenadas do Ponto central.
        Ponto hitbox[4]; // Modelo de hitbox do objeto
        Ponto alteredHitbox[4]; // Modelo alterado por rotação e translação do objeto
        Ponto resize; // Escalas de redimensionamento das coordenadas.

        GLboolean onScreen; // Objeto se econtra dentro da caixa de visualização ou não.
        GLuint model; // ID da displayList de desenho.

        GLboolean drawHitbox;
};

extern std::vector<Entity> entityList; // todos tem acesso a esse vector

#endif