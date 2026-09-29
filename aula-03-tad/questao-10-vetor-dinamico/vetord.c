#include "vetord.h"
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>

struct vetord {
    float *dados;
    int tamanho, capacidade;
    PoliticaCrescimento politica;
    unsigned long long copias;
};

VetorD *criarVetorD(int capacidadeInicial) {
    if (capacidadeInicial <= 0 || (size_t)capacidadeInicial > SIZE_MAX / sizeof(float)) return NULL;
    VetorD *v = malloc(sizeof *v);
    if (v == NULL) return NULL;
    v->dados = malloc((size_t)capacidadeInicial * sizeof *v->dados);
    if (v->dados == NULL) { free(v); return NULL; }
    v->tamanho = 0;
    v->capacidade = capacidadeInicial;
    v->politica = DOBRAR;
    v->copias = 0;
    return v;
}
void liberarVetorD(VetorD *v) {
    if (v == NULL) return;
    free(v->dados); free(v);
}
int definirPoliticaVetorD(VetorD *v, PoliticaCrescimento politica) {
    if (v == NULL || (politica != CRESCER_UM && politica != DOBRAR)) return 0;
    v->politica = politica; return 1;
}
int inserirVetorD(VetorD *v, float x) {
    if (v == NULL) return 0;
    if (v->tamanho == v->capacidade) {
        int nova;
        if (v->politica == CRESCER_UM) {
            if (v->capacidade == INT_MAX) return 0;
            nova = v->capacidade + 1;
        } else {
            if (v->capacidade == INT_MAX) return 0;
            nova = v->capacidade > INT_MAX / 2 ? INT_MAX : v->capacidade * 2;
        }
        if ((size_t)nova > SIZE_MAX / sizeof *v->dados) return 0;
        float *temp = realloc(v->dados, (size_t)nova * sizeof *v->dados);
        if (temp == NULL) return 0; /* Dados e capacidade antigos continuam intactos. */
        v->dados = temp;
        /* Contador do modelo: elementos que precisariam ser copiados caso
           o realloc mudasse o bloco de endereco; movimento fisico nao e
           observavel/garantido pela linguagem C. */
        v->copias += (unsigned long long)v->tamanho;
        v->capacidade = nova;
    }
    v->dados[v->tamanho++] = x;
    return 1;
}
int lerVetorD(VetorD *v, int pos, float *x) {
    if (v == NULL || x == NULL || pos < 0 || pos >= v->tamanho) return 0;
    *x = v->dados[pos]; return 1;
}
int tamanhoVetorD(VetorD *v) { return v == NULL ? 0 : v->tamanho; }
unsigned long long copiasVetorD(const VetorD *v) { return v == NULL ? 0ULL : v->copias; }
