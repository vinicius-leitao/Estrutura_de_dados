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

noPtr removeN(noPtr lista1, int n){
    lista1 = topo;
    noPtr ant = topo;
    while(lista1 != NULL){
        if(lista1->info == n){
            if(lista1 == topo)
                topo = lista1->next;
            else
                ant->next = lista1->next;
        }
        ant = lista1;
        lista1 = lista1->next;
        
    }
    return topo;     
}

int main(){
    noPtr lista1;
    int n = 1;
    enqueue();
    noPtr result = removeN(lista1, n);
    while(result->next != NULL){
        cout<<result->info<<"\t";
        result = result->next;
    }
    cout<<result->info<<"\t";
    return 0;
}