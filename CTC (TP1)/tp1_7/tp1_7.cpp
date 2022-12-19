//FUNCIONA TUDO menos a rotação dos tiros ao redor do player

#include "parametros.h"
#include "desenhos.h"
#include "inicializa.h"
#include "movimentos.h"
#include "colisoes.h"

using namespace std;

#define radianoParaGraus(radianos) (radianos * (180.0 / M_PI))
#define grausParaRadianos(graus) ((graus * M_PI) / 180.0)

// Callback da displayFunction
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if(endGame != 0)
    {
        if(endGame == 2)
        {
            char s[20] = {"Voce Venceu!!"};
            glColor3f(0,0,0);
            escreveTexto(GLUT_BITMAP_HELVETICA_18, s, 0, 0);
        }

        if(endGame == 1)
        {
            char s[20] = {"Game Over"};
            glColor3f(0,0,0);
            escreveTexto(GLUT_BITMAP_HELVETICA_18, s, 0, 0);
        }
    }
    // Endgame = 1 significa que ocorreu colisão


    // Se não tiver acabado o programa, executa normalmente
    else
    {
        // Desenha todas as imagens
        for(int i=0; i<entityList.size(); i++){
            if(entityList[i].onScreen)
            {   
                glPushMatrix();
                    glTranslatef(entityList[i].centro.x, entityList[i].centro.y, 0);
                    if(i==0)
                        glRotatef(entityList[0].angulo-90,0,0,1);
                    glScalef(entityList[i].resize.x,entityList[i].resize.y,1);
                    glCallList(entityList[i].model);
                glPopMatrix();
            }
        }

        for(int i=0; i<shotsList.size(); i++){
            if(shotsList[i].onScreen)
            {   
                glPushMatrix();
                    glTranslatef(shotsList[i].centro.x, shotsList[i].centro.y, 0);
                    glRotatef(shotsList[i].angulo-90,0,0,1);
                    glScalef(shotsList[i].resize.x,shotsList[i].resize.y,1);
                    glCallList(shotsList[i].model);
                glPopMatrix();
            }
        }

        glColor3ub(255,20,22);

        // Controla o desenho das hitboxes 

        for(int i=0, j=1; i<4; i++,j=(i+1)%4)
        {   
            if(hitBox)        // hitBox = true: desenha hitboxes
            {
                glBegin(GL_LINES);
                    for(int e=0; e < entityList.size(); e++){
                        if(entityList[e].drawHitbox)
                        {
                            glVertex2f(entityList[e].alteredHitbox[i].x, entityList[e].alteredHitbox[i].y);
                            glVertex2f(entityList[e].alteredHitbox[j].x, entityList[e].alteredHitbox[j].y);
                        }
                            
                    } 
                glEnd();

                glBegin(GL_LINES);
                    for(int e=0; e < shotsList.size(); e++){
                        if(shotsList[e].drawHitbox)
                        {
                            glVertex2f(shotsList[e].alteredHitbox[i].x, shotsList[e].alteredHitbox[i].y);
                            glVertex2f(shotsList[e].alteredHitbox[j].x, shotsList[e].alteredHitbox[j].y);
                        }
                    } 
                glEnd();
            }
        } 
    }

    //coloca esses desenhos na tela
    glutSwapBuffers();
}

// Callback da reshapeFunction
void reshape(int w, int h)
{
    aspectRatio = (float)w / (float)h;
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-100 * aspectRatio, 100* aspectRatio, -100, 100, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}                               

// Callback do evento de pressionamento de tecla (sem ser setas)
void keyboard(unsigned char key, int x, int y)
{
    /*Dependendo da tecla pressionada, um vetor sinaliza
    0 mostrando que uma tecla foi desligada, ou
    1 mostrando que uma tecla foi ligada*/
    switch (key)
    {
        case 27: 
            exit(0); 
            break;
            
        case 'w': //Anda para frente
        case 'W':
            if(on_off[0] == 1)
                on_off[0] = 0;
            else on_off[0] = 1;
            break;

        case 's': //Anda para trás
        case 'S':
            if(on_off[1] == 1)
                on_off[1] = 0;
            else on_off[1] = 1;
            break;

        case 'd': // Anda para direita
        case 'D':
            if(on_off[2] == 1)
                on_off[2] = 0;
            else on_off[2] = 1;
            break;

        case 'a': // Anda para esquerda
        case 'A':
            if(on_off[3] == 1)
                on_off[3] = 0;
            else on_off[3] = 1;
            break;

        case '-': // Rotaciona sentido anti-hotário
        case '_':
            if(on_off[4] == 1)
                on_off[4] = 0;
            else on_off[4] = 1;
            break;
        
        case '+': // Rotaciona sentido horário
        case '=':
            if(on_off[5] == 1)
                on_off[5] = 0;
            else on_off[5] = 1;
            break;

        case ' ': // Atira 
            if(on_off[6] == 0)
                on_off[6] = 1;
            else on_off[6] = 0;
            break;
    }
}

// Callback do evento de pressionamento de tecla (setas)
void setas(int key, int x, int y)
{
    switch (key){
        case 27: 
            exit(0); 
            break;
            
        case GLUT_KEY_UP: 
            if(on_off[0] == 1)
                on_off[0] = 0;
            else on_off[0] = 1;
            break;

        case GLUT_KEY_DOWN: 
            if(on_off[1] == 1)
                on_off[1] = 0;
            else on_off[1] = 1;
            break;

        case GLUT_KEY_RIGHT:
            if(on_off[2] == 1)
                on_off[2] = 0;
            else on_off[2] = 1;
            break;

        case  GLUT_KEY_LEFT:
            if(on_off[3] == 1)
                on_off[3] = 0;
            else on_off[3] = 1;
            break;
    }
}

// Callback da timerFunction.
void timer(int t)
{
    // Se ocorrer colisao, determina os valores X e Y de todas as entidades para seus valores default,
    // com o intuito de reiniciar a animação.

    confereEndGame();
    
    // Movimenta o jogador.
    playerMovement();
    movimentaShots();
    atirar();

    // Confere se ainda existem inimigos vivos
    if(voceVenceu())
    {   endGame = 2;
        glutTimerFunc(2000, timer, 16);
    }

    // Gerencia o game over por colisao entre jogador e inimigo
    for(int i=1; i < entityList.size(); i++)
    {
        enemyMovement(&entityList[i]);
        enemyHitboxMovement(&entityList[i]);   
    }



    for(int i=1; i<entityList.size(); i++)
    {
        // Se ocorrer colisao entre o player e um dos 5 NPCs, começa o proceso def reiniciar a animação
        if(colisaoGeral(&entityList[0],&entityList[i]))
        {
            printf("Game over com %d\n",i);
            endGame = 1;
            glutTimerFunc(2000, timer, 16); // Se ocorrer a colisão, o período da timer é momentaneamente definido para
                                            // 2 segundos, para a mensagem de "Game Over" aparecer na tela durante 2 segundos.
        }
    }

    // Gerencia as colisões netre shot e inimigo
    shotsReposiotioning();

    // Função que garante que player fique na tela.
    dentroTela(&entityList[0]);

    // Na proxima iteração da mainloop, a display() deve ser chamada.
    glutPostRedisplay();

    // Se a animação não tiver acabado, a timerfunc tem seu timer preservado.
    if(!endGame)
        glutTimerFunc(t, timer, t);
}

// Função main
int main(int argc, char **argv)
{
    // Prepara a tela
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Lista 2");

    // Configura o valor inicial de algumas variáveis de estado
    inicializar();

    // Registra callbacks para alguns eventos
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard);
    glutSpecialFunc(setas);
    glutSpecialUpFunc(setas);
    glutTimerFunc(16, timer, 16);

    glutMainLoop();
    return 0;
}