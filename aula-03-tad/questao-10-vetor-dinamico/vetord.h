#ifndef VETORD_H
#define VETORD_H

typedef struct vetord VetorD;
typedef enum { CRESCER_UM = 1, DOBRAR = 2 } PoliticaCrescimento;
VetorD *criarVetorD(int capacidadeInicial);
void liberarVetorD(VetorD *v);
int definirPoliticaVetorD(VetorD *v, PoliticaCrescimento politica);
int inserirVetorD(VetorD *v, float x);
int lerVetorD(VetorD *v, int pos, float *x);
int tamanhoVetorD(VetorD *v);
unsigned long long copiasVetorD(const VetorD *v);
#endif
