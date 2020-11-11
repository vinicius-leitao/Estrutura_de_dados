#include <iostream>


/*  
    --------------------------------------------
    Algoritmo InsertionSort, por Vinícius Leitão
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

    //Iteração do InsertionSort, pego um elemento como chave e enquanto esse elemento for menor que os outros da direita pra esquerda e a posição dele maior que zero, avanço o conteúdo das outras posições até que esbarre em uma das condições do loop. Insiro o conteúdo na posição adequada.
    for(int j = qtd - 1; j > 0; j--){
        int key = arr[j];
        int k = j - 1;
        while(k>=0 && arr[k]>key){
            arr[k+1] = arr[k];
            k--;
        }
        arr[k+1] = key;
    }

    for(int x=0; x < qtd; x++)
        std::cout<< arr[x] << " | ";


    return 0;
}

/* Pesquisando um pouco sobre o InsertionSort, me deparei com algumas questôes:

    1- Dependendo de como a lista se apresenta ao algoritmo do InsertionSort, pode ocorrer um número menor de operações se comparado ao SelectionSort (algoritmo muito parecido com o InsertionSort).

    2- No caso de listas já ordenadas em ordem descrescente, o InsertionSort é menos eficiente que o SelectionSort.

    3- Apesar do que foi dito no item 2, ainda assim o InsertionSort é mais eficiente que o BubbleSort para listas já ordenadas em ordem descrescente e para listas com conteúdo aleatório.

    4- Porém, ao se deparar com uma quantidade maior de elementos, acredito que o InsertionSort não seja o mais indicado para realizar a ordenação, tendo em vista que o algoritmo realiza muitas movimentações até que a lista esteja ordenada de fato.

    5- Em listas já ordenadas em ordem crescente, o InsertionSort é mais eficiente que o SelectionSort e o BubbleSort, esse que apesar de não realizar movimentações, realiza muitas comparações em relação aos outros.

    6- Em listas aleatórias, a diferença entre o SelectionSort e o InsertionSort é bem pequena.

*/
