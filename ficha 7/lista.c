#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"


int iguais (LInt a, LInt b) {
    // testa se duas listas são iguais
    while (a != NULL && b != NULL && a->valor == b->valor) {
        a = a->prox; b = b->prox;
    }
    return (a==NULL && b==NULL);
}

LInt cons (LInt l, int x) {
    LInt r = malloc (sizeof (struct slist));

    r->valor = x;
    r->prox  = l;

    return r;
}

int cons1 (LInt *l, int x) {
    // a invocacao
    // cons1 (&a, x)
    // deve corresponder a fazer
    // a = cons (a,x)
    // além disso retorna 1 se a alocação de memória não for possivel

    // ... completar

    return 1;
}

LInt tail (LInt l) {
    LInt tmp = l;
    l = l->prox;
    free (tmp);
    return l;
}

int tail1 (LInt *l) {
    // a invocação
    // tail1 (&a)
    // deve corresponder a fazer
    // a = tail (a)
    // além disso retorna 1 se a lista for vazia

    // ... completar

    return 1;
}

LInt initRec (LInt l) {
    // definição em Haskell:
    // init [x] = []
    // init (x:xs) = x:init xs
    if (l->prox==NULL) {
        free (l); l=NULL;
    }
    else l->prox = initRec (l->prox);
    return l;
}

LInt init (LInt l) {
    LInt tmp = l;
    while(l!=NULL) {
        if (l->prox == NULL) {
            free(l);
            l = NULL;
        }
        else l = l->prox;
    }
    return tmp;
}

int init1 (LInt *l) {
    // a invocação
    // init1 (&a)
    // deve corresponder a fazer
    // a = init1 (a)
    // além disso retorna 1 se a lista for vazia

    // ... completar

    return 1;
}

LInt snocRec (LInt l, int x) {
    // definição em Haskell
    // snoc [] x = [x]
    // snoc (h:t) x = h:(snoc t x)
    if (l==NULL) {
        l = malloc (sizeof (struct slist));
        l->valor = x;
        l->prox  = NULL;
    } else l->prox = snocRec (l->prox, x);

    return l;
}

LInt snoc (LInt l, int x) {
    LInt tmp,ant;
    for(tmp = l; tmp != NULL;tmp = tmp->prox)
        ant = tmp;

    tmp = malloc(sizeof(struct slist));
    tmp->valor = x;
    tmp->prox = NULL;
    if(l == NULL)l = tmp;
    else ant->prox = tmp;
    return l;
}

int snoc1 (LInt *l, int x) {
    // a invocacao
    // snoc1 (&a, x)
    // deve corresponder a fazer
    // a = snoc (a,x)
    // além disso retorna 1 se a alocação de memória não for possivel

    // ... completar

    return 1;
}

LInt concatRec (LInt a, LInt b) {
    // definição em Haskell
    // [] ++ bs = bs
    // (a:as) ++ bs = a:(as ++ bs)
    if (a==NULL) a = b;
    else a->prox = concatRec (a->prox,b);
    return a;
}

LInt concat (LInt a, LInt b) {
    LInt tmp = a;
    while(a != NULL){
        if(a->prox == NULL) a->prox = b;
        else a = a->prox;
    }

    return tmp;
}

void concat1 (LInt *a, LInt b){
    // a invocacao
    // concat1 (&a, b)
    // deve corresponder a fazer
    // a = concat (a,b)

    // ... completar
}

Aluno newAluno (char *nome, int numero, int nota){
    Aluno novo;
    strcpy(novo.nome,nome);
    novo.numero = numero;
    novo.nota = nota;

    return novo;
}

Turma vazia () {
    Turma r;


    return NULL;
}

int acrescentaAluno (Turma *t, Aluno a){
    Turma tmp;
    if(tmp = malloc(sizeof(struct sturma)) != NULL){
        tmp->aluno = a;
        tmp->prox = *t;
        *t = tmp;
        return 0;
    }
    return 1;
}

Aluno * procura (Turma t, int numero){
    while(t->aluno.numero != numero)t = t->prox;
    return (t == NULL)? NULL : &t->aluno;
}

int aprovados (Turma t){
    int r = 0;
    while(t != NULL){
        if(t->aluno.nota >= 10)r++;
        t = t->prox;
    }
    return r;
}
