#include <iostream>
#include <locale.h>

/* 
----------------------------------------------------
Aluno: Vinícius Leitão Santos

MAT: 1923125BCC

Código com comentários para facilitar o entendimento

(IMPORTANTE) 
Sobre a complexidade das funções pedidas no enunciado da questão, TODAS AS FUNÇÕES QUE FORAM PEDIDAS, ou seja, funções extras não contam, POSSUEM COMPLEXIDADE O(N).
(IMPORTANTE)
----------------------------------------------------
*/

using namespace std;

struct no{

    int info;
    struct no * prev;
    struct no * next;

};

typedef struct no * noPtr;


//Cabeçalhos das funções que eu utilizei. Algumas funções extras foram incluídas por já estarem prontas em listas de exercícios anteriores.

void insert(noPtr *, noPtr *);
void remove(noPtr *);
void increasingList(noPtr);
void decreasingList(noPtr, noPtr);
bool emptyList(noPtr);

int main(){
     // Instrução para melhor visualização dos caracteres especiais da lingua portuguesa. Lembrar de rodar o comando "chcp 65001" no terminal antes de executar o programa.
    setlocale(LC_ALL,"Portuguese_Brasil");

    //Defino um topo para a minha lista duplamente encadeada e um ponteiro que apontará para o último nó da lista.
    noPtr topo = NULL, ult;

    //Uma variável para a leitura da operação desejada no menu que foi desenvolvido caso o usuário decida inserir, remover ou listar mais de uma vez.
    int op;

    do{
        cout<<"Digite uma operação a ser realizada:"<<endl<<"(1) Inserir"<<endl<<"(2) Remover"<<endl<<"(3) Listar em ordem crescente"<<endl<<"(4) Listar em ordem decrescente"<<endl<<"(0) Sair"<<endl;
        cin>> op;

        switch(op){
            case 0: break;
            case 1: insert(&topo, &ult); break;
            case 2: remove(&topo); break;
            case 3: increasingList(topo); break;
            case 4: decreasingList(topo, ult); break; 
        }
    }while(op!=0);

    return 0;
}

// A função insert pede ao usuário um número e insere na lista JÁ de forma ORDENADA e CRESCENTE. Um ponteiro ULT é utilizado para marcar o último elemento da lista e será usado em uma próxima função.
void insert(noPtr * t, noPtr * ult){

    //Novo nó e uma variável auxiliar para ordenação da lista.
    noPtr p = new no, aux;
    
    cout<<"Insira o elemento desejado para a lista:"<<endl;
    cin >> p->info;
    cout<<"O elemento se encontra no endereço"<<" "<<"("<<p<<")"<<endl;

    //Se a lista estiver vazia, insiro o elemento sem nenhuma condição maior.
    if(*t == NULL){
        p->next = *t;
        p->prev = *t;
        *t = p;
        *ult = p;
    }else{
        // Se não estiver vazia, defino a auxiliar para onde topo aponta.
        aux = *t;

        //Enquanto for diferente de NULL e o elemento do novo nó for maior que o conteúdo de aux->info, incremento aux e p->prev guarda o anterior.

        while(aux != NULL && p->info > aux->info){
            p->prev = aux;
            aux = aux->next;
        }
        //Condição 1: Se aux for igual ao conteudo de topo, significa que o conteúdo do novo nó é menor que o primeiro nó da lista. Portanto, é inserido na primeira posição.
        if(aux == *t){
            p->next = *t;
            p->prev = NULL;
            *t = p;
            p->next->prev = p;
        }
        //Se aux for diferente de topo, existem duas condições.
        //Condição 2: Se aux não for o último nó, isto é, aux é diferente de NULL, atualizamos o aux->prev para o novo nó que entrará.
        //Condição 3: Se aux for o último nó, isto é, aux igual a NULL, marco o novo nó como o último nó.
        else{
            p->next = aux;
            p->prev->next = p;
            if(aux != NULL)
            p->next->prev = p;
            if(aux == NULL)
                *ult = p;
        }
    }
}

//Função que vai remover TODAS as ocorrências de um certo elemento que será escolhido pelo usuário. 
void remove(noPtr * t){
    noPtr p = *t;
    int n = 0;
    cout<<"Qual número você deseja remover?"<<endl;
    cin>>n;

    //Booleano para saber se o elemento existe na lista encadeada.
    bool founded = false;

    if(!emptyList(*t)){
        while(p!= NULL){
            //Condições para retirada no início, fim e meio, respectivamente.
            if(p->info == n && p==*t){
                founded = true;
                *t = p->next;
                delete p;
            }
            else if(p->info == n && p->next==NULL){
                founded = true;
                p->prev->next = NULL;
                delete p;
            }
            else if(p->info == n){
                founded = true;
                p->next->prev = p->prev;
                p->prev->next = p->next;
                delete p;
            }
            p = p->next; 
        }
        //Se não existir, o programa exibirá uma mensagem de aviso ao usuário.
        if(!founded){
            cout<<"O elemento"<<" "<<"("<<n<<")"<<" "<<"não pertence a lista!"<< endl;
        }
        //Se existir, o programa exibirá uma mensagem avisando que foram retirados todas as ocorrências de N.
        else{
            cout<<"Todas as ocorrências do elemento"<<" "<<"("<<n<<")"<<" "<<"foram removidas da lista!"<<endl;
        }
    }else{
        cout<< "A lista está vazia!"<<endl;
    }
}

// Função que vai exibir a lista em ORDEM CRESCENTE.
void increasingList(noPtr t){
    if(!emptyList(t)){
        cout<<"Elementos da lista em ORDEM CRESCENTE:"<<endl;
        cout<<"INICIO"<<"\t";
        while(t != NULL){
            cout<< t->info <<"|";
            t = t->next;
        }
        cout<<"\t"<<"FIM"<<endl;

    }else
        cout<<"A lista está vazia!"<<endl;
    
}

//Função que exibirá a lista em ORDEM DECRESCENTE. Essa função utilizará um ponteiro para o último nó da lista, como dito anteriormente.
void decreasingList(noPtr t, noPtr ult){
    noPtr p = ult;
    if(!emptyList(t)){
        cout<<"Elementos da lista em ORDEM DECRESCENTE:"<<endl;
        cout<<"INICIO"<<"\t";
        while(p != NULL){
            cout<< p->info <<"|";
            p = p->prev;
        }
        cout<<"\t"<<"FIM"<<endl;
    }else
        cout<<"A lista está vazia!"<<endl;
}

//Função que verifica se a lista está vazia.
bool emptyList(noPtr t){
    if(t)
        return false;
    else
        return true;
}