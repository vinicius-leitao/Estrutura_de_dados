#include <iostream>

using namespace std;

struct no{
    int info;
    struct no * next;
};

typedef struct no * noPtr;

noPtr topo = NULL;

void decreasingList(){
    noPtr lista = new no, aux, ant;
    cout<<"Insira um elemento na lista:"<<endl;
    cin>>lista->info;
    if(topo == NULL){
        lista->next = topo;
        topo = lista;
    }else{
        aux = topo;
        while(aux != NULL && lista->info < aux->info){
            ant = aux;
            aux = aux->next;
        }
        if(aux == topo){
            lista->next = topo;
            topo = lista;
        }else{
            lista->next = aux;
            ant->next = lista;
        }
    }
}

int main(){
    noPtr p;
    int x = 0;
    while(x < 8){
        decreasingList();
        x++;
    }
    p = topo;
    while(p!=NULL){
        cout<<p->info<<"\t";
        p = p->next;
    }

    return 0;
}

