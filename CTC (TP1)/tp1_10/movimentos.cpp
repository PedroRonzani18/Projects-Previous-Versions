#include "colisoes.h"
#include "movimentos.h"

#define radianoParaGraus(radianos) (radianos * (180.0 / M_PI))
#define grausParaRadianos(graus) ((graus * M_PI) / 180.0)

using namespace std;

double aux_angle; //TEM que ser variavel global pra preservar seu valor como constante
//senao fica redeclarando

int contador = 0;

int dentroTela(Entity* e)
{
    // Se um dos extremos de cima, baixo, esqueda, direita ultrapassar seu respectivo limite da
    // caixa de visualização, sua coordenada X e/ou Y é programada para voltar para o limite,
    // fazendo que ele nunca saia da caixa de visualização.

    if(e->getCentroX() + e->getY_Max() > 100){
        e->setCentroY(100 - e->getY_Max());
        return 0;
    }

    if(e->getCentroY() + e->getY_Min() < -100 ){
        e->setCentroY(-100 - e->getY_Min());
        return 0;
    }

    if(e->getCentroX() + e->getX_Max() > 100 * aspectRatio){
        e->setCentroX(100 * aspectRatio - e->getX_Max());
        return 0;
    }
    
    if(e->getCentroX() + e->getX_Min() < -100 * aspectRatio){
        e->setCentroX(-100 * aspectRatio - e->getX_Min());
        return 0;
    }

/*
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
    }*/

    return 1;
}

//PAREI AQUI
void playerMovement()
{
    double aux_angle = grausParaRadianos(entityList[0].getAngulo());

    // Aumenta a angulação da entidade com '+' e diminui com '-'
    entityList[0].setAngulo(entityList[0].getAngulo() + (on_off[4] - on_off[5]) * entityList[0].getAngularSpeed());

    // Movimenta para cima e para baixo com 'w' e 's' ou 'cima' e 'baixo'
    entityList[0].setCentroX(entityList[0].getCentroX() + (on_off[0] - on_off[1]) * cos(aux_angle) * entityList[0].getVetorialSpeed());
    entityList[0].setCentroY(entityList[0].getCentroY() + (on_off[0] - on_off[1]) * sin(aux_angle) * entityList[0].getVetorialSpeed());

    // Movimenta para direita e esquerda com 'd' e 'a' ou '->' e '<-'
    entityList[0].setCentroX(entityList[0].getCentroX() + (on_off[2] - on_off[3]) * cos(aux_angle - M_PI/2) * entityList[0].getVetorialSpeed());
    entityList[0].setCentroY(entityList[0].getCentroY() + (on_off[2] - on_off[3]) * sin(aux_angle - M_PI/2) * entityList[0].getVetorialSpeed());

    for(int i=0; i<4; i++)
    {
        // Variáveis auxiliares Usadas no calculo dos valores de x' e y' ao rotacionar a entidade
        double x = entityList[0].getHitbox()[i].x;
        double y = entityList[0].getHitbox()[i].y;

        vertice* auxHitbox;

        // Altera o valor das coordenadas x e y da hitbox de acordo com as rotações
        auxHitbox[i].x = x * cos(aux_angle + M_PI/2) - y * sin(aux_angle + M_PI/2);
        auxHitbox[i].y = x * sin(aux_angle + M_PI/2) + y * cos(aux_angle + M_PI/2);

        // Altera o valor das coordenadas x e y da hitbox de acordo com as translações
        auxHitbox[i].x += entityList[0].getCentroX();
        auxHitbox[i].y += entityList[0].getCentroX();

        // usa a variável auxiliar no set
        entityList[0].setAlteredHitbox(auxHitbox);
    }
/*
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
    }*/
}

void enemyMovement(Entity* e)
{
    // Se o NPC andar na horizontal, executa os comandos
    if(e->getLadoHorizontal() != 0)
    {
        // Se a entidade estiver programada para andar para a esquerda, diminui o valor X do ponto central
        if(e->getLadoHorizontal() == -1)
            e->setCentroX(e->getCentroX() - e->getX_Move());

        // Se a entidade estiver programada para andar para a direita, aumenta o valor X do ponto central
        if(e->getLadoHorizontal() == 1)
            e->setCentroX(e->getCentroX() + e->getX_Move());

        // Se o extremo esquerdo da entidade ultrapassar o limite esquero da caixa de visualização,
        // programa a entidade para andar para a direita. 
        if(e->getCentroX() < -100 * aspectRatio - e->getX_Min())
        {
            e->setLadoHorizontal(1);
            e->setCentroX(e->getCentroX() + e->getX_Move());
        }

        // Se o extremo direito da entidade ultrapassar o limite direito da caixa de visualização,
        // programa a entidade para andar para a esquerda. 
        if(e->getCentroX() > 100 * aspectRatio - e->getX_Max())
        {
            e->setLadoHorizontal(-1);
            e->setCentroX(e->getCentroX() - e->getX_Move());
        }
    }

    // Se o NPC andar na vetical, executa os comandos
    if(e->getLadoVertical() != 0)
    {
        // Se a entidade estiver programada para andar para baixo, diminui o valor Y do ponto central.
        if(e->getLadoVertical() == -1)
            e->setCentroY(e->getCentroY() - e->getY_Move());

        // Se a entidade estiver programada para andar para cima, aumenta o valor Y do ponto central.
        if(e->getLadoVertical() ==  1)
            e->setCentroY(e->getCentroY() + e->getY_Move());

        // Se o extremo esquerdo da entidade ultrapassar o limite inferior da caixa de visualização,
        // programa a entidade para andar para cima. 
        if(e->getCentroY() + e->getY_Min() < -100)
        {
            e->setLadoVertical(1);
            e->setCentroY(e->getCentroY() + e->getY_Move());
        }

        // Se o extremo esquerdo da entidade ultrapassar o limite superior da caixa de visualização,
        // programa a entidade para andar para baixo.
        if(e->getCentroY() + e->getY_Max() > 100)
        {
            e->setLadoVertical(-1);
            e->setCentroY(e->getCentroY() - e->getY_Move());
        }
    }
}

void enemyHitboxMovement(Entity* e)
{
    if(e->getOnScreen())
    {
        for(int i=0; i<4; i++)
        {
            vertice* auxHitbox;

            auxHitbox[i].x = e->getHitbox()[i].x + e->getCentroX();
            auxHitbox[i].y = e->getHitbox()[i].y + e->getCentroY();

            e->setAlteredHitbox(auxHitbox);
        }
    }
}

void shotsHitboxMovement(Entity* e)
{
    for(int i=0; i<4; i++)
    {
        // Variáveis auxiliares Usadas no calculo dos valores de x' e y' ao rotacionar a entidade
        double x = e->getHitbox()[i].x;
        double y = e->getHitbox()[i].y;

        vertice* auxHitbox;

        // Altera o valor das coordenadas x e y da hitbox de acordo com as rotações
        auxHitbox[i].x = x * cos(aux_angle + M_PI/2) - y * sin(aux_angle + M_PI/2);
        auxHitbox[i].y = x * sin(aux_angle + M_PI/2) + y * cos(aux_angle + M_PI/2);

        // Altera o valor das coordenadas x e y da hitbox de acordo com as translações
        auxHitbox[i].x += entityList[0].getCentroX();
        auxHitbox[i].y += entityList[0].getCentroX();

        // usa a variável auxiliar no set
        e->setAlteredHitbox(auxHitbox);
    }
/*
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
    }     */
}

void shotsReposiotioning()
{
    for(int i=0; i < shotsList.size(); i++){
        shotHitbox(i);
        
        for(int j=1; j < entityList.size(); j++){
            
            if(colisaoGeral(&shotsList[i],&entityList[j])) // se colidir tiro inimigo, tiro volta 
            {
                entityList[j].setOnScreen(GL_FALSE); // não desenha o personagem
                printf("Colidiu com %d\n",j);
                posicaoInicialShots();
                removeHitbox(&entityList[j]);   
            }

            else if(!dentroTela(&shotsList[i])) // se o tiro sair da tela, ele volta para a posição inicial
            {
                printf("Saiu da tela\n");
                posicaoInicialShots();
                removeHitbox(&entityList[j]);
            }               
        }
    }
}

void movimentaShots()
{
    contador++;

    printf("contador: %d\n",contador);
    if(dentroTela(&entityList[0]))
    {
        for(int e=0; e<shotsList.size(); e++){
            printf("1) Numero %d: ",e);getchar();

            printf("TESTE %d\n",shotsList[0].model);
            printf("TESTE %d\n",shotsList[1].model);
            printf("xxx %d\n",shotsList[e].continuar);
/*
            printf("Valor 0: %d\n",shotsList[0].continuar);
            printf("Valor 1: %d\n",shotsList[1].continuar);
            printf("Valor 2: %d\n",shotsList[2].continuar);
            printf("Valor 3: %d\n",shotsList[3].continuar);*/

            if(shotsList[e].continuar == 0) // se o tiro não tiver sido liberado, o player ainda controla sua posição
            {
                shotsList[e].setAngulo(entityList[0].getAngulo());
                //shotsList[e].angulo += (on_off[4] - on_off[5]) * shotsList[e].angularSpeed;

                double aux_angle = grausParaRadianos(shotsList[e].getAngulo());

                if(e==0){
                    shotsList[e].setCentroX(12 * cos(aux_angle + M_PI/6) + entityList[0].getCentroX());
                    shotsList[e].setCentroY(12 * sin(aux_angle + M_PI/6) + entityList[0].getCentroY()); 
                }

                if(e==1){
                    shotsList[e].setCentroX(12 * cos(aux_angle - M_PI/6) + entityList[0].getCentroX());
                    shotsList[e].setCentroY(12 * sin(aux_angle - M_PI/6) + entityList[0].getCentroY());
                }

                // Variáveis auxiliares
                double x,y;

                //move a hitbox do tiro junto do tiro
                shotsHitboxMovement(&shotsList[e]);
            }
        }
    }
}

//TIRO RETO
void atirar()
{
    for(int e=0; e<shotsList.size(); e++)
    {
        printf("2) Numero %d: ",e);
        printf("%d\n",entityList[e].continuar);

        if(shotsList[e].continuar == 0)
            aux_angle = grausParaRadianos(entityList[0].getAngulo());

        if(on_off[6] || shotsList[e].continuar == 1)
        {
            shotsList[e].setContinuar(1);
            shotsList[e].setCentroX(shotsList[e].getCentroX() + cos(aux_angle) * shotsList[e].getBulletSpeed());
            shotsList[e].setCentroY(shotsList[e].getCentroY() + sin(aux_angle) * shotsList[e].getBulletSpeed());

            shotsHitboxMovement(&shotsList[e]);
        }
    }
}

//TIRO "TELEGUIADO" (a hitbox não está acompanhando)
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