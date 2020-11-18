#include <iostream>

using namespace std;

struct no{
    int senha;
    struct no * next;
};

typedef struct no * noPtr;

noPtr topo = NULL;

void enqueue(){
        noPtr lista, ult;
        lista = new no;
        cout<<"Insira um elemento para a lista 1:"<<endl;
        cin>> lista->senha;
        lista->next = NULL;
        if(topo == NULL){
            topo = lista;
            ult = lista;
        }
        else{
            ult->next = lista;
            ult = lista;
        }   
}

void dequeue(){
    noPtr lista;
    if(topo == NULL){
        cout<<"lista vazia"<<endl;
    }else{
       
        lista = topo;
        topo = lista->next;
        cout<<"O Elemento"<< lista->senha <<"foi retirado"<<endl;
        delete lista;
    }
}


int main(){
    

    int x = 0;
    while(x<2){
    enqueue();
    x++;
    }
    dequeue();
    dequeue();
    dequeue();
    noPtr p = topo;

    while(p!=NULL){
        cout<<p->senha<<"\t";
        p = p->next;
    }

    return 0;
}