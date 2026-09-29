#include "matriz.h"
#include <stdio.h>

int main(void) {
    Matriz *m = criarMatriz(2, 3);
    float valor = 0.0f;
    if (m == NULL) { puts("Falha ao criar matriz."); return 1; }
    atribuirElemento(m, 0, 0, 1.5f);
    atribuirElemento(m, 1, 2, 7.0f);
    if (lerElemento(m, 1, 2, &valor)) printf("Matriz %dx%d: %.1f\n", numLinhas(m), numColunas(m), valor);
    printf("Indice invalido: %d\n", lerElemento(m, 2, 0, &valor));
    printf("Escrita invalida: %d\n", atribuirElemento(m, -1, 0, 4.0f));
    liberarMatriz(m);
    return 0;
}
