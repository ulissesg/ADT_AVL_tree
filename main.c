#include "arvore.h"
#include "arvore.c"
#include "fila/fila.h"
#include "fila/fila.cpp"
#include "fila/lista.h"
#include "fila/lista.cpp"
#include "nos/noLista.h"
#include "nos/noLista.cpp"
#include "nos/no.h"
#include "nos/no.c"
#include <string.h>


int main() {


    Arvore *arv = alocaArv();
    No* x=alocaNo();

//    construirArv(arv);

//    insereVerifica(arv, 8);
//    insereVerifica(arv, 3);
//    insereVerifica(arv, 5);
//    insereVerifica(arv, 2);
//    insereVerifica(arv, 4);
//    insereVerifica(arv, 1);
//    insereVerifica(arv, 22);
//    insereVerifica(arv, 9);
//    insereVerifica(arv, 10);
//    insereVerifica(arv, 11);
//    insereVerifica(arv, 56);
//    insereVerifica(arv, 96);


char string[1000];
scanf("%s", string);
int n = strlen(string);
//lerString(string, x, n, 0, x);
//construiArvString(arv, string, n, 0);

//    No* no = buscaNo(arv, 56);
//    printf("\nno busca: %d\n", no->chave);

//    No* x = buscaNoPai(arv, 22);
//    printf("\nno busca pai: %d\n", x->chave);

//    removeNo(arv, 5);
    removeNo(arv, 2);

    imprimeArvVisual(arv);

//    imprimiArv(arv);
//
//    int num;
//    num = numeroNo(arv);
//    printf("\nnumero de nos: %d", num);
//
    desalocaArv(arv);

    return 0;
}