#include "parques.h"
#include <stdlib.h>

int main(){
    Parque p1 = {600, NULL, "P1"},
           p2 = {1500, NULL, "P2"},
           p6 = {200, NULL, "P6"};
    
    LParque universidade = NULL;

    universidade = inserirParque(universidade, p1);
    universidade = inserirParque(universidade, p2);
    universidade = inserirParque(universidade, p6);

    listar(universidade);

    int i;

    for(i = 0; i < 500; i++) {
        universidade = estaciona(universidade, "P1", i);
        universidade = estaciona(universidade, "P2", 2*i);
        universidade = estaciona(universidade, "P2", i);
        universidade = estaciona(universidade, "P6", i);
    }
    listar(universidade);
    //if(disponivel(universidade, "P1", 23))
      //  universidade = estaciona( universidade, "P1", 23);
    
    //listardisponibilidades(universidade);

    return 0;
}