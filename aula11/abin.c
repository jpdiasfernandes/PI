#include <stdio.h>
#include <stdlib.h>
#include "abin.h"

int max (int a , int b) {
    return (a > b)? a : b;
}
int absInt (int a) {
    return (a < 0)? -a : a;
}
int peso (ABin a) {
    if (a == NULL) return 0;
    else 
        return 1 + max(peso(a->esq), peso(a->dir));
}

int nodos (ABin a) {
    if (a == NULL) return 0;
    else 
        return 1 + peso(a->esq) + peso(a->dir);
}

ABin insABin (ABin a, int x) {
    ABin aux;

    if(a == NULL) {
        aux = malloc(sizeof(NodoABin));
        aux->dir = aux->esq = NULL;
        aux->valor = x;
        return aux;
    }
    else {
        if(x < a->valor) a->esq = insABin(a->esq, x);
        else a->dir = insABin(a->dir, x);
        return a;
    }
}

void inorder (ABin a) {
    if(a != NULL) {
        inorder(a->esq);
        printf("%d ", a->valor);
        inorder(a->dir);
    }
}

void preorder (ABin a) {
    if(a != NULL) {
        printf("%d ", a->valor);
        preorder(a->esq);
        preorder(a->dir);
    }
}

void posorder (ABin a) {
    if(a != NULL) {
        posorder(a->esq);
        posorder(a->dir);
        printf("%d ", a->valor);
    }
}

int balanceada (ABin a) {
    if (a == NULL) return 1;
    else {
        if(absInt(peso(a->esq) - peso(a->dir)) <= 1) return (balanceada (a->esq) && balanceada (a->dir));
        else return 0;
    }
}
