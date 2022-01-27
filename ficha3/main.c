#include <stdio.h>
#include "Exercicios.h"

int main(){
    int* x,y;
    int a = 1, b = 3;
    int v[8];
    pascal(v,7);
    for(int i = 0; i < 8; i++){
        printf("%d ", v[i]);
    }
}


