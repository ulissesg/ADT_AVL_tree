#include "arvore.h"
#include "arvore.c"
#include "nos/no.h"
#include "nos/no.c"
#include <string.h>


int main() {


    Arvore *arv = alocaArv();

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
    removeAVL(arv, 56);
    removeAVL(arv, 9);

    imprimeArvVisual(arv);

    desalocaArv(arv);

    return 0;
}