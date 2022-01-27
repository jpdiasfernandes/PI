#include <stdio.h>
#include "exercicios/funções.h"
int main (int argc, char *argv[]){
    FILE *input;
    Dicionario dic;
    int r=0, count=0;
    char word[1024];
    char *mais_freq;

    initDic(&dic);

    if (argc==1) input=stdin;
    else input=fopen(argv[1],"r");
    if (input==NULL) r=1;
    else {
        while ((fscanf(input,"%s",word)!=EOF))
            acrescenta(&dic, word);
        fclose (input);
        mais_freq = maisFreq(dic, &count);
        printf ("A palavra mais recorrente é %s com %d ocorrencias.\n", mais_freq, count);
    }
    return r;
}

