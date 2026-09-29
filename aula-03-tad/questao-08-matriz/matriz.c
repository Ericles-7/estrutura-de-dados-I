/* Representacao: bloco unico de floats. Sao duas alocacoes no total
 * (estrutura e bloco), os elementos ficam contiguos e a liberacao usa
 * apenas dois free. Um vetor de ponteiros exigiria mais alocacoes
 * (uma por linha, alem do vetor e da estrutura) e liberacao por linha.
 */
#include "matriz.h"
#include <stdint.h>
#include <stdlib.h>

struct matriz {
    int nl, nc;
    float *v;
};

Matriz *criarMatriz(int nl, int nc) {
    if (nl <= 0 || nc <= 0 || (size_t)nl > SIZE_MAX / (size_t)nc ||
        (size_t)nl * (size_t)nc > SIZE_MAX / sizeof(float)) return NULL;
    Matriz *m = malloc(sizeof *m);
    if (m == NULL) return NULL;
    m->nl = nl;
    m->nc = nc;
    m->v = calloc((size_t)nl * (size_t)nc, sizeof *m->v);
    if (m->v == NULL) { free(m); return NULL; }
    return m;
}

void liberarMatriz(Matriz *m) {
    if (m == NULL) return;
    free(m->v);
    free(m);
}

static int indiceValido(const Matriz *m, int i, int j) {
    return m != NULL && i >= 0 && j >= 0 && i < m->nl && j < m->nc;
}

int lerElemento(Matriz *m, int i, int j, float *v) {
    if (!indiceValido(m, i, j) || v == NULL) return 0;
    *v = m->v[(size_t)i * (size_t)m->nc + (size_t)j];
    return 1;
}

int atribuirElemento(Matriz *m, int i, int j, float v) {
    if (!indiceValido(m, i, j)) return 0;
    m->v[(size_t)i * (size_t)m->nc + (size_t)j] = v;
    return 1;
}

int numLinhas(Matriz *m) { return m == NULL ? 0 : m->nl; }
int numColunas(Matriz *m) { return m == NULL ? 0 : m->nc; }
