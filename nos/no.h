//
// Created by ulisses on 24/02/19.
//

#ifndef ARVORE_NO_H
#define ARVORE_NO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct no No;

struct no{
    int chave;
    No *direita;
    No *esquerda;
};

No *alocaNo();

void desalocaNo(No *no);


#endif //ARVORE_NO_H
