#include <iostream>
#include "arvoreAVL.h"
using
 namespace std;

int main()
{
    arvoreAVL Arvore;
    int valor;
    int escolha;
    Arvore.criar_arvore();
    while(true){
        cout<<endl;
        cout<<"1- Inserir elemento na arvore binaria"<<endl;
        cout<<"2- Maior e menor valor na arvore"<<endl;
        cout<<"3- Altura da arvore"<<endl;
        cout<<"4- Numero de folhas na arvore"<<endl;
        cout<<"5- Percuso em pre-ordem"<<endl;
        cout<<"6- Percuso em in-ordem"<<endl;
        cout<<"7- Percuso em pos-ordem"<<endl;
        cout<<"8- Sair"<<endl;
        cout<<"Escolha uma opcao: ";
        cin>>escolha;
        switch(escolha){
            case(1):
                cout<<"Digite o valor a ser inserido na arvore: ";
                cin>>valor;
                Arvore.setRaiz(Arvore.inserirAVL(Arvore.getRaiz(),valor));
                break;
            case(2):
                cout<<"Maximo: "<<Arvore.maximo()<<endl<<"Minimo: "<<Arvore.minimo()<<endl;
                break;
            case(3):
                cout<<"Altura da arvore: "<<Arvore.altura_arvore(Arvore.getRaiz())<<endl;
                break;
            case(4):
                cout<<"Numero de folhas na arvore: "<<Arvore.numeroFolhas(Arvore.getRaiz())<<endl;
                break;
            case(5):
                cout<<"Percuso em pre-ordem: ";
                Arvore.preOrdem(Arvore.getRaiz());
                break;
            case(6):
                cout<<"Percuso em in-ordem: ";
                Arvore.inOrdem(Arvore.getRaiz());
                break;
            case(7):
                cout<<"Percuso em pos-ordem: ";
                Arvore.posOrdem(Arvore.getRaiz());
                break;
            case(8):
                return 0;
            default:
                cout<<"sabe ler? Tenta de novo"<<endl;
        }
    }

    return 0;
}
