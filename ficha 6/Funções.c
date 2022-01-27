#include <stdio.h>
#include <stdlib.h>
#include "Funções.h"


// Static queues
void resetFront(SQueue q){
    int i;
    for(i = 0; i < q->length; i++)
        q->values[i] = q->values[q->front + i];
    q->front = 0;
}
void SinitQueue (SQueue q){
    q->length = 0;
    q->front = 0;
}

int  SisEmptyQ (SQueue q){
    return (q->length == 0);
}

int  Senqueue (SQueue q, int x){
    int pos;
    if (q->length<Max) {
        pos = (q->front) + (q->length) % Max;
        q->values[pos] = x;
        q->length++;
        return 0;
    }
    else return 1;

}

int  Sdequeue (SQueue q, int *x) {
    int i,r = 0;
    if(SisEmptyQ(q)) r = 1;
    else{
        *x = q->values[q->front];
        q-> front = q->front + 1 % Max;
        q->length--;
    }
    return r;
}

int  Sfront (SQueue q, int *x) {
    int r = 0;
    if(SisEmptyQ(q)) r  = 1;
    else{
        *x = q->values[q->front];
    }

    return (-1);
}

void ShowSQueue (SQueue q){
    int i, p;
    printf ("%d Items: ", q->length);
    for (i=0, p=q->front; i<q->length; i++) {
        printf ("%d ", q->values[p]);
        p = (p+1)%Max;
    }
    putchar ('\n');
}

// Queues with dynamic arrays

int dupQueue (DQueue q) {
    // ...
    return (-1);
}

void DinitQueue (DQueue q) {
    q->size = 10;
    q->length = 0;
    q->front = 0;
    q->values = malloc(q->size * sizeof(int));
}

int  DisEmptyQ (DQueue q) {
    return (q->length == 0)? 1 : 0;
}

int  Denqueue (DQueue q, int x){
    int pos,r;
    if (q->length == q->size)
        r = dupQueue(q);
    if(!r) {
        pos = (q->front) + (q->length) % q->size;
        q->values[pos] = x;
        q->length++;
    }
    return r;
}

int  Ddequeue (DQueue q, int *x){
    int i,r = 0;
    if(!DisEmptyQ(q)) r = 1;
    else{
        *x = q->values[q->front];
        q-> front = q->front + 1 % q->size;
        q->length--;
    }
    return r;
}

int  Dfront (DQueue q, int *x){
    // ...
    return (-1);
}

void ShowDQueue (DQueue q){
    int i, p;
    printf ("%d Items: ", q->length);
    for (i=0, p=q->front; i<q->length; i++) {
        printf ("%d ", q->values[p]);
        p = (p+1)%q->size;
    }
    putchar ('\n');
}