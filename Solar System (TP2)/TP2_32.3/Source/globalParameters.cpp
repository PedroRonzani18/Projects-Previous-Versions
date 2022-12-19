#include "../Header/globalParameters.h"

// Variável de rezão aspecto da tela
float razaoAspecto;

// Variável que armazena o tempo de execução do programa em segundos
double tempo;

// Objeto que armazena se uma tecla está pressionada (keys->x = 1) ou não (keys->x = 0)
Keyboard* keys;

// Vector com os ID's das texturas
std::vector<GLuint> texturesId;

// Vetor auxiliar para simular um botão ao se pressionar uma tecla
int buttons[] = {0,0};