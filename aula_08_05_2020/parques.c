#include "parques.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>




void listardisponibilidades (LParque lp);

LParque inserirParque(LParque complexo, Parque p){
    LParque cres = malloc(sizeof(NLParque));

    cres->p = p;
    cres->seg = complexo;

    return cres;
}

//P1 : lugares = ..., ocupados,
void listar (LParque lp){
    printf("-------------------------------------\n");
    while(lp != NULL){
        listarParque(lp->p);
        lp = lp->seg;
    }
    
}

void listarParque (Parque p){
    printf("%s : lugares = %d, ocupados = %d\n", p.nparque, p.nlugares, contaOcupados(p.ocupados));
}

int contaOcupados(Llugar lista){
    int r =0;
    while(lista){
        r++;
        lista = lista->seg;
    }
    return r;
}

int disponivel (LParque lp, Nome p, int lugar){

    while(lp != NULL && strcmp(p,lp->p.nparque) != 0)
        lp = lp->seg;
    if(lp == NULL || lp->p.nlugares == contaOcupados(lp->p.ocupados)) return 0;
    else return (verOcupacao(lugar, lp->p.ocupados));
}

int verOcupacao(int lugar, Llugar ocupados){
    while(ocupados && lugar != ocupados->lugar)
        ocupados = ocupados->seg;

    return (ocupados == NULL)? 1 : 0;

}

LParque estaciona (LParque lp, Nome p, int lugar){
    if(disponivel(lp,p,lugar))
        return estacionaAux(lp,p,lugar);
    else return lp;
}

LParque estacionaAux(LParque lp, Nome p, int lugar){

    Llugar novo = malloc(sizeof(NLlugar));
    novo->lugar = lugar;

    LParque lpaux = lp;

    while(strcmp(p,lpaux->p.nparque) != 0)
        lpaux = lpaux->seg;
    
    lpaux->p.ocupados = inserirLugar(lpaux->p.ocupados, novo);

    return lp;
}

Llugar inserirLugar(Llugar ocupados, Llugar l){
    if(ocupados == NULL || ocupados->lugar > l->lugar){
        l->seg = ocupados;
        return l;
    }
    else {
        ocupados->seg = inserirLugar(ocupados->seg,l);
        return ocupados;
    }
    
}
