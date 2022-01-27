#include "abin.h"
#include <stdlib.h>
#include <stdio.h>

int main () {
    ABin a1 = NULL;

    int x[9] = {23, 17, 2, 19, 38, 31, 50, 60, 70};

    int i;

    for(i = 0; i < 9; i++)
        a1 = insABin(a1, x[i]);
    
    printf("InOrder: ");
    inorder(a1);
    printf("\nPreOrder: ");
    preorder(a1);
    printf("\nPosOrder: ");
    posorder(a1);
    printf("\nPeso: %d\n", peso(a1));
    a1 = insABin(a1, 46);
    printf("Está balanceada?: %d\n", balanceada(a1));
    a1 = insABin(a1, 1);
    printf("Está balanceada?: %d\n", balanceada(a1));
    printf("\nPreOrder: ");
    
    preorder(a1);
    return 0;
}