#ifndef _PARQUES
#define _PARQUES

typedef char Nome[10];

typedef struct sLlugar{
    int lugar;
    struct sLlugar *seg;
}*Llugar, NLlugar;

typedef struct sParque{
    int nlugares;
    Llugar ocupados;
    Nome nparque;
}Parque;

typedef struct sLParque{
    Parque p;
    struct sLParque *seg;
}*LParque, NLParque;

int verOcupacao(int lugar, Llugar ocupados);
void listarParque(Parque);
void listar (LParque lp);
int disponivel (LParque lp, Nome p, int lugar);
LParque estaciona (LParque lp, Nome p, int lugar);
void listardisponibilidades (LParque lp);
LParque inserirParque (LParque complexo, Parque p);
int contaOcupados(Llugar lista);
Llugar inserirLugar(Llugar ocupados, Llugar l);
LParque estacionaAux(LParque lp, Nome p, int lugar);

#endif 





























