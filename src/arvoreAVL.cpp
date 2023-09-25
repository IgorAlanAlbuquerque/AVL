#include "arvoreAVL.h"
#include <iostream>
#include <cstdlib>
using namespace std;


arvoreAVL::No* arvoreAVL::getRaiz(){
    return arvoreAVL::raiz;
};
void arvoreAVL::setRaiz(No *raiz1){
    arvoreAVL::raiz=raiz1;
}
void arvoreAVL::criar_arvore(){
    this->raiz=NULL;
}
int arvoreAVL::minimo(){
    if(arvoreAVL::raiz==NULL)
        return 0;
    No *ptu;
    ptu=raiz;
    while(ptu->esq!=NULL){
        ptu=ptu->esq;
    }
    return ptu->chave;
}
int arvoreAVL::maximo(){
   if(arvoreAVL::raiz==NULL)
        return 0;
    No *ptu;
    ptu=raiz;
    while(ptu->dir!=NULL){
        ptu=ptu->dir;
    }
    return ptu->chave;
}
int arvoreAVL::altura_arvore(No *raiz1){
    if(raiz1==NULL){
        return 0;
    }
    if(raiz1->esq==NULL&&raiz1->dir==NULL){
        return 1;
    }
    int E=arvoreAVL::altura_arvore(raiz1->esq);
    int D=arvoreAVL::altura_arvore(raiz1->dir);
    if(E>D){
        return E+1;
    }else{
        return D+1;
    }
}
int arvoreAVL::numeroFolhas(No * raiz1){
    if(raiz1==NULL){
        return 0;
    }else{
        if(raiz1->esq==NULL && raiz1->dir==NULL){
            return 1;
        }else{
            return numeroFolhas(raiz1->esq)+numeroFolhas(raiz1->dir);
        }
    }
}
void arvoreAVL::preOrdem(No *raiz1){
    if(raiz1!=NULL){
        cout<<raiz1->chave<<" ";
        arvoreAVL::preOrdem(raiz1->esq);
        arvoreAVL::preOrdem(raiz1->dir);
    }
}
void arvoreAVL::posOrdem(No *raiz){
    if(raiz!=NULL){
        arvoreAVL::posOrdem(raiz->esq);
        arvoreAVL::posOrdem(raiz->dir);
        cout<<raiz->chave<<" ";
    }
}
void arvoreAVL::inOrdem(No *raiz){
    if(raiz!=NULL){
        arvoreAVL::inOrdem(raiz->esq);
        cout<<raiz->chave<<" ";
        arvoreAVL::inOrdem(raiz->dir);
    }
}
arvoreAVL::No* arvoreAVL::rotacaoDireita(No *raiz1){
    No *ptu = raiz1->esq;
    if(ptu->balanco==-1){
        raiz1->esq=ptu->dir;
        ptu->dir=raiz1;
        raiz1->balanco=0;
        raiz1=ptu;
    }else{
        No *ptv = ptu->dir;
        ptu->dir=ptv->esq;
        ptv->esq=ptu;
        raiz1->esq=ptv->dir;
        ptv->dir=raiz;
        raiz1->balanco = (ptv->balanco== -1) ? 1:0;
        ptu->balanco = (ptv->balanco== 1) ? -1:0;
        raiz1=ptv;
    }
    raiz1->balanco=0;
    desbalanceada=false;
    return raiz1;
};
arvoreAVL::No* arvoreAVL::rotacaoEsquerda(No *raiz1){
    No * ptu = raiz1->dir;
    if(ptu->balanco==1){
        raiz1->dir=ptu->esq;
        ptu->esq=raiz1;
        raiz1->balanco=0;
        raiz1=ptu;
    }else{
        No* ptv = ptu->esq;
        ptu->esq=ptv->dir;
        ptv->dir=ptu;
        raiz1->dir=ptv->esq;
        ptv->esq=raiz1;
        raiz1->balanco = (ptv->balanco== -1) ? 1:0;
        ptu->balanco = (ptv->balanco== 1) ? -1:0;
        raiz1=ptv;
    }
    raiz1->balanco=0;
    desbalanceada=false;
    return raiz1;
};
arvoreAVL::No* arvoreAVL::inserirAVL(No *raiz1, int valor){
    if(raiz1==NULL){
        raiz1 = new No;
        raiz1->chave=valor;
        raiz1->esq=NULL;
        raiz1->dir=NULL;
        raiz1->balanco=0;
        desbalanceada=true;
        return raiz1;
    }
    else if(valor< raiz1->chave){
        raiz1->esq=arvoreAVL::inserirAVL(raiz1->esq, valor);
        if(desbalanceada){
            switch (raiz1->balanco){
                case(1):
                    raiz1->balanco=0;
                    desbalanceada=false;
                    break;
                case(0):
                    raiz1->balanco=-1;
                    break;
                case(-1):
                    raiz1 = arvoreAVL::rotacaoDireita(raiz1);
                    break;
            }
        }
    }
    else if(valor> raiz1->chave){
        raiz1->dir=arvoreAVL::inserirAVL(raiz1->dir, valor);
        if(desbalanceada){
            switch (raiz1->balanco){
                case(-1):
                    raiz1->balanco=0;
                    desbalanceada=false;
                    break;
                case(0):
                    raiz1->balanco=1;
                    break;
                case(1):
                    raiz1 = arvoreAVL::rotacaoEsquerda(raiz1);
                    break;
            }
        }
    }
    return raiz1;
};
