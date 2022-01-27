#include "../testar.h"
#ifndef TESTAR_TESTE_15_16_H
#define TESTAR_TESTE_15_16_H
char *mystrcat (char s1[], char s2[]);
int remRep (char x[]);
int nivelV (ABin a, int n, int v[]);
int addOrd (ABin *a, int x);
float getValor (Colunas lcol, int coluna);
float getEntry (Mat m, int linha, int coluna);
void setEntry (Mat *m, int linha, int coluna, float valor);
void alteraValor (Mat m, int linha, int coluna, float valor);
void alteraValorC(Colunas lcol, int coluna, float valor);
void insereValorC (Colunas *lcol, int coluna, float valor);
void imprimeMatL (Mat m);
void transpose (Mat *m);
void addTo (Mat *m1, Mat m2);
#endif //TESTAR_TESTE_15_16_H
