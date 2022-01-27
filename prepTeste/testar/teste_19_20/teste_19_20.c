#include "teste_19_20.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//1
int verifica (int s[], int N) {
    int res = 1;
    int i, a, b;
    if (N == 0) res = 0;
    else if (N == 1) res = 1;
    else if (N > 1) {
        a = s[0]; //a + b * 0
        b = s[1]-s[0]; //a + b*1 - a

        for (i = 0; i < N && res; i++)
            if (s[i] != (a + b*i)) res = 0;

    }

    return res;
}
//2
void gera (LInt *l, int N) {
    int ant1 = 1;
    int ant2 = 1;
    int prox;

    while (N) {
        LInt novo = malloc(sizeof(struct slist));
        novo->valor = ant1;
        novo->prox = NULL;
        *l = novo;
        l = &(*l)->prox;
        prox = ant1 + ant2;
        ant1 = ant2;
        ant2 = prox;
        N--;
    }
}
//3
LInt anterior (LInt l) {
    LInt *sitio = &l;

    while ((*sitio) && (*sitio)->prox != l)
        sitio = &(*sitio)->prox;

    return *sitio;
}
//4
void reverse (DLint *l) {
    if (l->front || l->last) {
        NodoD *front = l->front;

        NodoD **sitio = &front;
        while (*sitio) {
            NodoD *tmp = (*sitio)->prox;
            (*sitio)->prox = (*sitio)->ant;
            (*sitio)->ant = tmp;

            sitio = &(*sitio)->ant;
        }
    }
}
//5
void imprimeCaminho(int v[], int n) {
    int i = 0;
    for (i = 1; i <= n; i++) {
        if (v[i] == 1) putchar('>');
        else if (v[i] == -1) putchar('<');
    }
}
void imprimeAux (ABin t, int v[], int n) {
    if (t) {
        imprimeCaminho(v, n);
        printf("%d\n", t->valor);
        v[++n] = -1;
        imprimeAux(t->esq, v, n);
        v[n] = 1;
        imprimeAux(t->dir, v, n);
    }

}
void imprime (ABin t) {
    int v[1000];
    v[0] = 0;
    imprimeAux(t, v, 0);
}

//6
void shiftDir (char *texto, int N) {
    char aux[1024];
    int i,j;
    for (i = 0; texto[i]; i++)
        aux[i] = texto[i];
    aux[i] = 0;

    for (j = 0; j < N; j++)
        texto[j] = ' ';

    for (i = 0; aux[i]; i++)
        texto[j++] = aux[i];

    texto[j] = 0;
}
void pad (char *texto, int p, int N) {
    int i;
    for (i = 0; p > 1; i++) {
        if (texto[i] == ' '){
            shiftDir(texto + i, N);
            p--;
            for (i; texto[i] == ' '; i++);

        }
    }
}
//7
int calculaQuantos (Palavras p) {
    if (!p) return 0;
    int esq = calculaQuantos(p->esq);
    int dir = calculaQuantos(p->dir);
    p->quantos = esq + dir;
    return esq + dir + 1;
}
//8




