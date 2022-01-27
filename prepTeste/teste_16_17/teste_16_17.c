#include "teste_16_17.h"
#include <stdio.h>
#include <stdlib.h>

//1
int limpaEspacos (char t[]) {
    int i, j = 0;
    char ant = 0;
    for (i = 0; t[i]; i++) {
        if (ant != ' ' || t[i] != ' ')
            t[j++] = t[i];
        ant = t[i];
    }

    t[j] = 0;

    return j;
}
//2
void transposta (int N, float m[N][N]) {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < i; j++) {
            float tmp = m[j][i];
            m[j][i] = m[i][j];
            m[i][j] = tmp;
        }
    }
}
//3
LInt cloneL (LInt l) {
    LInt aux = NULL;
    LInt *sitio = &aux;
    while (l) {
        LInt novo = malloc(sizeof (struct slist));
        novo->prox = NULL;
        novo->valor = l->valor;
        *sitio = novo;
        sitio = &(*sitio)->prox;
        l = l->prox;
    }
    return aux;
}
//5
void removeMaiorA (ABin *a) {
    while (*a && (*a)->dir)
        a = &(*a)->dir;

    ABin tmp = *a;
    *a = tmp->esq;
    free(tmp);
}

/////////
//Parte B
/////////

//1
int push (StackC *s, int x) {
    if (!s) return 1;
    CList clist = s->valores;
    if (clist && s->sp != 2 ) {
        s->valores->vs[++s->sp] = x;
    }
    else {
        CList novo;
        novo= malloc (sizeof(struct chunk));
        novo->vs[0] = x;
        s->sp = 0;

        CList tmp = s->valores;
        novo->prox = tmp;
        s->valores = novo;
        }
    return 0;
}
//2
int pop (StackC *s, int *x) {
    if (!s || !s->valores) return 1;
    CList l = s->valores;
    *x = l->vs[s->sp];
    l->vs[s->sp] = 0;
    if (s->sp == 0) {
        s->sp = 2;
        CList tmp = l;
        l = l->prox;
        s->valores = l;
        free(tmp);
    }
    else s->sp--;

    return 0;
}
//3
int sizeSt (StackC s) {
    CList l = s.valores;
    int r = 0;
    while (l) {
        r += (!r)? (s.sp+1) : 3;
        l = l->prox;
    }
    return r;
}
//4
void reverse (StackC *s) {
    if (!s) return;
    int size;
    size = sizeSt(*s);
    int v[size];
    int i;

    for (i = 0; !pop(s, v+i); i++);

    for (i = 0; i < size; i++)
        push(s, v[i]);
}

//extra
void imprimeStackC (StackC s) {
    CList clist = s.valores;
    while (clist) {
        int i;
        for (i = 0; i < 3   ; i++)
            printf("%d ", clist->vs[i]);
        putchar('\n');
        clist = clist->prox;
    }
}
