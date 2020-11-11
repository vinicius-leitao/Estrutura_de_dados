#include <iostream>
#include <math.h>

using namespace std;

void intercalar(int arr[], int inicio, int meio, int fim){

   
    int i, aux[8], posLivre = inicio, inicioV1 = inicio, inicioV2 = meio+1;

    while(inicioV1 <= meio && inicioV2 <= fim){
        if(arr[inicioV1] > arr[inicioV2]){
            aux[posLivre] = arr[inicioV2];
            inicioV2++;
        }
        else{
            aux[posLivre] = arr[inicioV1];
            inicioV1++;
        }
        posLivre++;
    }

    for(i = inicioV1 ; i <= meio; i++){
        aux[posLivre] = arr[i];
        posLivre++;
    }
    
    for(int j = inicioV2 ; j <= fim; j++){
        aux[posLivre] = arr[j];
        posLivre++;
    }

    for(int k = inicio; k < fim; k++){
        aux[k] = arr[k];
    }

}

void MergeSort(int arr[], int inicio, int fim){
    int meio = inicio;

    if(inicio<fim){
        meio = (inicio + fim)/2;
        MergeSort(arr, inicio, meio);
        MergeSort(arr, meio + 1 , fim);
        intercalar(arr, inicio, meio, fim);
    }

}



int main(){

    int arr[8] = {5,1,3,4,2,8,6,7};
    
    MergeSort(arr, 0, 7);

    for(int i = 0; i <= 7; i++){
        cout<<arr[i]<< "\t";
    }
    
    return 0;
}