#include <stdio.h>
#include "testar.h"
#include "ficha.h"
int main(){

//    [ 1 12 13 14  5 16 17 18 19 110 111 12 113 114 115 116 117 18 119 12 ]
//    [ 1  2  3  4  5  1 17 18 19 20 21 22 23 114  5 126 127 12 129 132 ]
    int s[] = {1,12,13, 14,  5, 16, 17, 18, 19, 110, 111, 12, 113, 114 ,115,116,117,18,119,12};
    int v[] = {1,  2,  3,  4,  5,  1, 17, 18, 19, 20, 21, 22, 23, 114,  5, 126, 127, 12, 129, 132 };
    Posicao r[10];
    caminho((Posicao){0,20}, (Posicao){0,15}, r, 10);
    printf("%d",comuns(s,20,v,20));

}