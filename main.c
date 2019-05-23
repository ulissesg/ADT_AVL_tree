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

    insereAVL(arv, 8);
    insereAVL(arv, 3);
    insereAVL(arv, 5);
    insereAVL(arv, 2);
    insereAVL(arv, 4);
    insereAVL(arv, 1);
    insereAVL(arv, 22);
    insereAVL(arv, 9);
    insereAVL(arv, 10);
    insereAVL(arv, 11);
    insereAVL(arv, 56);
    insereAVL(arv, 96);

    removeAVL(arv, 1);
    removeAVL(arv, 2);
    removeAVL(arv, 3);
    removeAVL(arv, 10);
    removeAVL(arv, 56);


//char string[1000];
//scanf("%s", string);
//int n = strlen(string);
//lerString(string, x, n, 0, x);
//construiArvString(arv, string, n, 0);

//    No* no = buscaNo(arv, 56);
//    printf("\nno busca: %d\n", no->chave);

//    No* x = buscaNoPai(arv, 22);
//    printf("\nno busca pai: %d\n", x->chave);

//    removeNo(arv, 5);
//    removeNo(arv, 2);

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