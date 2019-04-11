//
// Created by ulisses on 04/03/19.
//

#ifndef UNTITLED3_FILA_H
#define UNTITLED3_FILA_H

#include "lista.h"

typedef struct fila Fila;

struct fila{
    Lista * listaNo;
};

Fila * alocafila();

void desalocafila(Fila *x);

Fila * insereNoFila(Fila *x, No *no);

void retiraNoFila(Fila *x);

No * consultaInicioFila(Fila *x);

int filaVazia(Fila *x);

#endif //UNTITLED3_FILA_H
