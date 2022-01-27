#include "alunos.h"
#include <stdio.h>
#include <stdlib.h>

int acrescentaAluno(Turma *t, Aluno a) {
    Turma novoAluno;
    int r;
    novoAluno = malloc(sizeof(NodoTurma));

    if(novoAluno){
        novoAluno->aluno = a;
        novoAluno->proxAluno = (*t);
        (*t) = novoAluno;
        r = 0;
    }
    else r = 1;
    
    return r;
}

void showTurma (Turma t) {
    while(t){
        showAluno(t->aluno);
        t = t->proxAluno;
    }
}

void showTurmaRec (Turma t) {
    if(t){
        showTurmaRec(t->proxAluno);
        showAluno(t->aluno);
    }
}

void showAluno (Aluno a) {
    printf("Nome: %30s; Número: %d; Nota: %2d.\n", a.nome, a.numeroAluno, a.nota);
}

Aluno *procura (Turma t,int numero) {
    Aluno *r = NULL;

    while(t) {
        if(t->aluno.numeroAluno == numero)r = &t->aluno;
        t = t->proxAluno;
    }

    return r;
}

int aprovados (Turma t) {
    int r = 0;

    for(t;t; t = t->proxAluno)
        if (t->aluno.nota >= 9.5)r++;

    return r;
}

int aprovadosRec (Turma t) {
    int r;
    if(t == NULL){
        return 0;
    }
    else{
        r = aprovadosRec  (t->proxAluno);
        return (t->aluno.nota >= 9.5)? 1 + r : r;   
    }
       
}