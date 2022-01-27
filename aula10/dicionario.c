#include "dicionario.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void initDic (Dicionario *d) { // Neste caso este endereço já tem espaço alocado.
    d->arvore = NULL;           // Não é preciso fazer malloc.
}


Palavras existePal (Palavras l, char *pal) {
    if (!l) return NULL;
    int res = strcmp(l->palavra, pal);
    if (res == 0) return l;
    if (res > 0) return existePal (l->esq, pal);
    else return existePal (l->dir, pal);
}


void inserePalProc (Palavras *a, char *pal) {
    Palavras palPtr, novo;
    if (palPtr = existePal(*a, pal))
        palPtr->ocorr++;
    else {
        novo = malloc(sizeof (Palavra));
        novo->palavra = strdup(pal); //o strdup aloca o espaço da string com length (pal) + 1 e retorna essa string.
        novo->ocorr = 1;             // se não o usasse tinha que alocar com malloc por exemplo e preencher manualmente a string;
        novo->esq = NULL;
        novo->dir = NULL;

        if (!(*a)) *a = novo;
        else {
            while (*a) {
                if (strcmp((*a)->palavra, pal) > 0) {
                    if (!(*a)->esq) {
                        (*a)->esq = novo;
                        break;
                    }
                    else a = &(*a)->esq;
                } else {
                    if (!(*a)->dir) {
                        (*a)->dir = novo;
                        break;
                    }
                    else a = &(*a)->dir;
                }
            }
        }
    }
}

int acrescenta (Dicionario *d, char *pal) {
    inserePalProc(&(d->arvore), pal);
    return 0;
}

void showPalavras (Palavras pals) {
    if (pals) {
        showPalavras(pals->esq);
        printf ("%s : %d\n", pals->palavra, pals->ocorr);
        showPalavras(pals->dir);
    }
}
void showDic (Dicionario d) {
    if (d.arvore) showPalavras(d.arvore);
}

