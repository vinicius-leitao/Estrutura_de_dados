#include <iostream>

using namespace std;

struct no{
    int info;
    struct no * next;
};

typedef struct no * noPtr;

noPtr topo = NULL;

void enqueue(){
        noPtr aux, lista1;
        int x = 0;
        while(x < 5){
        aux, lista1 = new no;
        cout<<"Insira um elemento para a lista 1:"<<endl;
        cin>> lista1->info;
        lista1->next = NULL;
        if(topo == NULL){
            topo = lista1;
            // cout<<"To no if"<<endl;
        }
        else{
            aux = topo;
            while(aux->next != NULL){
                aux = aux->next;
            }
            aux->next = lista1;
            // cout<<"To no else";
        }
        x++;
    }   
}

noPtr splitList(noPtr lista1, int n){
    lista1 = topo;
    noPtr newList, p;
    while(lista1->info != n){
        lista1 = lista1->next;
    }
    newList = lista1->next;
    lista1->next = NULL;

    p = topo;
    while(p != NULL){
        cout<<p->info<<"\t";
        p = p->next;
    }
    cout<<endl<<"------------------------------------"<<endl;
    while(newList != NULL){
        cout<<newList->info<<"\t";
        newList = newList->next;
    }

    return newList;
}

int main(){
    noPtr lista1, p;
    int n = 7;
    enqueue();
    splitList(lista1, n);
    
    return 0;
}
