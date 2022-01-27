#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

void initStack (Stack *s) {
    *s = NULL;
}
int isEmptyS (Stack *s) {
    if(*s == NULL) return 1;
    else return 0;
}
int push (Stack *s, int x) {
    int r = 0;
    Stack novo = malloc(sizeof(Nodo));
    if(novo){
        novo->valor = x;
        novo->prox = *s;
        *s = novo;
        r = 1;
    }
    else r = 0;

    return r;
}

int pop (Stack *s, int *x) {
    int r;
    if(isEmptyS(s)) r = 0;
    else{
        Stack tmp = (*s);
        *x = (*s)->valor;
        free(tmp);
        *s = (*s)->prox;
        r = 1;
    }

    return r;
}

int top (Stack *s, int *x) {
    int r;

    if(isEmptyS) r = 0;
    else {
        *x = (*s)->valor;
        r = 1;
    }

    return r;
}

void showStack (Stack s) {
    
    while (s) {
        printf("%d ", s->valor);
        s = s->prox;
    }
    printf("NULL\n");
}