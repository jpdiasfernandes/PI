#include "recurso_15_16.h"
#include <string.h>
#include "../testar.h"
#include <stdlib.h>
#include <stdio.h>
//1
char *mystrcpy (char *dest, char source[]) {
    int i;
    for (i = 0; source[i]; i++)
        dest[i] = source[i];
    dest[i] = 0;
    return dest;
}
//2
void strnoV (char s[]) {
    int i, j = 0;
    for (i = 0; s[i]; i++) {
        char tmp = s[i];
        if (tmp != 'a' && tmp != 'e' && tmp != 'i' &&
            tmp != 'o' && tmp != 'U' && tmp != 'A' &&
            tmp != 'E' && tmp != 'I' && tmp != 'O' &&
            tmp != 'U') s[j++] = s[i];

    }
    s[j] = 0;
}
//3
int dumpAbin (ABin a, int v[], int N) {
    if (!a || N <= 0) return 0;
    int esq = dumpAbin(a->esq, v, N);
    if (N > esq) v[esq] = a->valor;
    else return esq;
    int dir = dumpAbin(a->dir, v + 1 + esq, N - 1 - esq);
    return esq + 1 + dir;
}
//4
int lookupAB (ABin a, int x) {
    int r = 0;
    while (a && !r) {
        if (a->valor == x) r = 1;
        else if (a->valor > x)
            a = a->esq;
        else
            a = a->dir;
    }
    return r;
}

/////////
//Parte B
/////////

//1
int inc (Hist *h, char *pal) {
    int cmp;
    while (*h && strcmp((*h)->pal, pal) < 0)
        h = &(*h)->prox;
    if (*h && strcmp((*h)->pal, pal) == 0)(*h)->cont++;
    else {
        Hist novo = malloc(sizeof (NodoHist));
        novo->pal = strdup(pal);
        novo->cont = 1;
        novo->prox = NULL;
        if (!(*h)) *h = novo;
        else {
            Hist tmp = *h;
            *h = novo;
            (*h)->prox = tmp;
        }
    }
    return ((*h)->cont);
}
//2
char *remMaisFreq (Hist *h, int *count) {
    char *pal = strdup(maisFreq(*h)); //para Hist não vazios
    while (strcmp((*h)->pal, pal) != 0) //Sabe-se que a palavra existe e que *h é n nula.
        h = &(*h)->prox;
    Hist tmp = *h;
    *h = tmp->prox;
    tmp->prox = NULL;
    *count = tmp->cont;
    strcpy(pal, tmp->pal);
    free(tmp);
    return pal;
}
char *maisFreq (Hist h) {
    int maior = 1;
    char *pal = strdup(h->pal);
    while (h) {
       if (h->cont > maior) {
           maior = h->cont;
            strcpy(pal, h->pal);
       }
       h = h->prox;
    }
    return pal;
}

//3
//Tenho código base para isto

void showHist(Hist h) {
    while (h){
        printf("%s\n ", h->pal);
        h = h->prox;
    }
}




