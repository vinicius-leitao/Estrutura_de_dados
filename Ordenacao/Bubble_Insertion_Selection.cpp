#include <iostream>

/*
    -------------------------------------------------------------
    BubbleSort, InsertionSort, SelectionSort, por Vinícius Leitão
    -------------------------------------------------------------
*/


void BubbleSort(int arr[], int qtd)
{

    for (int j = 0; j < qtd - 1; j++)
        for (int k = j + 1; k < qtd; k++)
            if (arr[j] < arr[k])
            {
                int aux = arr[j];
                arr[j] = arr[k];
                arr[k] = aux;
            }
}

int *InsertionSort(int arr[], int qtd){
        for(int j = qtd - 1; j > 0; j--){
        int key = arr[j];
        int k = j - 1;
        while(k>=0 && arr[k]>key){
            arr[k+1] = arr[k];
            k--;
        }
        arr[k+1] = key;
    }
    
    return arr;
}

int *SelectionSort(int arr[], int qtd){
        for(int i = 0; i < qtd - 1; i++){
        int menor = i;
        for(int j = menor + 1; j < qtd; j++)
            if(arr[j] > arr[menor]){
                menor = j;
            }
        int aux = arr[i];
        arr[i] = arr[menor];
        arr[menor] = aux;    
    }

    return arr;
}

int getLength(){
    int qtd;
    std::cout<<"Insira o a quantidade de numeros:"<<std::endl;
    std::cin>> qtd;

    return qtd;
}

int *getNumbers(int arr[], int qtd){
    for(int i=0; i < qtd; i++)
        arr[i] = rand() % 100;

    return arr;    
}

void printArray(int arr[], int qtd){
    for(int x=0; x < qtd; x++){
        if(x<qtd - 1)
        std::cout<< arr[x] << " | ";
        else
        std::cout<< arr[x] <<std::endl;
    }
}

int main(){

    //Inicializo a variável para quantidade de elementos no array.
    int qtd = 0;

    //Peço ao usuário que entre com a quantidade de elementos desejados.
    qtd = getLength();

    //Inicializo o array com a quantidade de elementos já estipulado.
    int arr[qtd];

    //Peço ao usuário os números desejados.
    int *oldArray = getNumbers(arr, qtd);

    // int *newArray1 = BubbleSort(arr, qtd);
    BubbleSort(arr, qtd);
    // int *newArray2 = InsertionSort(arr, qtd);
    // int *newArray3 = SelectionSort(arr, qtd);

    // printArray(newArray1, qtd);
    // printArray(newArray2, qtd);
    // printArray(newArray3, qtd);

    for(int i=0; i< qtd; i++)
        std::cout<<arr[i]<<"\t";

    return 0;
}
