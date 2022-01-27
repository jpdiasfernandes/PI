#include <stdio.h>
#include <stdlib.h>
#include "../testar.h"
int preencheNota (Alunos a, Alunos t[], int nota) {
    int r = 0;
    if (!a) return r;
    else {
        if (a->nota == nota) t[r++] = a;
        int esq = preencheNota(a->esq, t+r, nota);
        int dir = preencheNota(a->dir, t+r+esq, nota);
        return r + esq + dir;
    }
}

void preenche (Alunos a, Alunos t[], int freq[21]) {
    int i = 0, j = 0;

    for (j = 20; j >= 0; j--) {
      i += preencheNota(a, t + i, j);
    }
}

void imprime (Alunos a) {
    int i;
    int notas [21];
    int quantos = 20 ; // = fnotas
    Alunos todos[quantos];

    preenche (a, todos, notas);

    for (i = 0; i < quantos; i++)
        printf ("%d %s %d\n", todos[i]->numero, todos[i]->nome, todos[i]->nota);
}
