#include <stdio.h>
#include "Exercicios.h"

//2
void swapM (int *x, int *y){
    int z;
     z = *x;
     *x = *y;
     *y = z;
}

//3
void swap(int v[], int i, int j){
    int t;
    t = v[i];
    v[i] = v[j];
    v[j] = t;
}

//4
int soma(int v[], int N){
    int i,soma;
    for(i = 0; i < N; i++){
       soma += v[i];
    }
}
//5
int maximum (int v[], int N, int *m){
    int maior,i,r;
    if( N < 0) return -1;
    for(i = 0; i < N; i++){
        if(i == 0)maior = v[i];
        if(v[i] > maior) maior = v[i];
    }
    *m = maior;
    return 0;
}

//6
void quadrados(int q[], int N){
    int i;
    for(i = 0; i < N; i++)
        q[i] = (q[i]*q[i]);
}

//7
void pascal(int v[], int N){
    int n,i;
    for(n = 0; n <= N; n++){
        for(i = n; i >= 0; i--){
            if(i == n || i == 0) v[i] = 1;
            else{
                v[i] = v[i] + v[i-1];
            }
        }
    }
}


