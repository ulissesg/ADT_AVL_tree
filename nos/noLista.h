//
// Created by ulisses on 02/03/19.
//

#ifndef UNTITLED3_NOLISTA_H
#define UNTITLED3_NOLISTA_H

#include "no.h"

typedef struct nolista noLista;

struct nolista {
    No * dado;
    noLista *proximo;
    noLista *anterior;
};

noLista * alocaNolista();

void desalocaNolista(noLista * no);

#endif //UNTITLED3_NOLISTA_H
