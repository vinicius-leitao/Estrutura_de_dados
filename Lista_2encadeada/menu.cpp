#include <iostream>
#include <locale.h>

using namespace std;

struct no{

    int info;
    struct no * prev;
    struct no * next;

};

typedef struct no * noPtr;

void insert(noPtr *);
void remove(noPtr *);
void list(noPtr);
bool emptyList(noPtr);

int main(){
    setlocale(LC_ALL,"Portuguese_Brasil");
    noPtr topo = NULL;
    int op;

    do{
        cout<<"Digite uma operação a ser realizada:"<<endl<<"(1) Inserir"<<endl<<"(2) Remover"<<endl<<"(3) Listar"<<endl<<"(0) Sair"<<endl;
        cin>> op;

        switch(op){
            case 0: break;
            case 1: insert(&topo); break;
            case 2: remove(&topo); break;
            case 3: list(topo); break; 
        }
    }while(op!=0);

    return 0;
}


void insert(noPtr * t){
    // A função insert está inserindo um novo nó para a lista duplamente encadeada no início da lista.

    noPtr p = new no;
    cout<<"Insira o elemento desejado para a lista:"<<endl;
    cin >> p->info;

    p->prev = NULL;

    if(emptyList(*t)){
        p->next = NULL;
    }else{
        // O campo próximo do nó recebe o endereço para onde topo aponta;
        p->next = *t;
        // O campo anterior de onde topo aponta recebe o endereço de p;
        (*t)->prev = p;
    }
    // Topo passa a ser o nó que entrou;
    *t = p;
}

void remove(noPtr * t){
    noPtr p = *t;
    if(!emptyList(*t)){
        if(p->next == NULL){
            *t = NULL;
        }
        else{
            *t = p->next;
            (*t)->prev = NULL;
        }
        cout<<"O elemento"<<" "<<p->info<<" "<<" foi removido da lista!"<< endl;
        delete p;
    }else{
        cout<< "A lista está vazia!"<<endl;
    }
}

void list(noPtr t){
    if(!emptyList(t)){
        cout<<"Elementos da lista:"<<endl;
        cout<<"INICIO"<<"\t";
        while(t != NULL){
            cout<< t->info <<"|";
            t = t->next;
        }
        cout<<"\t"<<"FIM"<<endl;

    }else{
        cout<<"A lista está vazia!"<<endl;
    }
}

bool emptyList(noPtr t){
    if(t)
        return false;
    else
        return true;
}