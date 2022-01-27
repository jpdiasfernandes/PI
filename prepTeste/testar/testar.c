#include "testar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "teste_15_16/teste_15_16.h"
//#include "recurso_15_16/recurso_15_16.h"
//#include "teste_16_17/teste_16_17.h"
//#include "teste_17_18/teste_17_18.h"
#include "teste_19_20/teste_19_20.h"
////////
//ABIN
////////

ABin insABin (ABin a, int x) {
    ABin aux;

    if(a == NULL) {
        aux = malloc(sizeof(NodoABin));
        aux->dir = aux->esq = NULL;
        aux->valor = x;
        return aux;
    }
    else if (a->valor == x) return a;
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

////////
//LLINT
////////

void showLInt(LInt l) {
    while (l){
        printf("%d ", l->valor);
        l = l->prox;
    }
    printf("\n");
}
//append
LInt snoc (LInt l, int x) {
    LInt tmp = l;
    LInt novo = malloc(sizeof(struct slist));
    novo->valor = x;
    novo->prox = NULL;

    while(l && l->prox)
        l = l->prox;
    if(l) l->prox = novo;
    else tmp = novo;

    return tmp;
}

////////
//ALUNOS
////////


Alunos insAluno (Alunos a, char nome[], int numero, int nota) {
    Alunos aux;

    if(a == NULL) {
        aux = malloc(sizeof(struct aluno));
        aux->dir = aux->esq = NULL;
        strcpy(aux->nome, nome);
        aux->numero = numero;
        aux->nota = nota;
        return aux;
    }
    else {
        if(numero < a->numero) a->esq = insAluno(a->esq, nome, numero, nota);
        else a->dir = insAluno(a->dir, nome, numero, nota);
        return a;
    }
}

////////
//ARRAYS
////////

void imprimeMatriz (int N, float m[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf("%.0f ", m[i][j]);
        putchar('\n');
    }
}
int main () {
    int v[5] = {1,4,7,11,14};
    ABin a = NULL;
    for (int i = 0; i < 5; i++)
        a = insABin(a, i);

    //for (int i = 1; i < 12; i++)
     //   a = insABin(a,i);
     char s[1024];
     strcpy(s, "Ola tudo bem?");
     pad(s, 3,2);
     printf("%s", s);

    return 0;
}
