#ifndef INC_50QUESTOES_FICHA_H
#define INC_50QUESTOES_FICHA_H
typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {
    int x, y;
} Posicao;

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt, Nodo;

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

int mystrcmp(char s1[], char s2[]);
char *mystrstr(char s1[],char s2[]);
void strnoV(char s[]);
void printString(char s[]);
void truncW(char t[], int n);
char charMaisfreq(char s[]);
int difConsecutivos(char s[]);
int remRep(char s[]);
void merge (int r[], int a[], int b[], int na, int nb);
void insere (int v[], int N, int x);
void insere1(int v[], int N, int x);
int menosFreq(int v[], int N);
int maxCresc (int v[],int N);
int elimRep(int v[],int N);
int comunsOrd (int a[],int na, int b[], int nb);
int comuns (int a[], int na, int b[], int nb);
int caminho (Posicao inicial, Posicao final, Movimento mov[], int N);
#endif //INC_50QUESTOES_FICHA_H
