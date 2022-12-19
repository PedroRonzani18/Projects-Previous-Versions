#include "../Header/Score.h"
#include <stdio.h>

Score::Score() : Entity()
{
    this->setMidPoint(40, 90);
    this->score = 0;

    this->digitsScoreTextures[0] = textures[16];
    this->digitsScoreTextures[1] = textures[17];
    this->digitsScoreTextures[2] = textures[18];
    this->digitsScoreTextures[3] = textures[19];
    this->digitsScoreTextures[4] = textures[20];
    this->digitsScoreTextures[5] = textures[21];
    this->digitsScoreTextures[6] = textures[22];
    this->digitsScoreTextures[7] = textures[23];
    this->digitsScoreTextures[8] = textures[24];
    this->digitsScoreTextures[9] = textures[25];
}

void Score::draw()
{
    int dig[9];
    double tamDig = 10;

    printf("Score: %d\n", this->score);

    for (int i = 0; i < 9; i++)
    {
        dig[i] = 0;
        int aux = score / pow(10, i);
        dig[i] = aux % 10;

        glPushMatrix();
            glTranslatef(this->midPoint.getX() - tamDig*i,
                         this->midPoint.getY(),
                         0);

        switch (dig[i])
        {
            case 0:
                glCallList(this->digitsScoreTextures[0]);
                break;

            case 1:
                glCallList(this->digitsScoreTextures[1]);
                break;

            case 2:
                glCallList(this->digitsScoreTextures[2]);
                break;

            case 3:
                glCallList(this->digitsScoreTextures[3]);
                break;

            case 4:
                glCallList(this->digitsScoreTextures[4]);
                break;

            case 5:
                glCallList(this->digitsScoreTextures[5]);
                break;

            case 6:
                glCallList(this->digitsScoreTextures[6]);
                break;

            case 7:
                glCallList(this->digitsScoreTextures[7]);
                break;

            case 8:
                glCallList(this->digitsScoreTextures[8]);
                break;

            case 9:
                glCallList(this->digitsScoreTextures[9]);
                break;
        }
        glPopMatrix();
    }
}

void Score::auxDraw(const int &dig)
{
}