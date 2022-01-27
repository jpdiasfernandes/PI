#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

int main () {

    int i,a;
    Stack s1;

    initStack(&s1);
    
    for (i = 1; i <= 100; i++) {
        push(&s1, 2*i);
    }
    showStack(s1);
    
    for(i = 1; i<= 100; i+=7) {
        pop(&s1, &a);
    }

    putchar('\n');

    showStack(s1);

    


}