#include "ponto.h"
#include "entity.h"
#include "listas.h"

using namespace std;

int main()
{
    Entity a;
    a.x_max = 20;

    entityList.push_back(a);

    printf("Valor: %f\n",entityList[0].x_max); 
}