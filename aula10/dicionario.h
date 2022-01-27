#ifndef _DICIONARIO
#define _DICIONARIO

typedef struct entrada {
    char *palavra;
    int ocorr;
    struct entrada *esq, *dir;
} *Palavras, Palavra;

typedef struct sDic {
    Palavras arvore;
    int npal;
} Dicionario; //como Dicionario já é uma struct em si o compilador já aloca memória! Não é necessário alocar!

void initDic (Dicionario *d);
int acrescenta (Dicionario *d, char *pal);
void showDic (Dicionario d);
char *maisFreq (Dicionario *d, int *c);
void inserePalProc (Palavras *a, char *pal);

#endif