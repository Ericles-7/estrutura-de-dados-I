#include "vetord.h"
#include <stdio.h>

static int testar(PoliticaCrescimento politica, unsigned long long *copias) {
    VetorD *v = criarVetorD(1);
    if (v == NULL || !definirPoliticaVetorD(v, politica)) { liberarVetorD(v); return 0; }
    for (int i = 0; i < 100000; ++i) {
        if (!inserirVetorD(v, (float)i)) { liberarVetorD(v); return 0; }
    }
    *copias = copiasVetorD(v);
    float ultimo = 0.0f;
    int ok = lerVetorD(v, 99999, &ultimo) && ultimo == 99999.0f && tamanhoVetorD(v) == 100000;
    liberarVetorD(v);
    return ok;
}
int main(void) {
    unsigned long long um = 0, dobro = 0;
    if (!testar(CRESCER_UM, &um) || !testar(DOBRAR, &dobro)) {
        puts("Falha no teste."); return 1;
    }
    printf("Crescimento +1: %llu copias teoricas\n", um);
    printf("Crescimento x2: %llu copias teoricas\n", dobro);
    printf("Razao (+1/x2): %.2f\n", (double)um / (double)dobro);
    return 0;
}
