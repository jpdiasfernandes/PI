#include "teste_15_16.h"
#include "../testar.h"
#include <stdio.h>
#include <stdlib.h>
//1
char *mystrcat (char s1[], char s2[]) {
    int i1, i2;

    for (i1 = 0; s1[i1]; i1++);

    for (i2 = 0; s2[i2]; i2++)
        s1[i1++] = s2[i2];

    s1[i1] = 0;

    return s1;
}
//2
int remRep (char x[]) {
    int i,j;
    char ant = 0;
    for (i = 0; x[i]; i++) {
        if (x[i] != ant) x[j++] = x[i];
        ant = x[i];
    }
    x[j] = 0;
    return j;
}
//3
int nivelV (ABin a, int n, int v[]) {
    if (!a || n == 0) return 0;
    if (n == 1) {
        v[0] = a->valor;
        return 1;
    }
    else {
        int esq = nivelV(a->esq, n-1, v);
        int dir = nivelV(a->dir, n-1, v + esq);
        return esq + dir;
    }
}
//4
int addOrd (ABin *a, int x) {
    ABin novo = malloc(sizeof(struct abin));
    novo->valor = x;
    novo->esq = novo->dir = NULL;

    while (*a) {
        int tmp = (*a)->valor;
        if (tmp > x) {
            if ((*a)->esq == NULL) {
                (*a)->esq = novo;
                return 0;
            }
            a = &(*a)->esq;
        }
        else if (tmp < x) {
            if ((*a)->dir == NULL) {
                (*a)->dir = novo;
                return 0;
            }
            a = &(*a)->dir;
        }
        else {
            free(novo);
            return 1;
        }
    }
    if (!(*a)) *a = novo;
    return 0;
}

/////////
//Parte B
/////////

//1
float getEntry (Mat m, int linha, int coluna) {
    float r = 0;
    while (m && m->linha < linha)
        m = m->prox;
    if (m && m->linha == linha) r = getValor(m->lcol,coluna);

    return r;
}

float getValor (Colunas lcol, int coluna) {
    float r = 0;
    while (lcol && lcol->coluna < coluna)
        lcol = lcol ->prox;

    if (lcol && lcol->coluna == coluna)
        r = lcol->valor;

    return r;
}

//2
void setEntry (Mat *m, int linha, int coluna, float valor) {
    if ((int)getEntry(*m, linha, coluna)) alteraValor (*m, linha, coluna, valor);
    else {
        Mat novo = malloc (sizeof(struct listaL));
        novo->lcol = NULL;
        novo->prox = NULL;
        novo->linha = linha;

        while (*m && (*m)->linha < linha)
            m = &(*m)->prox;

        if (!(*m)) {
            *m = novo;
            insereValorC(&(*m)->lcol, coluna, valor);
        }
        else if ((*m)->linha == linha) insereValorC(&(*m)->lcol, coluna, valor);
        else {
            Mat tmp = *m;
            *m = novo;
            (*m)->prox = tmp;
            insereValorC(&(*m)->lcol, coluna, valor);

        }
    }
}

void alteraValor (Mat m, int linha, int coluna, float valor) {
    if (m->linha == linha) alteraValorC(m->lcol, coluna, valor);
    else alteraValor(m->prox, linha, coluna, valor);
}
void alteraValorC(Colunas lcol, int coluna, float valor) {
    if (lcol->coluna == coluna) lcol->valor = valor;
    else alteraValorC(lcol->prox, coluna, valor);
}

void insereValorC (Colunas *lcol, int coluna, float valor) {
    Colunas novo = malloc(sizeof(struct listaC));
    novo->valor = valor;
    novo->prox = NULL;
    novo->coluna = coluna;


    while (*lcol && (*lcol)->coluna < coluna)
        lcol = &(*lcol)->prox;

    if (!(*lcol)) *lcol = novo;
    else {
        Colunas tmp = *lcol;
        *lcol = novo;
        (*lcol)->prox = tmp;
    }
}

//3
void addTo (Mat *m1, Mat m2) {
    if (!(*m1)) *m1 = m2;
    else {
        while (m2) {
            int linha = m2->linha;
            Colunas cols = m2->lcol;
            while (cols) {
                setEntry(m1, linha, cols->coluna, cols->valor);
                cols = cols->prox;
            }
            m2 = m2->prox;
        }
    }
}

//4
void transpose (Mat *m) {
    int linha;
    float tmp;
    Mat aux  = NULL;

    while (*m) {
        linha = (*m)->linha;
        Colunas cols = (*m)->lcol;
        while (cols) {
            setEntry(&aux, linha, cols->coluna, cols->valor);
            cols = cols->prox;
        }
        m = &(*m)->prox;
    }

    while (aux) {
        linha = (aux)->linha;
        Colunas cols = (aux)->lcol;
        while (cols) {
           setEntry(m, cols->coluna, linha, cols->valor);
           cols = cols->prox;
        }
        aux = aux->prox;
    }
}

void imprimeMatL (Mat m) {
    int col = 0;
    int linha = 0;
    while (m) {
        Colunas cols = m->lcol;
        while (cols) {
            printf ("%.0f ", cols->valor);
            cols = cols->prox;
        }
        putchar('\n');
        m = m->prox;
    }
}
