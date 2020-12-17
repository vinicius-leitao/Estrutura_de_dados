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

//Defino uma constante T com valor 20 para chamar minha função de busca binária.
#define T 20

//Função para busca binária de um elemento em um vetor.

void binarySearch(int array[], int n, int inicio, int fim){
    //Defino o meio do vetor
    int meio = (inicio + fim)/2;
    
    
    //Condição para verificar se o elemento foi encontrado na atual chamada da função. 
    if(n == array[meio]){
        //Indico para o usuário o elemento e a posição onde o mesmo foi encontrado.
        cout<<"O elemento"<<" "<<"("<<n<<")"<<" "<<"foi encontrado e está na posição"<<" "<<"("<<meio + 1<<")"<<endl<<endl;
    }
    //Verifico se o meio é igual a 0. Caso seja, significa que a função já percorreu todo o vetor e não encontrou o elemento desejado.
    else if(meio == 0){
        //Indico para o usuário que não foi encontrado o elemento.
        cout<<"O elemento"<<" "<<"("<<n<<")"<<" "<<"NÃO está na lista"<<endl<<endl;
        // Forço um retorno para evitar um loop sem fim de "couts".
        return;
    }
    //Se o elemento não for igual ao elemento do meio do vetor, algumas condições são verificadas.
    else{ 
    
        //Se o elemento for menor que o elemento do meio do vetor, passo o meio + 1 como o novo INÍCIO do vetor.
        if(n<array[meio])
            binarySearch(array, n, meio + 1, fim);
        // Se for maior, passo o meio como o novo FIM do vetor.
        else 
            binarySearch(array, n, inicio, meio);    
    }
}

int main(){
    // Instrução para melhor visualização dos caracteres especiais da lingua portuguesa. Lembrar de rodar o comando "chcp 65001" no terminal antes de executar o programa.

    setlocale(LC_ALL, "Portuguese_Brasil");

    //Inicializo a varíavel do elemento a ser procurado, a operação a ser feita, o contador para saber se já foi feita alguma operação e defino os elementos do meu array em ordem DECRESCENTE.

    int n = 0, op, cont = 0, array[20]={20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};

    //Forneço um menu de opções para caso haja necessidade de uma nova busca do usuário.
    do{
        //Se nenhuma operação foi feita, existe uma primeira mensagem ao usuário.
        if(cont == 0){
        cout<<"O que você precisa?"<<endl<<"(1) Buscar elemento desejado"<<endl<<"(0) Sair"<<endl<<endl;
        cin>> op;
        }
        //Se já foi feita, uma nova mensagem é apresentada.
        else{ 
            cout<<"Precisa buscar novamente? Fique a vontade!"<<endl<<"(1) Buscar elemento desejado"<<endl<<"(0) Sair"<<endl<<endl;
            cin>> op;
        }
        
        //Executo a operação desejada
        switch(op){ 
            case 0: break;
            case 1: cout<<"Qual elemento você deseja verificar?"<<endl;
                    cin>> n;
                    binarySearch(array, n, 0, T);
                    cont++;
                    break;
        }

    }while(op!=0);

    return 0;
}

