#include <iostream>

/*  
    -----------------------------------------
    Algoritmo BubbleSort, por Vinícius Leitão
    -----------------------------------------
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

    //Iteração do BubbleSort, pego a primeira posição e faço comparações até que o número esteja correto, assim até que o array esteja ordenado.
    for(int j=0; j < qtd - 1; j++)
        for(int k = j + 1; k < qtd; k++)
            if(arr[j] < arr[k]){
                aux = arr[j];
                arr[j] = arr[k];
                arr[k] = aux;
            }

    for(int x=0; x < qtd; x++)
        std::cout<< arr[x] << " | ";

    return 0;
}
