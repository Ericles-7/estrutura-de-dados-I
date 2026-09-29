#include "complexo.h"
#include <stdlib.h>

struct complexo { float real, imag; };

Complexo *criarComplexo(float real, float imag) {
    Complexo *z = malloc(sizeof *z);
    if (z != NULL) { z->real = real; z->imag = imag; }
    return z;
}
void liberarComplexo(Complexo *z) { free(z); }
int lerComplexo(const Complexo *z, float *real, float *imag) {
    if (z == NULL || real == NULL || imag == NULL) return 0;
    *real = z->real; *imag = z->imag; return 1;
}
int atribuirComplexo(Complexo *z, float real, float imag) {
    if (z == NULL) return 0;
    z->real = real; z->imag = imag; return 1;
}
int somarComplexos(const Complexo *a, const Complexo *b, Complexo *r) {
    if (a == NULL || b == NULL || r == NULL) return 0;
    float real = a->real + b->real, imag = a->imag + b->imag;
    return atribuirComplexo(r, real, imag);
}
int subtrairComplexos(const Complexo *a, const Complexo *b, Complexo *r) {
    if (a == NULL || b == NULL || r == NULL) return 0;
    float real = a->real - b->real, imag = a->imag - b->imag;
    return atribuirComplexo(r, real, imag);
}
int multiplicarComplexos(const Complexo *a, const Complexo *b, Complexo *r) {
    if (a == NULL || b == NULL || r == NULL) return 0;
    float real = a->real * b->real - a->imag * b->imag;
    float imag = a->imag * b->real + a->real * b->imag;
    return atribuirComplexo(r, real, imag);
}
int dividirComplexos(const Complexo *a, const Complexo *b, Complexo *r) {
    if (a == NULL || b == NULL || r == NULL) return 0;
    float den = b->real * b->real + b->imag * b->imag;
    if (den == 0.0f) return 0;
    float real = (a->real * b->real + a->imag * b->imag) / den;
    float imag = (a->imag * b->real - a->real * b->imag) / den;
    return atribuirComplexo(r, real, imag);
}
