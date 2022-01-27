#include "../testar.h"
#ifndef TESTAR_RECURSO_15_16_H
#define TESTAR_RECURSO_15_16_H
char *mystrcpy (char *dest, char source[]);
void strnoV (char s[]);
int dumpAbin (ABin a, int v[], int N);
int lookupAB (ABin a, int x);
int inc (Hist *h, char *pal);
void showHist (Hist h);
char *maisFreq (Hist h);
char *remMaisFreq (Hist *h, int *count);
#endif //TESTAR_RECURSO_15_16_H
