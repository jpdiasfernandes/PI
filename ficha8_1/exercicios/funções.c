#include <stdio.h>
#include <string.h>
#include "funções.h"

void initDic(Dicionario *d){
    (*d)-> palavra = NULL;
    (*d)-> ocorr = 0;
    (*d)-> prox = NULL;
}

int acrescenta (Dicionario *d, char *pal){
    int r = 0;
    while(*d != NULL){
        if(strcmp(pal,(*d)->palavra))
            r = ++(*d)->ocorr;
        (*d) = (*d)->prox;
    }

    return r;
}

char *maisFreq (Dicionario d, int *c){
    int maior_occ = 0;
    char *mais_freq;

    while(d != NULL){
        if(d->ocorr > maior_occ)
            mais_freq = d->palavra;
        d = d->prox;
    }
    *c = maior_occ;
    return mais_freq;
}
