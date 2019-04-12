//
// Created by ulisses on 24/02/19.
//

#include "no.h"

No *alocaNo(){
    No *no = (No*)malloc(sizeof(No));
    no->chave = NULL;
    no->esquerda = NULL;
    no->direita = NULL;
    no->h = 0;
    return no;
}

void desalocaNo(No *no){
    No *x = no;
    free(no);
}

No* insereNo(int num){
    No *x = alocaNo();
    x->chave = num;
    return x;
}