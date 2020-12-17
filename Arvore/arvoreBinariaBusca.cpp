#include <iostream>
#include <locale.h>

using namespace std;

struct no{
    int info;
    struct no * esq;
    struct no * dir;
};

typedef struct no * noPtr;

void inserir(noPtr *, int);
// bool buscar(noPtr, int);
void remover(noPtr *, int);
void listar_em_ordem(noPtr);
void listar_pre_ordem(noPtr);
void listar_pos_ordem(noPtr);
noPtr maior(noPtr *);
int list();
bool enderecoVazio(noPtr);

int main(){
    setlocale(LC_ALL, "Portuguese_Brasil");

    noPtr raiz = NULL;
    bool achei;
    int op, op2, n;
    do{
        cout<<endl<<"Digite a operação desejada: (1) Inserir , (2) Remover nó, (3) Listar nós, (4) Buscar nó e (0) Sair"<<endl;
        cin>>op;

        switch(op){
            case 0: break;

            case 1: cout<<"Digite o elemento que você deseja inserir na árvore de busca binária:"<<endl;
                    cin>>n;
                    inserir(&raiz, n);
                    break;
            case 2: cout<<"Digite o elemento que você deseja remover da árvore de busca binária:"<<endl;
                    cin>>n;
                    remover(&raiz, n);
                    break;
            case 3: op2 = list();
                    if(op2 == 1)
                        listar_em_ordem(raiz);
                    if(op2 == 2)
                        listar_pre_ordem(raiz);
                    if(op2 == 3)
                        listar_pos_ordem(raiz);
                    break;
            // case 4: cout<<"Digite o elemento que você deseja buscar na árvore de busca binária:"<<endl;
            //         cin>> n;
            //         achei = buscar(raiz, n);
            //         if(!achei)
            //             cout<<"Elemento não pertence à árvore de busca binária!"<<endl;
            //         break;                                   
        }
    }while(op != 0);
}

void inserir(noPtr * p, int n){
    if(enderecoVazio(*p)){
        *p = new no;
        (*p)->info = n;
        (*p)->esq = NULL;
        (*p)->dir = NULL;
    }else{
        if(n < (*p)->info)
            inserir(&((*p)->esq), n);
        else
            inserir(&((*p)->dir), n);    
    }
}

void remover(noPtr * p, int n){
    noPtr aux;
    if(!enderecoVazio(*p)){
        if(n == (*p)->info){
            aux = *p;
            if((*p)->esq == NULL)
                *p = (*p)->dir;
            else
                if((*p)->dir == NULL){
                    *p = (*p)->esq;
                }
                else{
                    aux = maior(&(*p)->esq);
                    (*p)->info = aux->info;
                }
            cout<<"O elemento"<<" "<<"("<<n<<")"<<" "<<"foi removido!"<<endl;   
            delete aux;    
        }else{
            if(n < (*p)->info)
                remover(&(*p)->esq, n);
            else
                remover(&(*p)->dir, n);    
        }
        
    }else
        cout<<"O elemento"<<" "<<"("<<n<<")"<<" "<<"não pertence à árvore!"<<endl;
}

noPtr maior(noPtr * p){
    noPtr t;
    t = *p;

    if(t->dir == NULL){
        *p = (*p)->esq;
        return t;
    }
    else
        return (maior(&((*p)->dir)));
}

int list(){
    int opcao;
    cout<<"Qual tipo de listagem você desejaria ver?"<<endl<<"(1) Listagem em ordem, (2) Listagem pré-ordem ou (3) Listagem pós-ordem."<<endl;

    cin>> opcao;

    return opcao;
}

void listar_em_ordem(noPtr p){
    if(!enderecoVazio(p)){
        listar_em_ordem(p->esq);
        cout<<"\t"<<p->info;
        listar_em_ordem(p->dir);
    }
}

void listar_pre_ordem(noPtr p){
    if(!enderecoVazio(p)){
        cout<<"\t"<<p->info;
        listar_em_ordem(p->esq);
        listar_em_ordem(p->dir);
    }
}

void listar_pos_ordem(noPtr p){
    if(!enderecoVazio(p)){
        listar_em_ordem(p->esq);
        listar_em_ordem(p->dir);
        cout<<"\t"<<p->info;
    }  
}

bool enderecoVazio(noPtr p){
    if(p)
        return false;
    else
        return true;    
}