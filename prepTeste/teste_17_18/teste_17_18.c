#include "teste_17_18.h"
#include <stdio.h>
#include <stdlib.h>
//1
int retiraNeg (int v[], int N) {
    int i, j = 0;

    for (i = 0; i < N; i++)
        if (v[i] >= 0) v[j++] = v[i];

    return j;
}
//2
int pertence (char s[], int pos, int tamanho){
    for(int i = pos-tamanho; i < pos; i++){
        if(s[pos] == s[i])return 1;
    }
    return 0;
}
int difConsecutivos (char s[]){
    int i, maior = 0, subString = 0;

    for(i = 0; s[i] != '\0'; i++){
        if(!pertence(s,i,subString)){
            subString++;
            if(subString > maior) maior = subString;
        }
        else {
            i = i - subString + 1;
            subString = 1;
        }
    }
    return maior;
}
//3 facil
//4 facil
//5 facil


//Parte b
//1
int minheapOK (ABin a) {
    if (!a) return 1;
    int esq = minheapOK(a->esq);
    int dir = minheapOK(a->dir);
    if (esq && dir) {
        if (!a->esq && !a->dir) return 1;
        if (a->esq && a->dir)
            return (a->valor < a->dir->valor &&
                    a->valor < a->esq->valor) ? 1 : 0;
        if (!a->esq) return (a->valor < a->dir->valor) ? 1 : 0;
        if (!a - dir) return (a->valor < a->esq->valor) ? 1 : 0;
    }
}


