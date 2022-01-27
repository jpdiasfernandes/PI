#ifndef FICHA_7_LISTA_H
#define FICHA_7_LISTA_H
#define Max 61
struct slist {
    int valor;
    struct slist *prox;
};

typedef struct slist *LInt;

int  iguais (LInt a, LInt b);
LInt cons (LInt l, int x);
int  cons1 (LInt *l, int x);
LInt tail (LInt l);
int  tail1 (LInt *l);
LInt initRec (LInt l);
LInt init (LInt l);
int  init1 (LInt *l);
LInt snocRec (LInt l, int x);
LInt snoc (LInt l, int x);
int  snoc1 (LInt *l, int x);
LInt concatRec (LInt a, LInt b);
LInt concat (LInt a, LInt b);
void concat1 (LInt *a, LInt b);


typedef struct aluno {
    char nome[Max];
    int numero,nota;
} Aluno;

struct sturma {
    Aluno aluno;
    struct sturma *prox;
};
typedef struct sturma *Turma;

Aluno newAluno (char *nome, int numero, int nota);
Turma vazia ();

int acrescentaAluno (Turma *t, Aluno a);
Aluno * procura (Turma t, int numero);
int aprovados (Turma t);


#endif //FICHA_7_LISTA_H
