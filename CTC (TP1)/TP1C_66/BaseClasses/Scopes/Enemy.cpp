#include "../Header/Enemy.h"
#include <stdio.h>
#include "../../GeneralFiles/Header/globalParameters.h"
#include <time.h>

#define radianoParaGraus(radianos) (radianos * (180.0 / M_PI))
#define grausParaRadianos(graus) ((graus * M_PI) / 180.0)

Enemy::Enemy(int type) : MovableEntity()
{
    srand(time(0));
    this->type = type;
    this->onScreen = GL_TRUE;

    switch (this->type)
    {
    case 0: // kamikaze
        this->dropPercentage = 50;
        this->killValue = 10;
        this->angle = 0;
        this->angularSpeed = 0;
        this->currentProjectile = Projectile(3);
        this->typeMove = 0;
        this->typeTiroManager = 1; // determina tipo do tiro
        this->numberOfShots = 0;
        this->hp = 5;
        this->onscreenTestable = GL_FALSE;
        this->continueMove = 0;
        this->fireRatePeriod = 0;
        this->setDisplayListModel(textures[11]);
        this->setMax(20, 20);
        this->setMin(-20, -20);
        this->setVelocity(1, 1);
        this->setResize(0.5);
        break;

    case 1: // sniper
        this->dropPercentage = 50;
        this->killValue = 10;
        this->angle = 180;
        this->angularSpeed = 0;
        this->currentProjectile = Projectile(3);
        this->typeTiroManager = 1;
        this->typeMove = 0;
        this->numberOfShots = 0;
        this->hp = 5;
        this->onscreenTestable = GL_FALSE;
        this->continueMove = 0;
        this->fireRatePeriod = 0;
        this->setDisplayListModel(textures[13]);
        this->setMax(15, 15);
        this->setMin(-15, -15);
        this->setVelocity(0.5, 1);
        this->setResize(0.5);
        break;

    case 2: // nave que atira missel que segue
        this->dropPercentage = 50;
        this->killValue = 10;
        this->angle = 180;
        this->angularSpeed = 0;
        this->currentProjectile = Projectile(5);
        this->typeMove = 4;
        this->typeTiroManager = 1;
        this->numberOfShots = 0;
        this->hp = 5;
        this->onscreenTestable = GL_FALSE;
        this->continueMove = 0;
        this->fireRatePeriod = 0;
        this->setDisplayListModel(textures[27]);
        this->setMax(15, 15);
        this->setMin(-15, -15);
        this->setVelocity(0.5, 1);
        this->setResize(0.5);
        break;

    case 3: // nave raio laser vermelho pequena 1/2
        this->dropPercentage = 50;
        this->killValue = 10;
        this->angle = 180;
        this->angularSpeed = 0;
        this->currentProjectile = Projectile(3);
        this->typeTiroManager = 1;
        this->numberOfShots = 0;
        this->hp = 5;
        this->onscreenTestable = GL_FALSE;
        this->typeMove = 4;
        this->continueMove = 0;
        this->fireRatePeriod = 0;
        this->setDisplayListModel(textures[28]);
        this->setMax(15, 15);
        this->setMin(-15, -15);
        this->setVelocity(0.5, 1);
        this->setResize(0.5);
        break;

    case 4: // tank
        this->dropPercentage = 50;
        this->killValue = 10;
        this->angle = 180;
        this->angularSpeed = 0;
        this->currentProjectile = Projectile(4);
        this->typeTiroManager = 1;
        this->numberOfShots = 0;
        this->hp = 5;
        this->onscreenTestable = GL_FALSE;
        this->typeMove = 4;
        this->continueMove = 0;
        this->fireRatePeriod = 0;
        this->setDisplayListModel(textures[29]);
        this->setMax(15, 15);
        this->setMin(-15, -15);
        this->setVelocity(0.5, 1);
        this->setResize(0.5);
        break;

    case 5: // torreta que estará sobre o png de asteroide
        this->dropPercentage = 50;
        this->killValue = 10;
        this->angle = 0;
        this->angularSpeed = 0;
        this->currentProjectile = Projectile(3);
        this->typeTiroManager = 1; /**/
        this->numberOfShots = 0;   // inutilizzadp
        this->hp = 5;
        this->onscreenTestable = GL_FALSE;
        this->typeMove = 4; /**/
        this->continueMove = 0;
        this->fireRatePeriod = 0; // tem que ser 0
        this->setDisplayListModel(textures[33]);
        this->setMax(15, 15);
        this->setMin(-15, -15);
        this->setVelocity(0.5, 1); // deixar padrao no cosntrutor e talvez mmudar na wave
        this->setResize(0.5);
        break;

    case 6: // asteroide
        this->dropPercentage = 50;
        this->killValue = 10;
        this->angle = 0;
        this->angularSpeed = 0;
        this->currentProjectile = Projectile(3);
        this->typeTiroManager = 3;
        this->numberOfShots = 0;
        this->hp = 5;
        this->onscreenTestable = GL_FALSE;
        this->typeMove = 4;
        this->continueMove = 0;
        this->fireRatePeriod = 0;
        this->setDisplayListModel(textures[32]);
        this->setMax(15, 15);
        this->setMin(-15, -15);
        this->setVelocity(0.5, 1);
        this->setResize(0.5);
        break;
    }
    this->setHitbox();
    this->setMidPoint();
}

Projectile Enemy::createProject(Projectile *auxP, double angle)
{
    auxP->setMidPoint(this->max.getX() * cos(grausParaRadianos(this->angle) + angle) + this->midPoint.getX(),
                      this->max.getY() * sin(grausParaRadianos(this->angle) + angle) + this->midPoint.getY());
    return *auxP;
}

void Enemy::parabolicMoveTemplate(double a, double b, double c)
{
    this->midPoint.setY(this->midPoint.getY() - this->velocity.getY());
    this->midPoint.setX(a * pow(this->midPoint.getY(), 2) + b * this->midPoint.getY() + c);
}

void Enemy::senoidMoveTemplate(double a, double b, double c, double d)
{
    this->midPoint.setY(this->midPoint.getY() - this->velocity.getY());
    this->midPoint.setX(a + b * sin(c * this->midPoint.getY() + d));
}

void Enemy::kamikazeMove()
{
    if (continueMove < 150)
    {
        double angle = atan2(this->followPoint.getY() - this->midPoint.getY(),
                             this->followPoint.getX() - this->midPoint.getX());

        this->angle = radianoParaGraus(angle) - 90;

        this->midPoint.setX(this->midPoint.getX() + cos(angle) * this->velocity.getX());
        this->midPoint.setY(this->midPoint.getY() + sin(angle) * this->velocity.getY());

        this->continueMove++;
    }
    else
    {
        this->midPoint.setX(this->midPoint.getX() + cos(grausParaRadianos(this->angle) + M_PI / 2) * this->velocity.getX() * 2);
        this->midPoint.setY(this->midPoint.getY() + sin(grausParaRadianos(this->angle) + M_PI / 2) * this->velocity.getY() * 2);
    }

    // printf("%d\n", this->continueMove);
}

void Enemy::aim() // mira  a frente do inimigo na direção do player
{
    double angle = atan2(this->followPoint.getY() - this->midPoint.getY(),
                         this->followPoint.getX() - this->midPoint.getX());

    this->angle = radianoParaGraus(angle);
}

void Enemy::move()
{
    switch (this->typeMove)
    {
    case 0:

        break;

    case 1: // anda para baixo
        this->midPoint.setY(this->midPoint.getY() - this->velocity.getY());
        break;

    case 2: // anda para esquerda
        this->midPoint.setX(this->midPoint.getX() + this->velocity.getX());
        break;

    case 3: // Kamikaze
        kamikazeMove();
        break;

    case 4: // parabola  y = x²
        parabolicMoveTemplate(-9.0 / 160, 9.0 / 2, -90);
        break;

    case 5: // parabola  y = x²
        parabolicMoveTemplate(9.0 / 160, -9, 360);
        break;

    case 6: // parabola  y = x²
        parabolicMoveTemplate(9.0 / 160, 0, 0);
        break;

    case 7: // senoide cima-baixo na direita
        senoidMoveTemplate(45, 20, 0.1, -15);
        break;

    case 8: // senoite cima-baixo na esquerda
        senoidMoveTemplate(-45, -20, 0.1, -15);
        break;

    case 9: // funcao de terceiro com 2 de segundo
        if (this->midPoint.getY() >= 60)
            parabolicMoveTemplate(9.0 / 160, -27.0 / 4, 405.0 / 2);
        else
            parabolicMoveTemplate(-9.0 / 160, 27.0 / 4, -405.0 / 2);
        break;

    case 10: // anda para baixo e mira para a posição do player
        this->midPoint.setY(this->midPoint.getY() - this->velocity.getY());
        break;
    }

    if (this->type == 3 || this->type == 5)
    {
        aim(); // rotaciona mirando para a posisção
        if (this->type == 3)
        {
            this->angle = this->angle - 90;
        }
    }

    verifyVisibility(*this);

    if (this->onScreen)
        this->onscreenTestable = 1;

    generalHitBoxMovement();
}

void Enemy::scaleMove(const double &scale) {}

std::vector<Projectile> Enemy::fire()
{
    Projectile projectile1 = this->currentProjectile;

    projectile1.setAngle(angle);

    projectile1.setOwner(2);

    std::vector<Projectile> vec;

    switch (this->typeTiroManager)
    {
    case 0: // tiro que sai na direcao do player
        switch (numberOfShots)
        {
        case 1:
            projectile1.setAngle(angle - 90);
            vec.push_back(createProject(&projectile1, 0));
            break;

        case 2:
            vec.push_back(createProject(&projectile1, M_PI / 2));
            vec.push_back(createProject(&projectile1, M_PI));
            break;
        }
        break;
    case 1: // tiro simples que espalha (tank)
        switch (numberOfShots)
        {
        case 3:

            projectile1.setAngle(angle - 32);
            vec.push_back(createProject(&projectile1, 0));

            projectile1.setAngle(angle);
            vec.push_back(createProject(&projectile1, M_PI / 2));

            projectile1.setAngle(angle + 32);
            vec.push_back(createProject(&projectile1, M_PI));
            break;

        case 5:
            projectile1.setAngle(angle - 50);
            vec.push_back(createProject(&projectile1, 0));

            projectile1.setAngle(angle - 25);
            vec.push_back(createProject(&projectile1, M_PI / 4));

            projectile1.setAngle(angle);
            vec.push_back(createProject(&projectile1, M_PI / 2));

            projectile1.setAngle(angle + 25);
            vec.push_back(createProject(&projectile1, 3 * M_PI / 4));

            projectile1.setAngle(angle + 50);
            vec.push_back(createProject(&projectile1, M_PI));
            break;
        }
        break;

    case 2: // tiro que segue
        switch (numberOfShots)
        {
        case 1:
            vec.push_back(createProject(&projectile1, 0));
            break;
        }
        break;
    }

    int r = rand() % 10;
    this->fireRatePeriod = this->currentProjectile.getDefaultFireRate() * (4 + r);
    // printf("Valor: %d\n",r);

    return vec;
}

/*
                case 3:
                    vec.push_back(createProject(&projectile1, M_PI/2));

                case 2:
                    vec.push_back(createProject(&projectile1, M_PI/4));
                    vec.push_back(createProject(&projectile1, 3*M_PI/4));
                    break;

                case 1:
                    vec.push_back(createProject(&projectile1, M_PI/2));
                    break;
            }
            break;

        case 1: // tiro que bate nas paredes
            switch(numberOfShots)
            {
                case 1:
                    projectile1.setHp(2);
                    break;
                case 2:
                    projectile1.setHp(3);
                    break;
                case 3:
                    projectile1.setHp(4);
                    break;
            }
            vec.push_back(createProject(&projectile1, M_PI/4));

            projectile1.getVelocity().setX(-projectile1.getVelocity().getX());
            vec.push_back(createProject(&projectile1, 3*M_PI/4));

            break;

        case 2: // tiro que segue
            switch (numberOfShots)
            {
            case 1:
                vec.push_back(createProject(&projectile1,   M_PI/2));
                break;
            case 2:
                vec.push_back(createProject(&projectile1,   M_PI/4));
                vec.push_back(createProject(&projectile1, 3*M_PI/4));
                break;
            case 3:
                vec.push_back(createProject(&projectile1, 0));
                vec.push_back(createProject(&projectile1,   M_PI/2));
                vec.push_back(createProject(&projectile1,   M_PI));
                break;
            }
            break;

        case 3:
            switch(numberOfShots)
            {
                case 3:
                printf("Enrtei 3\n");
                    vec.push_back(createProject(&projectile1, M_PI/2));

                case 2:
                    printf("Enrtei 2\n");
                    vec.push_back(createProject(&projectile1, M_PI/4));
                    vec.push_back(createProject(&projectile1, 3*M_PI/4));
                    break;

                case 1:
                    printf("Enrtei 1     %.2f\n",this->angle);
                    vec.push_back(createProject(&projectile1, 0));
                    break;
            }
            break;
            */
