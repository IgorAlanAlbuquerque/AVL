#ifndef ARVOREAVL_H
#define ARVOREAVL_H


class arvoreAVL
{
    public:
        typedef struct No{
            int chave;
            struct No *esq;
            struct No *dir;
            struct No *pai;
            int balanco;
            bool desbalanceada;
        }No;
        void criar_arvore();
        No* getRaiz();
        void setRaiz(No *raiz1);
        int minimo();
        int maximo();
        int altura_arvore(No *raiz1);
        void preOrdem(No *raiz1);
        void posOrdem(No *raiz1);
        void inOrdem(No *raiz1);
        No* rotacaoDireita(No *raiz1);
        No* rotacaoEsquerda(No *raiz1);
        No* inserirAVL(No *raiz1, int valor);
        int numeroFolhas(No *raiz1);

    private:
        No *raiz;
        bool desbalanceada;
};

#endif // ARVOREAVL_H
