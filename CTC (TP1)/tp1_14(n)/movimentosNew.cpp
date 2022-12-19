#include "colisoes.h"
#include "movimentosNew.h"

#define radianoParaGraus(radianos) (radianos * (180.0 / M_PI))
#define grausParaRadianos(graus) ((graus * M_PI) / 180.0)

using namespace std;

int posicao1, posicao2;

//angulos TEM que ser variaveis globais pra preservar seu valor como constante, senao fica redeclarando

// angulo que orienta rotação do tiro
double aux_angle; 

// angulo que orienta rotação do jogador
double aux_angle_player;

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


void generalHitboxMovement(entidade* e, double seuAngulo)
{
    for(int i=0; i<4; i++)
    {
        // Usadas no calculo dos valores de x' e y' ao rotacionar a entidade
        double x = e->hitbox[i].x;
        double y = e->hitbox[i].y;

        // Altera o valor das coordenadas x e y da hitbox de acordo com as rotações
        e->alteredHitbox[i].x = x * cos(seuAngulo + M_PI/2) - y * sin(seuAngulo + M_PI/2);
        e->alteredHitbox[i].y = x * sin(seuAngulo + M_PI/2) + y * cos(seuAngulo + M_PI/2);

        // Altera o valor das coordenadas x e y da hitbox de acordo com as translações
        e->alteredHitbox[i].x += e->centro.x;
        e->alteredHitbox[i].y += e->centro.y;
    }  
}



void playerModelMovement()
{
        // Aumenta a angulação da entidade com '+' e diminui com '-'
    entityList[0].angulo += (on_off[4] - on_off[5]) * entityList[0].angularSpeed;

    // Movimenta para cima e para baixo com 'w' e 's' ou 'cima' e 'baixo'
    entityList[0].centro.x += (on_off[0] - on_off[1]) * cos(aux_angle_player) * entityList[0].vetorialSpeed;
    entityList[0].centro.y += (on_off[0] - on_off[1]) * sin(aux_angle_player) * entityList[0].vetorialSpeed;

    // Movimenta para direita e esquerda com 'd' e 'a' ou '->' e '<-'
    entityList[0].centro.x += (on_off[2] - on_off[3]) * cos(aux_angle_player - M_PI/2) * entityList[0].vetorialSpeed;
    entityList[0].centro.y += (on_off[2] - on_off[3]) * sin(aux_angle_player - M_PI/2) * entityList[0].vetorialSpeed;
}

void playerMovement()
{
    aux_angle_player = grausParaRadianos(entityList[0].angulo);

    playerModelMovement();
    generalHitboxMovement(&entityList[0],aux_angle_player);
}



void enemyModelMovement(entidade* e)
{
    // Se o NPC andar na horizontal, executa os comandos
    if(e->ladoHorizontal != 0) 
    {
        // Se a entidade estiver programada para andar para a esquerda, diminui o valor X do ponto central
        if(e->ladoHorizontal == -1)
            e->centro.x -= e->x_move;

        // Se a entidade estiver programada para andar para a direita, aumenta o valor X do ponto central
        if(e->ladoHorizontal ==  1)
            e->centro.x += e->x_move;

        // Se o extremo esquerdo da entidade ultrapassar o limite esquero da caixa de visualização,
        // programa a entidade para andar para a direita. 
        if(e->centro.x < -100 * aspectRatio - e->x_min)
        {
            e->ladoHorizontal = 1;
            e->centro.x += e->x_move;
        }

        // Se o extremo direito da entidade ultrapassar o limite direito da caixa de visualização,
        // programa a entidade para andar para a esquerda. 
        if(e->centro.x > 100 * aspectRatio - e->x_max)
        {
            e->ladoHorizontal = -1;
            e->centro.x -= e->x_move;
        }
    }

    // Se o NPC andar na vetical, executa os comandos
    if(e->ladoVertical != 0)
    {
        // Se a entidade estiver programada para andar para baixo, diminui o valor Y do ponto central.
        if(e->ladoVertical == -1)
            e->centro.y -= e->y_move;

        // Se a entidade estiver programada para andar para cima, aumenta o valor Y do ponto central.
        if(e->ladoVertical ==  1)
            e->centro.y += e->y_move;

        // Se o extremo esquerdo da entidade ultrapassar o limite inferior da caixa de visualização,
        // programa a entidade para andar para cima. 
        if(e->centro.y + e->y_min < -100 )
        {
            e->ladoVertical = 1;
            e->centro.y += e->y_move;
        }

        // Se o extremo esquerdo da entidade ultrapassar o limite superior da caixa de visualização,
        // programa a entidade para andar para baixo. 
        if(e->centro.y + e->y_max > 100 )
        {
            e->ladoVertical = -1;
            e->centro.y -= e->y_move;
        }
    }
}

void enemyHitboxMovement(entidade* e)
{
    if(e->onScreen)
    {
        for(int i=0; i<4; i++)
        {
            e->alteredHitbox[i].x = e->hitbox[i].x + e->centro.x;
            e->alteredHitbox[i].y = e->hitbox[i].y + e->centro.y;
        }
    }
}

void enemyGeneralMovement()
{
    for(int i=1; i < entityList.size(); i++)
    {
        enemyModelMovement(&entityList[i]);
        enemyHitboxMovement(&entityList[i]);  
    }
}



void colocaShotDentroVector()
{
    listaStructsShots();
}

void posicionaShotComPlayer()
{
    aux_angle = grausParaRadianos(entityList[0].angulo);

    posicao1 = shotsList.size()-2; // posicao primeiro tiro
    posicao2 = shotsList.size()-1; // posicao segundo tiro

    //printf("P1: %d, P2: %d\n",posicao1,posicao2);

    shotsList[posicao1].centro.x = 12 * cos(aux_angle + M_PI/6) + entityList[0].centro.x;
    shotsList[posicao1].centro.y = 12 * sin(aux_angle + M_PI/6) + entityList[0].centro.y; 

    shotsList[posicao2].centro.x = 12 * cos(aux_angle - M_PI/6) + entityList[0].centro.x;
    shotsList[posicao2].centro.y = 12 * sin(aux_angle - M_PI/6) + entityList[0].centro.y;

}

void shotsAloneMovement(int e)
{
    shotsList[e].continuar = 1;
    shotsList[e].centro.x += cos(aux_angle) * shotsList[e].bulletSpeed;
    shotsList[e].centro.y += sin(aux_angle) * shotsList[e].bulletSpeed;
}

void retiraShotCasoColisao()
{
    for(int i=0; i < shotsList.size(); i++){
        shotHitbox(i); 
        
        for(int j=1; j < entityList.size(); j++){
            
            if(colisaoGeral(&shotsList[i],&entityList[j])) // se colidir tiro inimigo, tiro volta 
            {
                entityList[j].onScreen = GL_FALSE; // não desenha o personagem
                printf("Colidiu com %d\n",j);
                entityList.erase(entityList.begin() + i);

                //posicaoInicialShots();
                //removeHitbox(&entityList[j]);   
            }

            else if(!dentroTela(&shotsList[i])) // se o tiro sair da tela, ele volta para a posição inicial
            {
                printf("Saiu da tela\n");
                entityList.erase(entityList.begin() + i);

                //posicaoInicialShots();
                //removeHitbox(&entityList[j]);
            }               
        }
    }
}

void shotsGeneralMovement()
{
    /*
    if(on_off[6])
    {
        posicionaShotComPlayer();
    }*/
    

    for(int i=0; i<shotsList.size(); i++)
    {
        // percorre a lista e faz todos os tiros se movimentarem
        shotsAloneMovement(i);
        generalHitboxMovement(&shotsList[i],aux_angle);
        retiraShotCasoColisao();
    }

}

//TIRO "TELEGUIADO" (a hitbox não está acompanhando)
/*glutSetKeyRepeat+
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