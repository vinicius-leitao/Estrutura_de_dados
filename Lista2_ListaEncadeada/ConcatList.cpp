#include <iostream>

using namespace std;

struct no{
    int info;
    struct no * next;
};

typedef struct no * noPtr;
noPtr topo1 = NULL;
noPtr topo2 = NULL;
noPtr topo3 = NULL;

noPtr concatList(noPtr lista1, noPtr lista2) {
    lista1 = topo1;
    while(lista1->next!=NULL){
        lista1 = lista1->next;
    }
    lista1->next = topo2;

    return topo3 = topo1;
}

int main(){
    noPtr aux, lista1, aux2, lista2;

    int x = 0, y = 0;
    while(x < 5){
        aux, lista1 = new no;
        cout<<"Insira um elemento para a lista 1:"<<endl;
        cin>> lista1->info;
        lista1->next = NULL;
        if(topo1 == NULL){
            topo1 = lista1;
            // cout<<"To no if"<<endl;
        }
        else{
            aux = topo1;
            while(aux->next != NULL){
                aux = aux->next;
            }
            aux->next = lista1;
            // cout<<"To no else";
        }
        x++;
    }   
    while(y < 5){
        aux2, lista2 = new no;
        cout<<"Insira um elemento para a lista 2:"<<endl;
        cin>>lista2->info;
        lista2->next = NULL;
        if(topo2 == NULL){
            topo2 = lista2;
        }
        else{
            aux2 = topo2;
            while(aux2->next != NULL){
                aux2 = aux2->next;
            }
            aux2->next = lista2;
        }
       y++;
    }
    
    concatList(lista1, lista2);
    noPtr p = topo1;
    while(p->next != NULL){
        cout<<p->info<<"\t";
        p = p->next;
    } 
    cout<<p->info<<"\t";

    return 0;
}