#include <iostream>
#include <locale.h>

using namespace std;

/* 
----------------------------------------------------
Aluno: Vinícius Leitão Santos

MAT: 1923125BCC

Código comentado para facilitar o entendimento
----------------------------------------------------
*/

//Struct nó para a lista duplamente circular
struct no{

    int info;
    struct no * prev;
    struct no * next;

};

//Abreviação para um nó que aponta para a struct.
typedef struct no * noPtr;

//Função para inserção na lista circular.
void insert(noPtr *, int *, noPtr *);
//Função para remoção na lista circular.
void remove(noPtr *, int *, noPtr *);
//Função para listar os elementos da lista circular.
void list(noPtr, int);
//Função extra para verificar se a lista está vazia.
bool emptyList(noPtr);

//Main com menu para interação com o usuário.
int main(){
    // Instrução para melhor visualização dos caracteres especiais da lingua portuguesa. Lembrar de rodar o comando "chcp 65001" no terminal antes de executar o programa.
    setlocale(LC_ALL, "Portuguese_Brasil");

    //Ponteiro para o topo recebendo null e um ponteiro para o último que será usado em duas funções.
    noPtr topo = NULL, ult;

    //Variável para operação do menu e uma para quantidade de elementos que serão contados com a inserção de elementos.
    int op, qtd = 0;
    
    //Menu
    do{
        cout<<"Digite uma operação a ser realizada:"<<endl<<"(1) Inserir"<<endl<<"(2) Remover"<<endl<<"(3) Listar"<<endl<<"(0) Sair"<<endl;
        cin>> op;

        switch(op){
            case 0: break;
            case 1: insert(&topo, &qtd, &ult); break;
            case 2: remove(&topo, &qtd, &ult); break;
            case 3: list(topo, qtd); break;
        }
    }while(op!=0);

    return 0;
}


//Função de inserção que verifica se a lista tá vazia e insere no início da lista.
void insert(noPtr * t, int * qtd, noPtr * ult){
    noPtr p = new no;

    cout<<"Insira o elemento desejado para a lista:"<<endl;
    cin >> p->info;
    cout<<"O elemento se encontra no endereço"<<" "<<"("<<p<<")"<<endl;
    

    if(emptyList(*t)){
        *t = p;
        p->next = *t;
        p->prev = *t;
        *ult = p;
    }else{
        if(*qtd == 1){
          p->next = *t;
          p->prev = *ult;
          (*ult)->prev = p;
          (*ult)->next = p;
          *t = p;
        }
        else{
           p->next = *t;
           p->next->prev = p;
           p->prev = *ult;
           (*ult)->next = p;
           *t = p;
        }
    }

    *qtd = *qtd + 1;
}


//Função que remove um elemento escolhido pelo usuário. Possui condições para a quantidade de elementos na lista e dentro dessas condições, outras que verificarão se o elemento é o primeiro, do meio ou o último. Essa função considera que a lista terá NÚMEROS DIFERENTES.

void remove(noPtr * t, int * qtd, noPtr * ult){
    int n = 0;
    noPtr p = *t;
    bool founded = false;
    if(!emptyList(*t)){
        cout<<"Qual elemento deseja remover?"<<endl;
        cin>>n;
        for(int i = 0; i < *qtd; i++){
            if(*qtd == 1){
                if(p->info == n){
                    founded = true;
                    *t = NULL;
                    *qtd= *qtd - 1;
                    delete p;
                    break;
                }
            }
            else if(*qtd == 2){
                if(p->info == n){
                    if(i==0){
                        founded = true;
                        (*ult)->prev = *ult;
                        (*ult)->next = *ult;
                        *t = *ult;
                        *qtd= *qtd - 1;
                        delete p;
                        break;
                    }
                    else{
                        founded = true;
                        p->prev = *t;
                        p->next = *t;
                        *qtd= *qtd - 1;
                        delete p;
                        break;
                    }
                }
            }else{
                if(p->info == n){
                    if(i==0){
                        founded = true;
                        p->next->prev = *ult;
                        (*ult)->next = p->next;
                        *t = p->next;
                        *qtd= *qtd - 1;
                        delete p;
                        break;
                    }
                    else if(i== *qtd - 1){
                        founded = true;
                        p->prev->next = *t;
                        *ult = p->prev;
                        (*t)->prev = *ult;
                        *qtd = *qtd - 1;
                        delete p;
                        break;
                    }
                    else{
                        founded = true;
                        p->next->prev = p->prev;
                        p->prev->next = p->next;
                        *qtd = *qtd - 1;
                        delete p;
                        break;
                    }
                }   
            }
            p = p->next;
        }   
    }else
        cout<< "A lista está vazia!"<<endl;
    if(!founded){
        if(*qtd > 0)
        cout<<"O elemento"<<" "<<"("<<n<<")"<<" "<<"não pertence a lista!"<< endl; 
    }
    else
        cout<<"O elemento"<<" "<<"("<<n<<")"<<" "<<"foi removido da lista!"<<endl;
        
}

//Função que lista os elementos e mostra o endereço do primeiro e do próximo do último (novamente o primeiro).
void list(noPtr t,int qtd){
    if(!emptyList(t)){
        cout<<"Elementos da lista:"<<endl;
        cout<<"INICIO"<<"\t";
        for(int i = 0; i < qtd; i++){
            if(i == 0)
                cout<< t->info <<" "<<"&PRIM:"<<"("<<t<<")"<<" "<<"|";
            else if(i == qtd - 1)
                cout<< t->info <<" "<<"&PROX:"<<"("<<t->next<<")"<<" ";
            else   
                cout<< t->info <<"|";
            t = t->next;
        }
        cout<<"\t"<<"FIM"<<endl;
    }else
        cout<< "A lista está vazia!"<<endl;
}


//Função extra que verifica se a lista está vazia.
bool emptyList(noPtr t){
    if(t)
        return false;
    else
        return true;
}