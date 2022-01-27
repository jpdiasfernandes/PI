#include <stdio.h>
#include "Funções.h"
void printQueue (SQueue q){
    int i;
    for(i = q->length -1; i < Max; i++){
        printf(q->values[i]);
    }
}

int main() {
    struct staticQueue s;
    SQueue q = &s;
    SinitQueue(q);
    Senqueue(q,2);
    Senqueue(q,3);
    ShowSQueue(q);
}
