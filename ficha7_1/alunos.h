#ifndef _ALUNOS
#define _ALUNOS

typedef struct aluno {
    char nome[61];
    int numeroAluno;
    int nota;
} Aluno;

typedef struct turma *Turma;

typedef struct turma {
    Aluno aluno;
    Turma proxAluno;
} NodoTurma;

int acrescentaAluno (Turma *t, Aluno a);
void showTurma (Turma t);
void showTurmaRec (Turma t);
void showAluno (Aluno a);
Aluno *procura (Turma t, int numero);
int aprovados (Turma t);
int aprovadosRec (Turma t);
#endif