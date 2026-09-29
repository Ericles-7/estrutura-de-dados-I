#include "complexo.h"
#include <stdio.h>

int main(void) {
    float a, b, c, d, real, imag;
    char op;
    puts("Informe a parte real e imaginaria do primeiro complexo:");
    if (scanf("%f %f", &a, &b) != 2) return 1;
    puts("Informe a parte real e imaginaria do segundo complexo:");
    if (scanf("%f %f", &c, &d) != 2) return 1;
    puts("Operacao (+ - * /):");
    if (scanf(" %c", &op) != 1) return 1;
    Complexo *z1 = criarComplexo(a, b);
    Complexo *z2 = criarComplexo(c, d);
    Complexo *r = criarComplexo(0.0f, 0.0f);
    if (z1 == NULL || z2 == NULL || r == NULL) {
        puts("Falha de memoria.");
        liberarComplexo(z1); liberarComplexo(z2); liberarComplexo(r);
        return 1;
    }
    int ok = 0;
    switch (op) {
        case '+': ok = somarComplexos(z1, z2, r); break;
        case '-': ok = subtrairComplexos(z1, z2, r); break;
        case '*': ok = multiplicarComplexos(z1, z2, r); break;
        case '/': ok = dividirComplexos(z1, z2, r); break;
        default: puts("Operacao invalida."); break;
    }
    if (ok && lerComplexo(r, &real, &imag)) printf("Resultado: %.4f %+.4fi\n", real, imag);
    else puts("Nao foi possivel calcular (operacao invalida ou divisao por zero).");
    liberarComplexo(z1); liberarComplexo(z2); liberarComplexo(r);
    return ok ? 0 : 1;
}
