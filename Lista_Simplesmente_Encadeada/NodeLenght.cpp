#include <iostream>


using namespace std;

//Criando a estrutura para a lista simplesmente encadeada e o ponteiro para o topo.
struct node
    {
        int info;
        struct node * next;
    };
    typedef struct node * nodePtr;
    nodePtr topo = NULL;


//Função para inserção de um novo nó na lista encadeada.
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

int getLength(){
    int lenght = 0;
    nodePtr p;
    p = topo;
    if(p == NULL){
        return 1;
    }else{
        while(p!=NULL){
            p = p->next;
            lenght++;
        }
        return lenght;
    }
}

int main(){
    int x = 0;
    while(x<=5){
        push();
        x++;
    }
    int qtd = getLength();
    cout<< qtd - 1;

    return 0;
}