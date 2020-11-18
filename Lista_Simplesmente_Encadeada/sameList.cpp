#include <iostream>

using namespace std;

struct no{
    int info;
    struct no * next;
};

typedef struct no * noPtr;

noPtr topo1 = NULL, topo2 = NULL;

noPtr enqueue(noPtr lista, noPtr topo){
    noPtr aux;
    int x = 0;
    while(x < 5){
        aux, lista = new no;
        cout<<"Insira um elemento para a lista:"<<endl;
        cin>> lista->info;
        lista->next = NULL;
        if(topo == NULL){
            topo = lista;
        }else{
            aux = topo;
            while(aux->next != NULL){
                aux = aux->next;
            }
            aux->next = lista;
        }
        x++;
    }
    return topo;
}

void isEqual(noPtr lista1, noPtr lista2){
    bool equal;
    lista1 = topo1;
    lista2 = topo2;
    while(lista1 != NULL && lista2 != NULL){
        if(lista1->info == lista2->info){
            lista1 = lista1->next;
            lista2 = lista2->next;
            equal = true;
        }else{
            equal = false;
            cout<<"As listas nao sao iguais"<<endl;
            break;
        }
    }
    if(equal == true){
        cout<<"As listas sao iguais!"<<endl;
    }
}

int main(){
    noPtr lista1, lista2;
    topo1 = enqueue(lista1, topo1);
    topo2 = enqueue(lista2, topo2);
    isEqual(lista1, lista2);
    return 0;
}