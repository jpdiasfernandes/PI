#include "ficha4.h"
#include <stdio.h>
#include <ctype.h>
#define MAX 100

typedef struct stack{
    int sp;
    int valores[MAX];
}STACK;
//1
int minusculas(char *s){
    int count = 0,i;

    for(i = 0; s[i] != 0; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] += 32;
            count++;
        }
    }
    return count;
}
//2
int contalinhas (char s[]){
    int i = 0,count = 0;
    while(s[i] != 0){
        if(s[i++] == '\n')count++;
    }
    return i? count + 1 : 0;
}
//3
int contaPal(char s[]){
    int i = 0,count = 0;
    char anterior = 0;

    while(s[i]){
        if(isspace(s[i]) && anterior != ' ' && anterior != 0) {
            count++;
        }
        anterior = s[i++];
    }
    return count;
}
//4
int iguais (char s1[], char s2[]){
    int i = 0, r = 1;
    while(s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i])i++;
    return (!s1[i] && !s2[i])? 1 : 0;
}
int procura (char p[], char *ps[], int N){
    int i, r = 0;
    for(i = 0; i < N && !iguais(p,ps[i]); i++);
    return (i == N)? 0 : i + 1;
}
//5
//a)
void initStack (STACK *s){
    s -> sp = 0;
}
//b)
int isEmptyS(STACK *s){
    return(s -> sp == 0)?1 : 0;
}
//c)
int push(STACK *s, int x){
    if(s -> sp < MAX -1){
        s -> valores[s -> sp++] = x;
        return 0;
    }
    else return 1;
}
//d)
int pop(STACK *s, int *p){
    if(!isEmptyS(s)){
        *p = s -> valores[--s->sp];
        --s -> sp;
        return 0;
    } else return 1;
}
//e)
int top(STACK *s, int *x){
    if(!isEmptyS(s)){
        *x = s -> valores[--s->sp];
        return 0;
    }
    else return 1;
}
//f) acrescentado pelo professor
void showStack(STACK *s){
    while(!isEmptyS(s)){
        printf("%d ", s -> valores[--s -> sp]);
        --s -> sp;
    }
}


