#include <iostream>


/*  
    --------------------------------------------
    Algoritmo SelectionSort, por Vinícius Leitão
    --------------------------------------------
*/

int main(){

    //Inicializo a variável para quantidade de elementos no array.
    int qtd = 0;
    int aux = 0;

    //Peço ao usuário que entre com a quantidade de elementos desejados.
    std::cout<<"Insira o a quantidade de numeros:"<<std::endl;
    std::cin>> qtd;

    //Inicializo o array com a quantidade de elementos já estipulado.
    int arr[qtd];

    //Peço ao usuário os números desejados.
    for(int i=0; i < qtd; i++)
        std::cin>> arr[i];

    //Iteração do SelectionSort, pego o conteúdo da primeira posição e comparo com as outras. Caso haja números menores ao decorrer do array, marco a posição e efetuo a troca ao final da iteração.
    for(int i = 0; i < qtd - 1; i++){
        int menor = i;
        for(int j = menor + 1; j < qtd; j++)
            if(arr[j] > arr[menor]){
                menor = j;
            }
        aux = arr[i];
        arr[i] = arr[menor];
        arr[menor] = aux;    
    }

    for(int x=0; x < qtd; x++)
        std::cout<< arr[x] << " | ";


    return 0;
}