#include <stdio.h>
#include <ctype.h>
#include "dicionario.h"

/*
    1. Tornar o buffer dinâmico;
    2. Tornar o word boundary mais inteligente.
*/

#define SIZE 200

int main()
{
    char buffer[SIZE];
    int index, c;
    Dicionario d; //já tem espaço alocado.
    initDic(&d);



    /* initalize variables */
    c = 1;                          /* avoid random EOF */
    index = 0;
    buffer[index] = '\0';

    /* process standard input */
    while(c != EOF)
    {
        c = getchar();
        if(isspace(c) || (!isalpha(c)  && c != '-' ))            /* whitespace found */
        {
            buffer[index] = '\0';
            if(*buffer)                          /* cap the string */
                acrescenta(&d, buffer);           /* display w/newline */
            index = 0;              /* reset index */
        }
        else                        /* keep filling the buffer */
        {
            buffer[index] = c;
            index++;
        }
    }
    showDic(d);
    return(0);
}