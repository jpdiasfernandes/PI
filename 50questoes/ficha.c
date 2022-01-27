#include "ficha.h"
#include <stdio.h>
#include <stdlib.h>

//Função que imprime uma string
void printString(char s[]){
    for(int i = 0; s[i] != '\0'; i++)
        printf("%c", s[i]);
}

//9
int mystrcmp(char s1[],char s2[]){
    int i = 0;

    while(s1[i] != '\0' && s2[i] != '\0'){
        if(s1[i] > s2[i]) return 1;
        else if (s1[i] < s2[i]) return -1;
        i++;
    }
    if(s1[i] == '\0' && s2[i] == '\0') return 0;
    else if (s1[i] == '\0') return  -1;
    return 1;
}
//10
char *mystrstr(char s1[], char s2[]){
    int i, j = 0, index;
    if(s1[0] == '\0' && s2[0] == '\0')return s1;

    for(i = 0; s1[i] != '\0' || s1[i] == s2[j]; i++){
        if(s1[i] == s2[0]){
            index= i;
            for(j = 0; s1[i] == s2[j]; j++){
                if(s1[index] == '\0' && s2[j] == '\0')break;
                index++;
            }
            if(s2[j] == '\0') return (s1 + i);
        }
    }
    return NULL;
}
//11
void strrev (char s[]){
    int i = 0, j = 0;

    for (i; s[i] != '\0'; i++);
    int x[i + 1];

    for(--i; i >= 0; i--) {
        x[j] = s[i];
        j++;
    }

    for(i = 0; s[i] != '\0'; i++)
        s[i] = x[i];
}
//12
void strnoV(char s[]){
    int i,j = 0;
    for( i = 0; s[i] != '\0'; i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'
        || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
            s[i] = '\0';
        }
        else{
            s[j] = s[i];
            j++;
        }
    }
    s[j] = '\0';
}
//13
void truncW(char s[], int n){
    int i,j = 0,letra = 0;
    for(i = 0; s[i] != '\0'; i++){
        if(s[i] == ' '){
            letra = 0;
            s[j] = s[i];
            j++;
        }
        else if(letra < n){
            s[j] = s[i];
            letra++;
            j++;
        }
    }
    s[j] = '\0';
}
//14
char charMaisfreq(char s[]){
    int maior = 0, i, arr[256] = {0};
    char cmaior = 0;

    for(i = 0; s[i] != '\0'; i++){
        arr[s[i]]++;
    }

    for(i = 0; i < 256; i++){
        if(arr[i] > maior){
            maior = arr[i];
            cmaior = i;
        }
    }
    return cmaior;
}
//15
int iguaisConsecutivos (char s[]){
    int i,maior = 0, countString = 0;
    char cprocura;
    for(i = 0; s[i] != '\0'; i++){
        if(i == 0)cprocura = s[i];
        if(s[i] == cprocura){
            countString++;
            if(countString > maior) maior = countString;
        }
        else{
            countString = 1;
            cprocura = s[i];
        }
    }
    return maior;
}
//16
int pertence (char s[], int pos, int tamanho){
    for(int i = pos-tamanho; i < pos; i++){
        if(s[pos] == s[i])return 1;
    }
    return 0;
}
int difConsecutivos (char s[]){
    int i, maior = 0, subString = 0;

    for(i = 0; s[i] != '\0'; i++){
        if(!pertence(s,i,subString)){
            subString++;
            if(subString > maior) maior = subString;
        }
        else {
            i = i - subString + 1;
            subString = 1;
        }
    }
    return maior;
}
//17
int maiorPrefixo(char s1[],char s2[]){
    int i = 0;
    while(s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')i++;
    return i;
}
//18
int tamanhoString(char s[]){
    int i;
    for(i = 0; s[i]!= 0; i++);
    return i;
}
int maiorSufixo(char s1[],char s2[]){
    int tamanho1 = tamanhoString(s1) , tamanho2 = tamanhoString(s2);
    int i = tamanho1 - 1, j = tamanho2 - 1;
    while(i >= 0 && j >= 0 && s1[i] == s2[j]){
        j--;
        i--;
    }
    return(tamanho1 - (++i));
}
//19
int preSufIguais(char s1[], char s2[], int pos, int tamanho){
    int i, j = 0;
    for (int i = pos; s1[i] != '\0' && s1[i] == s2[j] && s2[j] != '\0'; ++i)j++;
    if(j == tamanho - pos) return j;
    else return 0;
}
int sufPref(char s1[], char s2[]){
    int i,r = 0;
    for(i = 0; s1[i] != '\0'; i++) {
        int r = preSufIguais(s1,s2,i, tamanhoString(s1));
        if(r != 0) return r;
    }
    return r;
}
//20
int contaPal(char s[]){
    int i, count;
    char anterior = s[0];
    if(s[0] == ' ' || s[0] == '\n' || s[0] == 0)count = 0;
    else count = 1;

    for(i = 0; s[i] != 0; i++) {
        if (s[i] != ' ' && anterior == ' ' && s[i] != '\n')
            count++;

        anterior = s[i];
    }
    return count;
}
//21
int contaVogais(char s[]){
   int i, count = 0;

   for(i = 0; s[i] != 0; i++) {
       if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'
           || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')count++;
   }
   return count;
}
//22
int elem (char s[], char x){
    int i, r= 0;
    for(i = 0; s[i] != '\0'; i++) {
        if (s[i] == x) r = 1;
    }
    return r;
}
int contida(char a[], char b[]){
    int i;

    for(i = 0;  elem(b, a[i]) == 1 && a[i] != 0; i++);
    if(a[i] == 0)return 1;
    else return 0;
}
//23

int palindorome (char s[]){
    int j = tamanhoString(s) - 1;
    int i,k  = 1;
    int r = 0;

    for(i = 0; i <= j || s[i] != '\0';){
        if(s[i++] != s[j--]) return 0;
    }
    return k;
}
//24
int remRep(char s[]){
    int i,j = 0;
    char aux[tamanhoString(s) + 1];
    char anterior = 0;

    for(i = 0; s[i] != 0; i++){
        if(anterior != s[i])aux[j++] = s[i];
        anterior = s[i];
    }
    aux[j] = '\0';
    for(i = 0; s[i] != 0; i++)
        s[i] = aux[i];

    return tamanhoString(s);
}
//25
int limpaEspacos (char s[]){
    int i = 0, j = 0;
    char anterior = 0;

    for(i; s[i] != 0; i++){
        if(s[i] != anterior || anterior != ' ')
            s[j++] = s[i];

        anterior = s[i];
    }
    s[j] = '\0';
    return tamanhoString(s);
}
//26
void insere (int v[], int N, int x){
    int i = 0, anterior;

    for(i; i < N; i++){
        if(x <= v[i]){
            anterior = x;
            for(i; i <= N; i++){
                int temp;
                temp = v[i];
                v[i] = anterior;
                anterior = temp;
            }
        }
    }
}
void insere1 (int v[], int N, int x){
    int i = 0, j = 0;
    int aux[N+1];
    for(i; i < N; i++){
        if(x <= v[i] && i==j){
            aux[j++] = x;
        }
        aux[j] = v[i];
        j++;
    }
    if(i == j)aux[j] = x;

    for(i = 0; i <= N; i++)v[i] = aux[i];
}
//27
void merge (int r[], int a[], int b[], int na, int nb){
    int i = 0, j = 0;
    for(i; i < na; i++)r[i] = a[i];
    for(j; j < nb; j++)insere(r,i++,b[j]);
}
//28
int crescente(int v[], int i, int j){
    int r = 0;
    int anterior = v[i];
    for(i; i <= j; i++){
        if(anterior > v[i]){
            r = 0;
            break;
        }
        r = 1;
        anterior = v[i];
    }
    return r;
}
//29
int retiraNeg(int v[], int N){
    int i,j = 0;
    for(i = 0; i < N; i++){
        if(v[i] >= 0) v[j++] = v[i];
        else v[i] = 0;
    }
    return j;
}
//30
int menosFreq(int v[], int N){
    //Tentar experimentar usar structs
    int i,r = v[0],count = 0,menor = N, anterior = v[0];

    for(i = 0; i < N; i++){
        if(v[i] != anterior){
            if(count < menor){
                menor = count;
                r = v[i-1];
            }
            count = 1;
        }
        else count++;
        if(i == N-1){
            if(count < menor)
                r = v[i];
        }
        anterior = v[i];
    }
    return r;

}
//31
int maisFreq(int v[],int N){
    int i, r = v[0], count = 0, maior = 0, anterior = v[0];

    for(i = 0; i < N; i++){
        if(v[i] != anterior){
            if(count > maior){
                maior = count;
                r = v[i-1];
            }
            count = 1;
        }
        else count++;
        if(i == N -1){
            if(count > maior)r = v[i];
        }
        anterior = v[i];
    }
    return r;
}
//32
void maxCrescAux (int v[], int N,int x[], int index){
    int count = 0;
    while(index < N - 1 && v[index] <= v[index + 1]){
        count++;
        index++;
    }
    if(index == N - 1 && v[index -1] <= v[index]){
        count++;
        index++;
    }
    else {
        index++;
        count++;
    }
    x[0] = index;
    x[1] = count;
}
int maxCresc (int v[],int N){
    int i = 0, maior = 0;
    int aux[2] = {0,0};

    while(i<N){
        maxCrescAux(v,N,aux,i);
        if(aux[1]> maior){
            maior = aux[1];
        }
        i = aux[0];
    }
    return maior;
}
//33
int elimRep(int v[],int N){
    int j = 0,temp = 0,i = 0;
    v[j++] = v[i];
    for(i = 1; i < N; i++){
        while(temp < i && v[temp] != v[i])temp++;
        if(temp == i)v[j++] = v[i];
        temp = 0;
    }
    return (j);
}
//34
int elimRepOrd(int v[],int N){
    int j = 0, i = 0;
    v[j++] = v[i];

    for(i = 1; i < N; i++){
        if(v[i] != v[i -1])v[j++] = v[i];
    }
    return j;
}
//35
int comunsOrd (int a[],int na, int b[], int nb){
    int i = 0,j = 0,res = 0,aux[nb] ;
    for(i = 0; i < nb;i++)aux[i]= 0;

    for(i= 0; i < na; i++){
        while(j < nb && b[j] < a[i])j++;
        if(b[j] == a[i] && !aux[j]){
            res++;
            aux[j++] = 1;
        }
    }
    return res;
}
//36
int retiraIndex(int v[], int N, int index){
    int j = 0, i = 0, res;

    for(i = 0; i < N; i++){
        if(i != index)v[j++] = v[i];
    }
    return j;
}
int comuns (int a[], int na, int b[], int nb){
    int i = 0, j = 0, aux[nb], tamAux = nb, res = 0;

    for(i = 0; i < nb; i++)aux[i] = b[i];

    for(i = 0; i < na; i++){
        while(j < tamAux && a[i] != aux [j])j++;
        if(j != tamAux){
            res++;
            tamAux = retiraIndex(aux,tamAux,j);
        }
        j = 0;
    }
    return  res;
}
//37
int minInd(int v[], int N){
    int i, index = 0, menor = v[0];

    for(i = 1; i < N; i++){
        if(v[i] < menor){
            menor = v[i];
            index = i;
        }
    }
    return index;
}
//38
int somaAc(int v[], int Ac[], int N){
    int i, acc = 0;
    for(i = 0; i < N; i++){
        acc += v[i];
        Ac[i] = acc;
    }
}
//39
int triSUp (int N, float m[N][N]){
    int l,c, res = 1;
    for(l = 1; l < N; l++){
        for(c = 0; c < l && m[l][c] == 0; c++);
        if(c == l)res *= 1;
        else res *= 0;
    }
    return res;
}
//40
void transposta (int N, float m[N][N]){
    int l,c;
    for(l = 0; l < N; l++){
        for(c = 0; c <= l; c++){
            int temp;
            temp = m[l][c];
            m[l][c] = m[c][l];
            m[c][l] = temp;
        }
    }
}
//41
void addTo (int N, int M, int a[N][M], int b[N][M]){
    int l,c;
    for(l = 0; l < N; l++){
        for(c = 0; c < M; c++)a[l][c] += b[l][c];
    }
}
//42
int unionSet (int N, int v1[N], int v2[N], int r[N]) {
    int i;

    for (i = 0; i < N; i++)
        if(v1[i] || v2[i]) r[i] = 1;
        else r[i] = 0;

    return (i)? 1 : 0;
}
//43
int intersectSet (int N, int v1[N], int v2[N], int r[N]) {
    int i;

    for (i = 0; i < N; i++)
        if(v1[i] && v2[i]) r[i] = 1;
        else r[i] = 0;

    return i? 1 : 0;
}
//44
int minInt (int x, int y) {
    return (x < y)? x : y;
}
int intersectMSet (int N, int v1[N], int v2[N], int r[N]) {
    int i;

    for (i = 0; i < N; i++)
        if (v1[i] && v2[i]) r[i] = minInt (v1[i], v2[i]);
        else r[i] = 0;

    return i? 1 : 0;
}
//45
int maxInt (int x, int y) {
    return (x > y)? x : y;
}
int unionMSet (int N, int v1[N], int v2[N], int r[N]) {
    int i;

    for (i = 0; i < N; i++)
        if (v1[i] || v2[i]) r[i] = maxInt (v1[i], v2[i]);
        else r[i] = 0;

    return i? 1 : 0;
}
//46
int cardinalMSet (int N, int v[N]) {
    int i,r = 0;

    for (i = 0; i < N; i++)
        r += v[i];

    return r;
}
//47
Posicao posFinal (Posicao inicial, Movimento mov[], int N) {
    int i;

    for (i = 0; i < N; i++) {
        switch (mov[i]) {
            case Norte :
                inicial.y++;
                break;
            case Sul :
                inicial.y--;
                break;
            case Oeste :
                inicial.x--;
                break;
            case Este :
                inicial.x++;
                break;
            default: break;
        }
    }

    return inicial;
}
//48
void showPos (Movimento mov){
    switch (mov) {
        case Norte : printf("Norte\n");
            break;
        case Sul : printf("Sul\n");
            break;
        case Oeste : printf("Oeste\n");
            break;
        case Este : printf("Este\n");
            break;
    }
}
int caminho (Posicao inicial, Posicao final, Movimento mov[], int N) {
    int difx = final.x - inicial.x;
    int dify = final.y - inicial.y;
    int preenchidos = 0;
    int i;

    if (difx > 0) {
        for (i = 0; i < difx && preenchidos < N; i++)
            mov[preenchidos++] = Este;
    }
    else if (difx < 0) {
        for (i = 0; i < maxInt(difx, -difx) && preenchidos < N; i++)
            mov[preenchidos++] = Oeste;
    }

    if (dify > 0) {
        for (i = 0; i < dify && preenchidos < N; i++) {
            mov[preenchidos++] = Norte;
        }
    }
    else if (dify < 0) {
        for (i = 0; i < maxInt(dify,-dify) && preenchidos < N; i++)
            mov[preenchidos++] = Sul;
    }
    return (maxInt(difx,-difx) + maxInt(dify , -dify) <= N)? preenchidos : -1;
}
//49
int absInt (int x) {
    return (x < 0)? -x : x;
}
int distO (Posicao pos) {
    return absInt(pos.x) + absInt(pos.y);
}
int maisCentral (Posicao pos[], int N) {
    int i, min, minIndex;

    if (!N) return -1;
    min = distO(pos[0]);
    minIndex = 0;
    for (i = 0; i < N; i++) {
        int tmp = distO(pos[i]);
        if (tmp < min) {
            min = tmp;
            minIndex = i;
        }
    }

    return minIndex;
}
//50
int pertencePos (Posicao p, Posicao pos[], int N) {
    int i, r = 0;

    for (i = 0; i < N; i++)
        if(p.x == pos[i].x && p.y == pos[i].y)r++;

    return r;
}
int difPos (Posicao p1, Posicao p2) {
    return absInt(p1.x - p2.x) + absInt(p1.y - p2.y);
}
int vizinhos (Posicao p, Posicao pos[], int N) {
    int i,j, r = 0;

    for (i = p.x - 1; i <= p.x + 1; i++)
        for (j = p.y -1; j <= p.y + 1; j++) {
            int tmp = pertencePos((Posicao){i,j}, pos, N);
            if (difPos(p, (Posicao) {i, j}) == 1 && tmp )r += tmp;
        }


    return r;
}
//51
int length (LInt lista) {
    int r;

    for (r = 0; lista != NULL; lista = lista->prox)r++;

    return r;
}
//52
void freeL (LInt l) {
    LInt tmp;
    while (l) {
        tmp = l;
        l = l->prox;
        free(tmp);
    }
}
//53
void imprimeL (LInt l) {
    while (l) {
        printf("%d\n", l->valor);
        l = l->prox;
    }
}
//54
LInt reverseL (LInt l) {
    LInt ant = NULL, aux = l;

    while (aux) {
        aux = aux->prox;
        l->prox = ant;
        ant = l;
        l = aux;
    }

    return ant;
}
//55
void insertOrd (LInt *l, int x) {
    LInt novo = malloc (sizeof(Nodo));
    novo->valor = x;
    while (*l && (*l)->valor < x) {
            l = &((*l)->prox);
    }
    novo->prox = *l;
    *l = novo;
}
//56
int removeOneOrd (LInt *l, int x) {
    LInt tmp;
    while (*l && (*l)->valor != x)
        l = &((*l)->prox);
    if (*l) {
        tmp = *l;
        *l = (*l) -> prox;
        free(tmp);
        return 0;
    }
    return 1;
}
//57
void merge1 (LInt *r, LInt a, LInt b) {
    *r = a;
    while (b) {
        insertOrd(r, b->valor);
        b = b->prox;
    }
}
//58
void splitQS (LInt l, int x, LInt *mx, LInt *Mx) {
    LInt tmp;
    while (l) {
        tmp = l;
        l = l->prox;
        tmp->prox = NULL;
        if (tmp->valor < x) {
            *mx = tmp;
            mx = &((*mx)->prox);
        }
        else {
            *Mx = tmp;
            Mx = &((*Mx)->prox);
        }
    }
}
//59
LInt parteAmeio (LInt *l) {
    int count = 0;
    LInt tmp = *l;
    LInt *r = &tmp;
    LInt l1 = NULL;

    while (tmp) {
        count++;
        tmp = tmp->prox;
    }
    count *= 0.5;
    if(count) {
        l1 = *l;
        while (count != 0) {
            tmp = *l;
            *l = (*l)->prox;
            *r = tmp;
            tmp->prox = NULL;
            r = &((*r)->prox);
            tmp = tmp->prox;
            count--;
        }
    }

    return l1;
}
//60
int removeAll (LInt *l, int x) {
    int r = 0;
    while (*l) {
        if ((*l)->valor == x) {
            (*l) = (*l)->prox;
            r++;
        }
        else l = &((*l)->prox);
    }
}
//61
void removeDups (LInt *l) {
    while (*l) {
        removeAll((*l)->prox, (*l)->valor);
        (*l) = (*l)->prox;
    }
}
//62
//Para listas não vazias!
int maiorL (LInt *l) {
    int maior = (*l)->valor;

    while (*l) {
        if ((*l)->valor > maior) maior = (*l)->valor;
        l = &((*l)->prox);
    }

    return maior;
}
int removeMaiorL (LInt *l) {
    int maior = maiorL(l);
    int r;
    while (*l && (*l)->valor != maior)
        l = &((*l)->prox);
    r = (*l)->valor;
    *l = (*l)->prox;

    return r;

}
//63
void init (LInt *l) {
    while ((*l)->prox)
        l = &((*l)->prox);

    LInt tmp = (*l);
    *l = NULL;
    free(tmp);
}
//64
void appendL (LInt *l, int x) {
    LInt novo = malloc(sizeof(Nodo));
    novo->prox = NULL;
    novo->valor = x;

    while (*l)
        l = &((*l)->prox);

    *l = novo;
}
//65
void concatL (LInt *a, LInt b) {
    while (*a)
        a = &((*a)->prox);

    *a = b;
}
//66
LInt cloneL (LInt l) {
    LInt r = NULL;

    while (l) {
        appendL(&r, l->valor);
        l = l->prox;
    }

    return r;
}
//67
//Criar uma nova lista é alocar espaço? Sem compromoter com a outra lista?
LInt cloneRev (LInt l) {
    LInt r,novo = r = NULL;

    while (l) {
        novo = malloc(sizeof(Nodo));
        novo->valor = l->valor;
        novo->prox = r;
        r = novo;
        l = l->prox;
    }

    return r;
}
//68
int maximo (LInt l) {
    int max = l->valor; //Lista não vazia...

    while (l) {
       if (l->valor > max) max = l->valor;
       l = l->prox;
    }

    return max;
}
//69
int LLength (LInt l) {
    int r = 0;

    while (l) {
        r++;
        l = l->prox;
    }

    return r;
}

int take (int n, LInt *l) {
    int length = LLength (*l);
    int i, r = 0;
    LInt tmp;

    if (length <= n) return length;
    else {
        for (i = 1; i <= length; i++) {
            if (i > n) {
                tmp = *l;
                *l = (*l)->prox;
                free(tmp);
            }
            else {
                l = &((*l)->prox);
                r++;
            }
        }

        return r;
    }
}
//70
//Remove nodo de lista não vazia
void removeNodo (LInt *l) {
    LInt tmp = *l;
    *l = (*l)->prox;
    free(tmp);
}
int drop (int n, LInt *l) {
    int length = LLength(*l);
    int i;
    LInt tmp;

    n = (length <= n)? length : n;

        for (i = 1; i <= n; i++)
           removeNodo(l);

    return n;
}
//71
LInt Nforward (LInt l, int N) {
    int i;

    for (i = 0; i < N; i++)
        l = l->prox;

    return l;
}
//72
int listToArray (LInt l, int v[], int N) {
    int i = 0;

    while (l && i < N) {
        v[i++] = l->valor;
        l = l->prox;
    }

    return i;
}
//73
LInt arrayToList (int v[], int N) {
    int i;
    LInt l = NULL;

    for (i = 0; i < N; i++)
        appendL(&l, v[i]);

    return l;
}
//74
LInt somaAcL (LInt l) {
    int c = 0;
    LInt r = NULL;

    while (l) {
        c += l->valor;
        appendL(&r, c);
        l = l->prox;
    }

    return r;
}
//75
void remreps (LInt l) {
    LInt tmp;

    while (l) {
        if (l->prox && l->valor == l->prox->valor) {
            tmp = l->prox;
            l->prox = tmp->prox;
            free(tmp);
        }
        else l = l->prox;
    }
}
//76
LInt rotateL (LInt l) {
    if (!l || !l->prox) return l;
    else {
        LInt tmp = l->prox;
        LInt first = l;
        first->prox = NULL;

        while (l->prox)
            l = l->prox;
        first->prox = NULL;
        l->prox = first;
    }
}
//77
LInt parte (LInt imp) {
    LInt par = NULL;
    LInt *sitioImp = &imp;
    LInt *sitioP = &par;
    LInt tmp;

    while (*sitioImp && (*sitioImp)->prox) {
        sitioImp = &((*sitioImp)->prox);
        tmp = *sitioImp;
        *sitioImp = (*sitioImp)->prox;
        tmp->prox = NULL;
        *sitioP = tmp;
        sitioP = &((*sitioP)->prox);
    }

    return par;
}
//Arvores Binárias
//78
int altura (ABin a) {
    if (a == NULL) return 0;
    else return 1 + maxInt(altura(a->esq), altura(a->dir));
}
//79
ABin cloneAB (ABin a) {
    ABin r;
    if (a == NULL) return NULL;
    else {
        r = malloc(sizeof(struct nodo));
        r->valor = a->valor;
        r->esq = cloneAB(a->esq);
        r->dir = cloneAB(a->dir);

        return r;
    }
}
//80
void mirror (ABin *a) {
    if ((*a) != NULL) {
        ABin tmp;
        tmp = (*a)->esq;
        (*a)->esq = (*a)->dir;
        (*a)->dir = tmp;
        mirror(&(*a)->esq);
        mirror(&(*a)->dir);
    }
}
//81
void inorderAux (ABin a, LInt *l) {
    if (a) {
        inorderAux(a->esq, l);
        appendL(l, a->valor);
        inorderAux(a->dir, l);
    }
}
void inorder (ABin a, LInt *l) {
    *l = NULL;
    inorderAux(a, l);
}
//82
void preorderAux (ABin a, LInt *l) {
    if (a) {
        appendL(l, a->valor);
        preorderAux(a->esq, l);
        preorderAux(a->dir, l);
    }
}
void preorder (ABin a, LInt *l) {
    *l = NULL;
    preorderAux(a, l);
}
//83
void posorderAux (ABin a, LInt *l) {
    if (a) {
        posorderAux(a->esq, l);
        posorderAux(a->dir, l);
        appendL(l, a->valor);
    }
}
void posorder (ABin a, LInt *l) {
    *l = NULL;
    posorderAux(a, l);
}
//84
//Ainda não percebi olhar melhor!
int depth(ABin a, int x) {
    if(!a) return -1;

    if(a->valor == x) return 1;

    int esq = depth(a->esq,x);
    int dir = depth(a->dir,x);

    if(esq == -1 && dir == -1) return -1;
    if(esq == -1) return 1 + dir;
    if(dir == -1) return 1 + esq;
    return esq < dir ? 1 + esq : 1 + dir;
}
//85
int freeAB (ABin a) {
    if (a == NULL) return 0;
    else {
        int esq = freeAB(a->esq);
        int dir = freeAB(a->dir);

        free(a);
        return (1+esq+dir);
    }
}
//86
int pruneAB (ABin *a, int l) {
    if (!(*a)) return 0;
    else {
        if (l == 0) {
            int r = freeAB(*a);
            (*a) = NULL;
            return r;
        }
        else {
            l--;
            return (pruneAB(&(*a)->esq, l) + pruneAB(&(*a)->dir, l));
        }
    }
}
//87
int iguaisAB (ABin a, ABin b) {
    if (!a && !b) return 1;
    if (!a && b || a && !b) return 0;
    
    if (a->valor != b->valor) return 0;
    else return iguaisAB(a->esq, b->esq) && iguaisAB(a->dir, b->dir);
}
//88
LInt nivelL (ABin a, int n) {
    if (!a || !n) return NULL;

    if (n == 1) {
        LInt r = malloc(sizeof(Nodo));
        r->valor = a->valor;
        r->prox = NULL;
        return r;
    }
    else {
        LInt esq = nivelL(a->esq, --n);
        LInt dir = nivelL(a->dir, n);
        if (!esq && !dir) return NULL;
        if (!esq && dir) return dir;
        if (esq && !dir) return esq;
        if (esq && dir) {
            LInt *sitio = &esq;
            while (*sitio)
               sitio = &(*sitio)->prox;
            (*sitio) = dir;
            return esq;
        }
    }
}
//89
int nivelVAux (ABin a, int n, int v[], int i) {
    if (!a) return i;
    if (n == 1) {
        v[i] = a->valor;
        return ++i;
    }
    else {
        n--;
        int esq = nivelVAux(a->esq, n, v, i);
        int dir = nivelVAux(a->dir, n, v, esq);
        return dir;
    }
}

int nivelV (ABin a, int n, int v[]) {
    return nivelVAux(a, n, v, 0);
}
//90
int dumpAbin (ABin a, int v[], int N) {
    if (!a || !N) return 0;

    if (!a->esq && !a->dir) {
        *v = a->valor;
        a = NULL;
        return 1;
    }

    int esq = dumpAbin(a->esq, v, N);
    if (N-esq > 0) {
        *(v + esq) = a->valor;
        int dir = dumpAbin(a->dir, v + esq + 1, N - esq - 1);
        return esq + dir + 1;
    }
    return esq;
}
//91
ABin somasAcA (ABin a) {
    if (!a) return NULL;
    ABin novo = malloc(sizeof(struct nodo));
    ABin esq = somasAcA(a->esq);
    ABin dir = somasAcA(a->dir);
    novo->esq = esq;
    novo->dir = dir;

    if (novo->esq && novo->dir) novo->valor = a->valor + esq->valor + dir->valor;
    if (novo->esq && !novo->dir) novo->valor = a->valor + esq->valor;
    if (!novo->esq && novo->dir) novo->valor = a->valor + dir->valor;
    if (!novo->esq && !novo->dir) novo->valor = a->valor;
    return novo;
}
//92
int contaFolhas (ABin a) {
    if (!a) return 0;
    if (!a->esq && !a->dir) return 1;
    else return contaFolhas(a->esq) + contaFolhas(a->dir);
}
//93
ABin cloneMirror (ABin a) {
    if (!a) return NULL;
    ABin novo = malloc(sizeof(struct nodo));
    novo->valor = a->valor;
    novo->esq = cloneMirror(a->dir);
    novo->dir = cloneMirror(a->esq);
    return novo;
}
//94
int addOrd (ABin *a, int x) {
    while (*a) {
        if (x == (*a)->valor) return 1;
        else if (x > (*a)->valor)
           a = &(*a)->dir;
        else if (x < (*a)->valor)
            a = &(*a)->esq;
    }
    ABin novo = malloc(sizeof(struct nodo));
    novo->valor = x;
    novo->esq = NULL;
    novo->dir = NULL;
    (*a) = novo;
    return 0;
}
//95
int lookupAB (ABin a, int x) {
    ABin *sitio = &a;
    while (*sitio) {
        if ((*sitio)->valor == x) return 1;
        if ((*sitio)->valor < x) sitio = &(*sitio)->dir;
        else sitio = &(*sitio)->esq;
    }
    return 0;
}
//96
int depthOrd (ABin a, int x) {
    int r = 1;

    while (a) {
        if (a->valor != x) {
            r++;
            if (a->valor < x) a = a->dir;
            else a = a->esq;
        }
        else return r;
    }
    return -1;
}
//97
int maiorAB (ABin a) {
    while (a->dir)
        a = a->dir;
    return a->valor;
}
//98
void removeMaiorA (ABin *a) {
   while (*a && (*a)->dir)
       a = &(*a)->dir;

    ABin tmp = *a;
    *a = (*a)->esq;
    free(tmp);
}
//99
int nodos (ABin a) {
    if (!a) return 0;
    return 1 + nodos(a->esq) + nodos(a->dir);
}
int quantosMaiores (ABin a, int x) {
    if (!a) return 0;
    if (x < a->valor) return (1 + nodos(a->dir) + quantosMaiores(a->esq, x));
    if (x == a->valor) return nodos(a->dir);
    else return quantosMaiores(a->dir, x);
}
//100!!!!!
void listToBTree (LInt l, ABin *a) {
    if (!l) *a = NULL;

    while (l) {
        addOrd (a, l->valor);
        l = l->prox;
    }
}
//101 dalmatas
int deProcuraAux (ABin a, int x, int q) { //-1 para testar se x é menor que todos
    if (!a) return 1;                     //1 para testar se x é maior que todos

    int esq = deProcuraAux(a->esq, x, q);
    int dir = deProcuraAux(a->dir, x, q);

    if (a->valor < x && q == 1) return esq && dir;
    if (a->valor > x && q == -1) return esq && dir;
    else return 0;
}
int deProcura (ABin a) {
    if (!a) return 1;

    int esq = deProcura(a->esq);
    int dir = deProcura(a->dir);

    return deProcuraAux(a->esq, a->valor, 1) && deProcuraAux(a->dir, a->valor, -1) && esq && dir;
}
