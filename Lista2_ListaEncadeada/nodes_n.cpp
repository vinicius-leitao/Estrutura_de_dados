#include <iostream>

using namespace std;

struct node
    {
        int info;
        struct node * next;
    };
    typedef struct node * nodePtr;
    nodePtr topo = NULL;


void push(){
    //Ponteiro para a lista
    nodePtr p;
    //Inicializa a variavel para a entrada de dados.
    int value = 0;
    p = new node;
    cout<<"Digite o valor do elemento:"<<endl;
    cin>>value;
    p->info = value;
    p->next = topo;
    topo = p;
}

int compareNodes(){
    int n = 0;
    int qtd = 0;
    cout<<"Insira um numero a ser comparado"<<endl;
    cin>> n;
    nodePtr p;
    p = topo;

    if(p==NULL){
        return 1;
    }else{
        while(p!=NULL){
            if(p->info>n)
                qtd++;
            p = p->next;
        }
        return qtd;
    }
}

int main(){
    int x = 0;
    while(x < 5){
        push();
        x++;
    }
    int nodes = compareNodes();
    cout<< nodes<<endl;

    return 0;
}