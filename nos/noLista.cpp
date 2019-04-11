//
// Created by ulisses on 02/03/19.
//

#include "noLista.h"

noLista * alocaNolista(){
    noLista * x =(noLista*)malloc(sizeof(noLista));
    x->anterior = (noLista*)malloc(sizeof(noLista));
    x->proximo = (noLista*)malloc(sizeof(noLista));
    return x;
}

void desalocaNolista(noLista * no){
    noLista * x = no;
    free(x->proximo);
    free(x->anterior);
    desalocaNo(x->dado);
    free(no);
}
