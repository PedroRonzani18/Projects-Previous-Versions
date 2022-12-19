#include "colisoes.h"
#include "movimentos.h"

#define radianoParaGraus(radianos) (radianos * (180.0 / M_PI))
#define grausParaRadianos(graus) ((graus * M_PI) / 180.0)

using namespace std;

double aux_angle; //TEM que ser variavel global pra preservar seu valor como constante
//senao fica redeclarando

int dentroTela(entidade* e)
{
    // Se um dos extremos de cima, baixo, esqueda, direita ultrapassar seu respectivo limite da
    // caixa de visualização, sua coordenada X e/ou Y é programada para voltar para o limite,
    // fazendo que ele nunca saia da caixa de visualização.

    if(e->centro.y + e->y_max > 100){
        e->centro.y = 100 - e->y_max;
        return 0;
    }

    if(e->centro.y + e->y_min < -100 ){
        e->centro.y = -100 - e->y_min;
        return 0;
    }

    if(e->centro.x + e->x_max > 100 * aspectRatio){
        e->centro.x = 100 * aspectRatio - e->x_max;
        return 0;
    }
    
    if(e->centro.x + e->x_min < -100 * aspectRatio){
        e->centro.x = -100 * aspectRatio - e->x_min;
        return 0;
    }
    return 1;
}

void movimentacaoJogador()
{
    double aux_angle = grausParaRadianos(entityList[0].angulo);

    // Aumenta a angulação da entidade com '+' e diminui com '-'
    entityList[0].angulo += (on_off[4] - on_off[5]) * entityList[0].angularSpeed;

    // Movimenta para cima e para baixo com 'w' e 's' ou 'cima' e 'baixo'
    entityList[0].centro.x += (on_off[0] - on_off[1]) * cos(aux_angle) * entityList[0].vetorialSpeed;
    entityList[0].centro.y += (on_off[0] - on_off[1]) * sin(aux_angle) * entityList[0].vetorialSpeed;

    // Movimenta para direita e esquerda com 'd' e 'a' ou '->' e '<-'
    entityList[0].centro.x += (on_off[2] - on_off[3]) * cos(aux_angle - M_PI/2) * entityList[0].vetorialSpeed;
    entityList[0].centro.y += (on_off[2] - on_off[3]) * sin(aux_angle - M_PI/2) * entityList[0].vetorialSpeed;

    // Variáveis auxiliares
    double x,y;

    for(int i=0; i<4; i++)
    {
        // Usadas no calculo dos valores de x' e y' ao rotacionar a entidade
        x = entityList[0].hitbox[i].x;
        y = entityList[0].hitbox[i].y;

        // Altera o valor das coordenadas x e y da hitbox de acordo com as rotações
        entityList[0].alteredHitbox[i].x = x * cos(aux_angle + M_PI/2) - y * sin(aux_angle + M_PI/2);
        entityList[0].alteredHitbox[i].y = x * sin(aux_angle + M_PI/2) + y * cos(aux_angle + M_PI/2);

        // Altera o valor das coordenadas x e y da hitbox de acordo com as translações
        entityList[0].alteredHitbox[i].x += entityList[0].centro.x;
        entityList[0].alteredHitbox[i].y += entityList[0].centro.y;
    }
}

void movimentaNPC(int e)
{
    // Se o NPC andar na horizontal, executa os comandos
    if(entityList[e].ladoHorizontal != 0) 
    {
        // Se a entidade estiver programada para andar para a esquerda, diminui o valor X do ponto central
        if(entityList[e].ladoHorizontal == -1)
            entityList[e].centro.x -= entityList[e].x_move;

        // Se a entidade estiver programada para andar para a direita, aumenta o valor X do ponto central
        if(entityList[e].ladoHorizontal ==  1)
            entityList[e].centro.x += entityList[e].x_move;

        // Se o extremo esquerdo da entidade ultrapassar o limite esquero da caixa de visualização,
        // programa a entidade para andar para a direita. 
        if(entityList[e].centro.x < -100 * aspectRatio - entityList[e].x_min)
        {
            entityList[e].ladoHorizontal = 1;
            entityList[e].centro.x += entityList[e].x_move;
        }

        // Se o extremo direito da entidade ultrapassar o limite direito da caixa de visualização,
        // programa a entidade para andar para a esquerda. 
        if(entityList[e].centro.x > 100 * aspectRatio - entityList[e].x_max)
        {
            entityList[e].ladoHorizontal = -1;
            entityList[e].centro.x -= entityList[e].x_move;
        }
    }

    // Se o NPC andar na vetical, executa os comandos
    if(entityList[e].ladoVertical != 0)
    {
        // Se a entidade estiver programada para andar para baixo, diminui o valor Y do ponto central.
        if(entityList[e].ladoVertical == -1)
            entityList[e].centro.y -= entityList[e].y_move;

        // Se a entidade estiver programada para andar para cima, aumenta o valor Y do ponto central.
        if(entityList[e].ladoVertical ==  1)
            entityList[e].centro.y += entityList[e].y_move;

        // Se o extremo esquerdo da entidade ultrapassar o limite inferior da caixa de visualização,
        // programa a entidade para andar para cima. 
        if(entityList[e].centro.y + entityList[e].y_min < -100 )
        {
            entityList[e].ladoVertical = 1;
            entityList[e].centro.y += entityList[e].y_move;
        }

        // Se o extremo esquerdo da entidade ultrapassar o limite superior da caixa de visualização,
        // programa a entidade para andar para baixo. 
        if(entityList[e].centro.y + entityList[e].y_max > 100 )
        {
            entityList[e].ladoVertical = -1;
            entityList[e].centro.y -= entityList[e].y_move;
        }
    }

}

void movimentaShotsHitbox(entidade* e)
{
    for(int i=0; i<4; i++)
    {
        // Usadas no calculo dos valores de x' e y' ao rotacionar a entidade
        double x = e->hitbox[i].x;
        double y = e->hitbox[i].y;

        // Altera o valor das coordenadas x e y da hitbox de acordo com as rotações
        e->alteredHitbox[i].x = x * cos(aux_angle + M_PI/2) - y * sin(aux_angle + M_PI/2);
        e->alteredHitbox[i].y = x * sin(aux_angle + M_PI/2) + y * cos(aux_angle + M_PI/2);

        // Altera o valor das coordenadas x e y da hitbox de acordo com as translações
        e->alteredHitbox[i].x += e->centro.x;
        e->alteredHitbox[i].y += e->centro.y;
    }     
}

void movimentaShots()
{
    if(dentroTela(&entityList[0]))
    {
        for(int e=0; e<shotsList.size(); e++)
            if(!shotsList[e].continuar) // se o tiro não tiver sido liberado, o player ainda controla sua posição
            {
                shotsList[e].angulo = entityList[0].angulo;
                //shotsList[e].angulo += (on_off[4] - on_off[5]) * shotsList[e].angularSpeed;

                double aux_angle = grausParaRadianos(shotsList[e].angulo);

                // Aumenta a angulação da entidade com '+' e diminui com '-'
                
    /*
                shotsList[e].centro.x = 20 * cos(aux_angle + M_PI/4) + entityList[0].centro.x;
                shotsList[e].centro.y = 20 * sin(aux_angle + M_PI/4) + entityList[0].centro.y;
    */
            
                // Movimenta para cima e para baixo com 'w' e 's' ou 'cima' e 'baixo'

                shotsList[e].centro.x += (on_off[0] - on_off[1]) * cos(aux_angle) * shotsList[e].vetorialSpeed;
                shotsList[e].centro.y += (on_off[0] - on_off[1]) * sin(aux_angle) * shotsList[e].vetorialSpeed;

                // Movimenta para direita e esquerda com 'd' e 'a' ou '->' e '<-'
                shotsList[e].centro.x += (on_off[2] - on_off[3]) * cos(aux_angle - M_PI/2) * shotsList[e].vetorialSpeed;
                shotsList[e].centro.y += (on_off[2] - on_off[3]) * sin(aux_angle - M_PI/2) * shotsList[e].vetorialSpeed;
            
                // Variáveis auxiliares
                double x,y;

                movimentaShotsHitbox(&shotsList[e]);
            }
    }
}

//TIRO "TELEGUIADO"

void atirar()
{
    for(int e=0; e<shotsList.size(); e++)
    {
        if(shotsList[e].continuar == 0)
            aux_angle = grausParaRadianos(entityList[0].angulo);

        if(on_off[6] || shotsList[e].continuar == 1)
        {
            shotsList[e].continuar = 1;
            shotsList[e].centro.x += cos(aux_angle) * shotsList[e].bulletSpeed;
            shotsList[e].centro.y += sin(aux_angle) * shotsList[e].bulletSpeed;

            movimentaShotsHitbox(&shotsList[e]);
        }
    }
}


// TIRO TEORICAMENTE NORMAL
 /*
void atirar()
{
    double aux_angle;

    for(int e=0; e<shotsList.size(); e++)
    {        
        if(shotsList[e].continuar == 0)
            aux_angle = grausParaRadianos(entityList[0].angulo);
        
        printf("Continuar: %d | Angulo: %.3f\n",shotsList[e].continuar,radianoParaGraus( aux_angle));
        printf("Cx: %.3f | Cy: %.3f\n",shotsList[e].centro.x,shotsList[e].centro.y);

         if(on_off[6] || shotsList[e].continuar == 1)
        {
            shotsList[e].continuar = 1;
            //shotsList[e].centro.x += cos(aux_angle) * shotsList[e].bulletSpeed;
            shotsList[e].centro.y += sin(aux_angle) * shotsList[e].bulletSpeed;
        }
    }
}
*/

//TIRO "TELEGUIADO"
/*
void atirar()
{
    double aux_angle = grausParaRadianos(entityList[0].angulo);

    for(int e=0; e<shotsList.size(); e++)
    {
        if(!shotsList[e].continuar)
            aux_angle = grausParaRadianos(entityList[0].angulo);

        if(on_off[6] || shotsList[e].continuar)
        {
            shotsList[e].continuar = 1;
            shotsList[e].centro.x += cos(aux_angle) * shotsList[e].bulletSpeed;
            shotsList[e].centro.y += sin(aux_angle) * shotsList[e].bulletSpeed;  
        }
    }
}
*/