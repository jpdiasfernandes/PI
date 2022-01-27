#ifndef FICHA8_FUNÇÕES_H
#define FICHA8_FUNÇÕES_H

typedef struct entrada{
    char *palavra;
    int ocorr;
    struct entrada *prox;
} *Palavras;

typedef Palavras Dicionario;

void initDic(Dicionario *d);
int acrescenta (Dicionario *d, char *pal);
char *maisFreq (Dicionario d, int *c);

#endif //FICHA8_FUNÇÕES_H
