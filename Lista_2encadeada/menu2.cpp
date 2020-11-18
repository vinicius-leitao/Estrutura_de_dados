#include <iostream>
#include <locale.h>

using namespace std;

struct no{

    int info;
    struct no * prev;
    struct no * next;

};

typedef struct no * noPtr;

void insert(noPtr *, int *);
void remove(noPtr *, int *);
void list(noPtr, int);
bool emptyList(noPtr);

int main(){
    setlocale(LC_ALL, "Portuguese_Brasil");
    noPtr topo = NULL;
    int op, qtd = 0;

    do{
        cout<<"Digite uma operação a ser realizada:"<<endl<<"(1) Inserir"<<endl<<"(2) Remover"<<endl<<"(3) Listar"<<endl<<"(0) Sair"<<endl;
        cin>> op;

        switch(op){
            case 0: break;
            case 1: insert(&topo, &qtd); break;
            case 2: remove(&topo, &qtd); break;
            case 3: list(topo, qtd); break;
        }
    }while(op!=0);

    return 0;
}

void insert(noPtr * t, int * qtd){
    noPtr p = new no;
    cout<<"Insira o elemento desejado para a lista:"<<endl;
    cin >> p->info;
    

    if(emptyList(*t)){
        *t = p;
        p->next = *t;
        p->prev = p;
    }else{
        p->next = *t;
        p->prev = (*t)->prev;
        (*t)->prev->next = p;
        *t = p;
    }

    *qtd = *qtd + 1;
}

void remove(noPtr * t, int * qtd){
    noPtr p = *t;
    if(!emptyList(*t)){
        if(*qtd == 1)
            *t = NULL;
        else
            *t = p->next;

        cout<<"O elemento"<<" "<<p->info<<" "<<" foi removido da lista!"<< endl;
        delete p;
        *qtd= *qtd - 1;
    }else
        cout<< "A lista está vazia!"<<endl;

        
}

void list(noPtr t,int qtd){
    if(!emptyList(t)){
        cout<<"Elementos da lista:"<<endl;
        cout<<"INICIO"<<"\t";
        for(int i = 0; i < qtd; i++){
            cout<< t->info <<"|";
            t = t->next;
        }
        cout<<"\t"<<"FIM"<<endl;
    }else
        cout<< "A lista está vazia!"<<endl;
}

bool emptyList(noPtr t){
    if(t)
        return false;
    else
        return true;
}