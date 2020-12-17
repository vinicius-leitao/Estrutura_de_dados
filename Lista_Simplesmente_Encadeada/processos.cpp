#include <iostream>
#include <locale.h>

using namespace std;

/* 
----------------------------------------------------
Aluno: Vinícius Leitão Santos

MAT: 1923125BCC

Código com comentários para facilitar o entendimento
----------------------------------------------------
*/

//Estrutura base pedida no enunciado!

struct processo{
    int cod;
    struct processo * prox;
};

typedef struct processo * prPtr;


//Cabeçalho das funções utilizadas no programa. Algumas extras foram utilizadas por estarem já prontas em listas de exercícios.
void novaRequisicao(prPtr *, prPtr *);
void retiraProcesso(prPtr *);
void listar(prPtr);
bool emptyList(prPtr);

int main(){
    // Instrução para melhor visualização dos caracteres especiais da lingua portuguesa. Lembrar de rodar o comando "chcp 65001" no terminal antes de executar o programa.
    setlocale(LC_ALL, "Portuguese_Brasil");

    prPtr topo = NULL, ult;
    // Variável para verificar a operação desejada do usuário.
    int op;

     do{
        cout<<"Digite uma operação a ser realizada:"<<endl<<"(1) Novo processo"<<endl<<"(2) Remover Processo"<<endl<<"(3) Listar"<<endl<<"(0) Sair"<<endl;
        cin>> op;

        switch(op){
            case 0: break;
            case 1: novaRequisicao(&topo, &ult); break;
            case 2: retiraProcesso(&topo); break;
            case 3: listar(topo);
        }
    }while(op!=0);
}

//Função que insere um novo processo sempre no final da lista com código escolhido pelo usuário, por exemplo: p->cod = 1; "Processo número 1", p->cod = 2; "Processo número 2", assim por diante.

void novaRequisicao(prPtr * t, prPtr * ult){
    prPtr p = new processo;
    cout<<"Digite o número do processo"<<endl;
    cin>> p->cod;

    p->prox = NULL;

    if(emptyList(*t)){
        *t = p;
        *ult = p;
    }
    else{
        (*ult)->prox = p;
        *ult = p;
    }
}

//Função que retira o processo. Será sempre removido o processo que estiver na primeira posição, isto é, o primeiro processo a ser requirido pelo usuário.
void retiraProcesso(prPtr * t){
    prPtr p = *t;
    if(!emptyList(*t)){
        if(p->prox==NULL){
            *t = NULL;
            cout<<"O processo"<<" "<<"("<<p->cod<<")"<<" "<<"foi removido da espera!"<<endl;
            delete p;
        }
        else{
            *t = p->prox;
            cout<<"O processo"<<" "<<"("<<p->cod<<")"<<" "<<"foi removido da espera!"<<endl;
            delete p;
        }
    }else{
        cout<<"A lista está vazia!"<<endl;
    }
}

//Função para melhor visualização do usuário. Lista todos os processos em espera.
void listar(prPtr t){
    if(!emptyList(t)){
        cout<<"Elementos da lista:"<<endl;
        cout<<"INICIO"<<"\t";
        while(t != NULL){
            cout<< t->cod <<"|";
            t = t->prox;
        }
        cout<<"\t"<<"FIM"<<endl;

    }else{
        cout<<"A lista está vazia!"<<endl;
    }
}


//Função que verifica se a lista está vazia.
bool emptyList(prPtr t){
    if(t)
        return false;
    else
        return true;
}