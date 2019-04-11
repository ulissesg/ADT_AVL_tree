//
// Created by ulisses on 01/03/19.
//

#include "lista.h"


Lista * criaLista (){
    Lista * list =(Lista*)malloc(sizeof(Lista));
    list->cabeca = alocaNolista();
    list->ultimo = alocaNolista();
    list->cabeca->proximo = list->ultimo;
    list->ultimo->anterior = list->cabeca;
    list->cabeca->anterior = NULL;
    list->ultimo->proximo = NULL;
    return list;
}

Lista * insereNoLista(Lista *l, No *no){
    if (listavazia(l) == 0){
        noLista * x = alocaNolista();
        x->dado = no;

        l->cabeca->proximo = x;
        l->ultimo->anterior = x;
        x->anterior = l->cabeca;
        x->proximo = l->ultimo;


    }else{
        noLista * novoNo = alocaNolista();
        novoNo->dado =no;
        l->ultimo->anterior->proximo =novoNo; //  talvez seja: l->ultimo->anterior->proximo
        novoNo->anterior = l->ultimo->anterior;
        l->ultimo->anterior =novoNo;
        novoNo->proximo = l->ultimo;
    }


    return l;
}

void retiraNoLista(Lista * l){
    noLista * x = l->cabeca->proximo;
    l->cabeca->proximo->proximo->anterior = l->cabeca; //talvez seja: l->cabeca->proximo->proximo->anterior
    l->cabeca->proximo= x->proximo;
//    desalocaNolista(x);
}

void desalocaLista(Lista*x){
    desalocaNolista(x->cabeca);
    desalocaNolista(x->ultimo);
    free(x);
}

No* consultaInicioLista(Lista *x) {
    return x->cabeca->proximo->dado;
}

int listavazia(Lista *x){
    if (x->cabeca->proximo == x->ultimo){
        return 0;
    }
    else return 1;
}
