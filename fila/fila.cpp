//
// Created by ulisses on 04/03/19.
//

#include "fila.h"

Fila * alocafila(){
    Fila * x =(Fila*)malloc(sizeof(Fila));
    x->listaNo = criaLista();
    return x;
}

void desalocafila(Fila *x){
    while(x->listaNo->ultimo != x->listaNo->cabeca){
        retiraNoLista(x->listaNo);
    }
    desalocaLista(x->listaNo);
}

Fila * insereNoFila(Fila *x, No *no){
    if (no != NULL){
        x->listaNo = insereNoLista(x->listaNo, no);
        return x;
    }
    return x;
}

void retiraNoFila(Fila *x){
    retiraNoLista(x->listaNo);
}

No *consultaInicioFila(Fila *x){
    return consultaInicioLista(x->listaNo);
}

int filaVazia(Fila *x){
    return listavazia(x->listaNo);
}