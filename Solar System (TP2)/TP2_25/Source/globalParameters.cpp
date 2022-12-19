#include "../Header/globalParameters.h"

// Variável global de razão aspecto da tela
float razaoAspecto;

// Variável global do valor atual do tempo de execução do programa
double tempo;

// Objeto que simboliza as teclas do teclado pressionadas ou não
Keyboard* keys;

// Vector de texturas
std::vector<GLuint> texturesId;

// Vetor auxiliar para simular um aperto de botão mais realista
int buttons[] = {0};