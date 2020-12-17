#include <iostream>
#include <locale.h>
#include <ctime>

using namespace std;

struct no{
    int info;
    struct no * prev;
    struct no * next;
};

typedef struct no * noPtr;

void criarRoleta(noPtr *);
bool emptyList(noPtr);
void roletar(noPtr);

int main(){
    // Lembrar de inserir o comando chcp 65001 no terminal.
    setlocale(LC_ALL, "Portuguese_Brasil");
    noPtr topo = NULL;
    int op;

    do{
        cout<<"Digite uma operação a ser realizada:"<<endl<<"(1) Construir nova roleta"<<endl<<"(2) Roletar"<<endl<<"(0) Sair"<<endl;
        cin>> op;

        switch(op) {
            case 0: break;
            case 1: criarRoleta(&topo);
            case 2: roletar(topo);
        }
    }while(op!=0);

    return 0;
}

void criarRoleta(noPtr * t){
    for(int j = 0; j< 15; j++){
    noPtr p = new no;
    cout<<"Insira o elemento desejado para a lista:"<<endl;
    cin >> p->info;
    

    if(emptyList(*t)){
        *t = p;
        p->next = *t;
        p->prev = p;
    }else{
        p->next = *t;
        p->prev = (*t)->prev;
        (*t)->prev->next = p;
        *t = p;
    }
    }
}

void roletar(noPtr t){
    if(!emptyList(t)){
        int num = 0;
        unsigned seed  = time(0);
        srand(seed);
        int random = rand()% 100 + 11;
        cout<<"A roleta possui números de 0 a 15, escolha com sabedoria e boa sorte!"<<endl;
        cout<<"Escolha um número:"<<endl;
        cin>> num;
        cout<<"Certo, você escolheu o número"<<" "<< num <<" "<<endl<<"Roletando..."<<endl;
        for(int i=0; i <= random; i++){
            t = t->next;
        }
        if(t->info == num)
            cout<<"Mas que sorte! Você ganhou!"<<endl;
        else
            cout<<"Que pena, não foi dessa vez."<<endl;
            
    }else
        cout<< "A lista está vazia!"<<endl;
}

bool emptyList(noPtr t){
    if(t)
        return false;
    else
        return true;
}