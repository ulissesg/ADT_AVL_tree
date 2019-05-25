//
// Created by ulisses on 24/02/19.
//

#include "arvore.h"

Arvore *alocaArv(){
    Arvore *arv = (Arvore *)malloc(sizeof(Arvore));
    arv->raiz = NULL;
    return arv;
}

void desalocaArv(Arvore *arv){
    desalocaArvNo(arv->raiz);
}

void desalocaArvNo(No *x){
    if (x != NULL){
        desalocaArvNo(x->esquerda);
        desalocaArvNo(x->direita);
        desalocaNo(x);
    }
}

No *buscaNo(Arvore *a, int num){
    buscaNoAux(a->raiz, num);
}

No* buscaNoAux(No* no, int num){
    if (no != NULL){
        if (no->chave == num){
            return no;
        }
        else if (no->chave > num){
            return buscaNoAux(no->esquerda, num);
        }
        else if (no->chave < num){
            return buscaNoAux(no->direita, num);
        }
    }
    printf("\n numero nao encontrado !\n");
}

void insereAVL(Arvore *a, int num){
    if (a->raiz == NULL){
        a->raiz = alocaNo();
        a->raiz->chave = num;
    }
    else {
        insereAVLAux(&(a->raiz), num);
    }
}

void insereAVLAux(No **x, int num){
    if (num > (*x)->chave && (*x)->direita == NULL){
        (*x)->direita = alocaNo();
        (*x)->direita->chave = num;

    }
    else if(num < (*x)->chave && (*x)->esquerda == NULL){
        (*x)->esquerda = alocaNo();
        (*x)->esquerda->chave = num;
    }
    else if(num > (*x)->chave){
        insereAVLAux(&(*x)->direita, num);
    }
    else if(num < (*x)->chave){
        insereAVLAux(&(*x)->esquerda, num);
    }
    atualizarAltura(*x);
    checkAVL(&(*x));
}

void removeAVL(Arvore *arv, int num){

    if (arv->raiz->chave == num && arv->raiz->esquerda == NULL && arv->raiz->direita == NULL){
        free(arv->raiz);
    }
    else {
        removeAVLAux(arv, &(arv->raiz), num);
    }
}

void removeAVLAux(Arvore *arv, No **no, int num){

    if ((*no) != NULL){
        if ((*no)->chave == num){

            if((*no)->direita == NULL && (*no)->esquerda == NULL){
                removeNoFolha(no);
            }
            else if ((*no)->direita == NULL || (*no)->esquerda == NULL){
                removeNoUmFilho(no);
            }
            else if ((*no)->direita != NULL && (*no)->esquerda != NULL){
                removeNoDoisFilhos(arv, no);
                checkAVL(no);
            }
        }
        else if ((*no)->chave > num){
            removeAVLAux(arv, &((*no)->esquerda), num);
            atualizarAltura(*no);
            checkAVL(no);
        }
        else if ((*no)->chave < num){
            removeAVLAux(arv, &((*no)->direita), num);
            atualizarAltura(*no);
            checkAVL(no);
        }
    }
}

void removeNoFolha(No ** no){
    desalocaNo(*no);
    (*no) = NULL;
}

void removeNoUmFilho(No** no){
    No * aux = (*no);
    if ((*no)->direita != NULL){
        *no = (*no)->direita;
    }else if ((*no)->esquerda != NULL){
        *no = (*no)->esquerda;
    }
    desalocaNo(aux);
}

void removeNoDoisFilhos(Arvore* arv, No** no){

    No ** menorSucessor1 = menorSucessor(no);
    No * aux = (*menorSucessor1)->direita;
    (*menorSucessor1)->esquerda = (*no)->esquerda;
    if (((*no)->direita) != (*menorSucessor1)){ // se o menor sucessor for o no da direita.
        (*menorSucessor1)->direita = (*no)->direita;
    }
    No * auxRem = (*no);
    (*no) = (*menorSucessor1);
    (*menorSucessor1) = aux;
    desalocaNo(auxRem);
    atualizarAltura(*no);
}

No ** menorSucessor(No ** x){
    No ** no = &(*x)->direita;
    if ((*no)->esquerda != NULL){
        no = &(*no)->esquerda;
    }
    return no;
}

void imprimeArvVisualNo(No* no){

    if (no != NULL) {
        printf("(");
        printf("%d", no->chave);
        imprimeArvVisualNo(no->esquerda);
        imprimeArvVisualNo(no->direita);
        printf(")");
    }
}

void imprimeArvVisual (Arvore *a){
    imprimeArvVisualNo(a->raiz);
}

void rotacaoSimplesEsquerda (No ** no){
    No *aux = (*no)->esquerda->direita;
    (*no)->esquerda->direita = (*no);
    (*no)= (*no)->esquerda;
    (*no)->direita->esquerda = aux;
    atualizarAltura((*no)->direita);
    atualizarAltura(*no);

}

void rotacaoSimplesDireita (No ** no){
    No *aux = (*no)->direita->esquerda;
    (*no)->direita->esquerda = (*no);
    (*no)= (*no)->direita;
    (*no)->esquerda->direita = aux;
    atualizarAltura((*no)->esquerda);
    atualizarAltura(*no);
}

void rotacaoDuplaEsquerda (No ** no){
    rotacaoSimplesDireita(&((*no)->esquerda));
    rotacaoSimplesEsquerda(&(*no));
}

void rotacaoDuplaDireita (No ** no){
    rotacaoSimplesEsquerda(&(*no)->direita);
    rotacaoSimplesDireita(&(*no));
}

int contaAVL ( No ** no){

    if ((*no) != NULL){
        if (((*no)->direita) != NULL && (*no)->esquerda != NULL){
            return (*no)->direita->h - (*no)->esquerda->h;
        }

        else if (((*no)->direita) == NULL && (*no)->esquerda == NULL){
            return 0;
        }

        else if (((*no)->direita) == NULL || (*no)->esquerda == NULL){

            if (((*no)->direita) == NULL){
                return (0-1) - (*no)->esquerda->h;
            }

            if (((*no)->esquerda) == NULL){
                return (*no)->direita->h + 1;
            }
        }
    }
}

void checkAVL (No ** no){

    int b = contaAVL(&(*no));
//    int b  = (*no)->h;

    if(b >= 2){
        int b2 = contaAVL(&(*no)->direita);

        if (b2 >= 0){
            rotacaoSimplesDireita(&(*no));
        }
        else {
            rotacaoDuplaDireita(&(*no));
        }
    }
    else if (b <= -2){
        int b2 = contaAVL(&(*no)->esquerda);
        if (b2 <= 0){
            rotacaoSimplesEsquerda(&(*no));
        }
        else {
            rotacaoDuplaEsquerda(&(*no));
        }
    }

    atualizarAltura(*no);
}

void atualizarAltura (No * no){

    if (no != NULL) {
        if ((no->direita != NULL) && (no->esquerda != NULL)){
            if (no->direita->h >= no->esquerda->h){
                no->h = no->direita->h + 1;
            }
            else{
                no->h = no->esquerda->h + 1;
            }
        }

        else if ((no->direita == NULL) && (no->esquerda == NULL)){
            no->h = 0;
        }

        else if ((no->direita == NULL) || (no->esquerda == NULL)){
            if (no->direita == NULL){
                no->h = no->esquerda->h + 1;
            }

            else if (no->esquerda == NULL){
                no->h = no->direita->h + 1;
            }
        }
    }


}

