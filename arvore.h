//
// Created by ulisses on 24/02/19.
//

#ifndef ARVORE_ARVORE_H
#define ARVORE_ARVORE_H

#include "nos/no.h"

struct arvore {
    No *raiz;
};

typedef struct arvore Arvore;

Arvore *alocaArv();

void desalocaArv(Arvore *arv);

void desalocaArvNo(No *no);

No *buscaNo(Arvore *a, int num);

No* buscaNoAux(No* no, int num);

void removeNoFolha(No ** no);

void removeNoUmFilho(No** no);

void removeNoDoisFilhos(Arvore *arv, No** no);

No ** menorSucessor(No ** x);

void imprimeArvVisual (Arvore *a);

void imprimeArvVisualNo(No *no);

void insereAVL(Arvore *a, int num);

void insereAVLAux(No **x, int num);

void rotacaoSimplesEsquerda (No ** no);

void rotacaoSimplesDireita (No ** no);

void rotacaoDuplaEsquerda (No ** no);

void rotacaoDuplaDireita (No ** no);

int contaAVL ( No ** no);

void checkAVL (No ** no);

void atualizarAltura (No * no);

void removeAVL(Arvore *arv, int num);

void removeAVLAux(Arvore *arv, No **no, int num);


#endif //ARVORE_ARVORE_H
