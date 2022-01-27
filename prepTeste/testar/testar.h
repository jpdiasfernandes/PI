#ifndef TESTAR_TESTAR_H
#define TESTAR_TESTAR_H
typedef struct slist {
    int valor;
    struct slist *prox;
} *LInt;

typedef struct aluno {
    char nome[50];
    int numero;
    int nota; //>= 0, <=20
    struct aluno *esq, *dir;
} *Alunos;

typedef struct strlist {
    char *string;
    struct strlist *prox;
} *StrList;

typedef struct abin {
    int valor;
    struct abin *esq, *dir;
} *ABin, NodoABin;

typedef struct listaC {
    int coluna;
    float valor;
    struct listaC *prox;
} *Colunas;

typedef struct listaL {
    int linha;
    Colunas lcol;
    struct listaL *prox;
} *Mat;

typedef struct listaP {
    char *pal;
    int cont;
    struct listaP *prox;
} NodoHist, *Hist;

typedef struct chunk {
    int vs [3];
    struct chunk *prox;
} *CList;

typedef struct stackC {
    CList valores;
    int sp;
} StackC;

typedef struct dlist {
    int valor;
    struct dlist *ant, *prox;
} NodoD;

typedef struct {
    NodoD *front, *last;
} DLint;
typedef struct nodo { char *raiz; int quantos; struct nodo *esq, *dir; } *Palavras;
#endif //TESTAR_TESTAR_H
