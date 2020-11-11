#include <iostream>

using namespace std;

struct no{
    int info;
    struct no * next;
};

typedef struct no * noPtr;

noPtr topo = NULL;
noPtr topo2 = NULL;
noPtr topo3 = NULL;

noPtr enqueue(noPtr lista, noPtr topo){
    noPtr aux;
    int x = 0;
    while(x < 5){
        aux, lista = new no;
        cout<<"Insira um elemento para a lista:"<<endl;
        cin>> lista->info;
        lista->next = NULL;
        if(topo == NULL){
            topo = lista;
        }else{
            aux = topo;
            while(aux->next != NULL){
                aux = aux->next;
            }
            aux->next = lista;
        }
        x++;
    }
    return topo;
}

noPtr intercala(noPtr lista1, noPtr lista2){
    noPtr lista3, aux;
    lista1 = topo;
    lista2 = topo2;
    int cont1 = 0, cont2 = 0;
    while(lista1 != NULL || lista2 != NULL){
        if(cont1 == cont2){
            aux, lista3 = new no;
            lista3->info = lista1->info;
            lista3->next = NULL;
            if(topo3 == NULL){
                topo3 = lista3;
            }else{
                aux = topo3;
                while(aux->next != NULL){
                    aux = aux->next;
                }
                aux->next = lista3;
            }
            lista1 = lista1->next;
            cont1++;
        }else{
            aux, lista3 = new no;
            lista3->info = lista2->info;
            lista3->next = NULL;
            if(topo3 == NULL){
                topo3 = lista3;
            }else{
                aux = topo3;
                while(aux->next != NULL){
                    aux = aux->next;
                }
                aux->next = lista3;
            }
            lista2 = lista2->next;
            cont2++;
        }
    }
    return topo3;
}

int main(){
    noPtr lista1, lista2, lista3;
    topo = enqueue(lista1, topo);
    topo2 = enqueue(lista2, topo2);
    lista3 = intercala(lista1, lista2);

    while(lista3 != NULL){
        cout<<lista3->info<<"\t";
        lista3 = lista3->next;
    }

    return 0;
}