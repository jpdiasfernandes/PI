#include "exercicios.h"
#include <stdio.h>

void swap (int v[], int i, int j){
    int t=v[i];
    v[i]=v[j]; v[j]=t;
}

/////// Insertion Sort

void insere (int v[], int N, int x){
    int i,j;
    for (i = 0; i < N && v[i] < x; i++);
    for (j = N; j != i; j--) {
        v[j] = v[j-1];
    }
    v[i] = x;

}

void iSort1 (int v[], int N) {
    //fazer um sort qualquer
}

void iSort2 (int v[], int N){
    // semelhante ao anterior, mas sem usar a função insert
}


////// Max Sort ///////

int maxInd (int v[], int N){
    // calcula o ídice do maior elemento do array v

    return 0;
}

void maxSort1 (int v[], int N) {
    // ordena o array por sucessivas invocações da função maxInd
}

void maxSort2 (int v[], int N) {
    // semelhante ao anterior, mas sem usar a função maxInd

}


////// Bubble Sort ///////

int bubble (int v[], int N) {
    int i, r=0;
    for (i=1; i<N; i++)
        if (v[i] < v[i-1]) {
            swap (v, i, i-1);
            r=i;
        }
    return r; // última posição trocada
}

void bubblesort1 (int v[], int N){
    // ordena o array por sucessivas invocações da função bubble
}

void bubblesort2 (int v[], int N){
    // optimização do procedimento anterior que pára mal o array esteja ordenado
}

