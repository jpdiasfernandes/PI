#ifndef _ABIN
#define _ABIN

typedef struct sAbin {
    int valor;
    struct sAbin *esq, *dir;
} *ABin, NodoABin;

int peso (ABin a);
ABin insABin (ABin a, int x);
void inorder (ABin a);
void preorder (ABin a);
void posorder (ABin a);
int nodo (ABin a);
int balanceada (ABin a);

#endif