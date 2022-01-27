#include <stdio.h>
#include "ficha4.h"
#define MAX 100
typedef struct stack {
    int sp;
    int valores [MAX];
} STACK;

int main() {
    char *ps[] = {"", "fjdhdjfh", "Ola", "   "};
    char *p = "Ola";
    printf("%d",procura(p, ps, 4));
    STACK numeros = {5, {13,20,5,7}};


}
