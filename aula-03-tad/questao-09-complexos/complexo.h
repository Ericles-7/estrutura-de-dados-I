#ifndef COMPLEXO_H
#define COMPLEXO_H

typedef struct complexo Complexo;
/* Operacoes escrevem em 'resultado', fornecido pelo chamador.
 * O chamador e dono desse objeto e deve chamar liberarComplexo nele.
 * Retorno 1: sucesso; 0: erro. Em erro, resultado nao e modificado.
 */
Complexo *criarComplexo(float real, float imag);
void liberarComplexo(Complexo *z);
int lerComplexo(const Complexo *z, float *real, float *imag);
int atribuirComplexo(Complexo *z, float real, float imag);
int somarComplexos(const Complexo *a, const Complexo *b, Complexo *resultado);
int subtrairComplexos(const Complexo *a, const Complexo *b, Complexo *resultado);
int multiplicarComplexos(const Complexo *a, const Complexo *b, Complexo *resultado);
int dividirComplexos(const Complexo *a, const Complexo *b, Complexo *resultado);
#endif
