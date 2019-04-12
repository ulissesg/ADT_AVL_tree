//
// Created by ulisses on 24/02/19.
//

#ifndef ARVORE_ARVORE_H
#define ARVORE_ARVORE_H

#include "fila/fila.h"

struct arvore {
    No *raiz;
};

typedef struct arvore Arvore;

Arvore *alocaArv();

void desalocaArv(Arvore *arv);

void desalocaArvNo(No *no);

//void construirArv(Arvore *a);

void construiArvString(Arvore *a, char arvoreString[100], int size, int posicao);

void contruiArvStringNo(No *no, char arvoreString[100], int size, int posicao, No* pai, No *raiz);

int verificaNumDigitos(char arvoreString[100], int posicao);

int digitosString(char arvoreString[100], int posicao, int numDigitos, int size);

int verificaExistente(No *x, int num);

void insereVerificaAux(No *x, int num);

void insereVerifica(Arvore *a, int num);

No *buscaNo(Arvore *a, int num);

No* buscaNoAux(No* no, int num);

No* buscaNoPai(Arvore *a, int num);

No* buscaNoPaiAux(No *no, int num);

void removeNo(Arvore *a, int num);

void removeNoAux(No* x, int num);

void removeNoFolha(No* no, No* pai);

void removeNoUmFilho(No* no, No* pai);

void removeNoDoisFilhos(No* x, No* no, No* pai);

No * menorSucessor(No * x);

void imprimiArv(Arvore *a);

void imprimeArvVisual (Arvore *a);

void imprimeArvVisualNo(No *no);

int numeroNo(Arvore *a);

int contaNo(No *no);

// AVL

void rotacaoSimplesEsquerda (No ** no);

void rotacaoSimplesDireita (No ** no);

void rotacaoDuplaEsquerda (No ** no);

void rotacaoDuplaDireita (No ** no);

void checkAVL (No ** no);

void atualizarAltura (No ** no);


#endif //ARVORE_ARVORE_H
