#ifndef _STACK
#define _STACK

typedef struct slist {
    int valor;
    struct slist *prox;
} Nodo, *LInt;

typedef LInt Stack;

void initStack (Stack *s);
int isEmptyS (Stack *s);
int push (Stack *s, int x);
int pop (Stack *s, int *x);
int top (Stack *s, int *x);
void showStack (Stack s);
#endif