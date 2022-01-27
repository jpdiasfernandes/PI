#include <stdio.h>
#include <stdlib.h>
#include "llint.h"

int main (){

    LInt l, aux;
    l = NULL;
    aux = NULL;

    int i;
    for(i = 1; i <= 5; i++)
        l = cons(l,i);

    showLInt(l);

    for(i = 1; i <= 5; i++)
        aux = snoc(aux,i);
    
    showLInt(aux);

    l = concat(l,aux);

    showLInt(l);

    return 0;

}
