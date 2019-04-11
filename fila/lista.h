//
// Created by ulisses on 01/03/19.
//

#ifndef UNTITLED3_LISTA_H
#define UNTITLED3_LISTA_H

#include "../nos/noLista.h"

typedef struct lista Lista;

struct lista{
    noLista * cabeca;
    noLista * ultimo;
};

Lista * criaLista ();

Lista * insereNoLista(Lista *l, No *no);

void retiraNoLista(Lista *x);

void desalocaLista(Lista*x);

No* consultaInicioLista(Lista *x);

int listavazia(Lista *x);

#endif //UNTITLED3_LISTA_H
