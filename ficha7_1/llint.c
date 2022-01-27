#include "llint.h"
#include <stdio.h>
#include <stdlib.h>

void showLInt(LInt l) {
    while (l){
        printf("%d ", l->valor);
        l = l->prox;
    }
    printf("\n");
}

void showLIntR(LInt l) {
    if(l){
        printf("%d ", l->valor);
        showLIntR(l->prox);
    }
    else printf("\n");
}

LInt cons (LInt l, int x){
    LInt tmp;

    tmp = malloc(sizeof(Nodo));
    tmp->valor = x;
    tmp->prox = l;

    return tmp;
}

LInt tail (LInt l) {
    if(!l){
        LInt tmp = l;

        l = l->prox;
        free(tmp);
    }

    return l;
}

LInt init (LInt l){
    LInt tmp = l;
    LInt ant;

    while(l &&  l->prox){
        ant = l;
        l = l->prox;
    }
    if(!l){
        ant->prox = NULL;
        free(l);
    }

    return tmp;
}

LInt snoc (LInt l, int x) {
    LInt tmp = l;
    LInt novo = malloc(sizeof(Nodo));
    novo->valor = x;
    novo->prox = NULL;
    
    while(l && l->prox) 
        l = l->prox;
    if(l) l->prox = novo;
    else tmp = novo;

    return tmp;
}

LInt concat (LInt a, LInt b) {
    LInt tmp = a;

    while(tmp && tmp->prox) tmp = tmp->prox;
    if(!tmp) tmp = b;
    else tmp->prox = b;

    return a;
}