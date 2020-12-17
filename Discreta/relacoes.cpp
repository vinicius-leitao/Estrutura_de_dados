#include <iostream>
#include <time.h>
#include <locale.h>

using namespace std;

//Aluno: Vinícius Leitão
//Mat: 1923125BCC

int main(){
    //Acentuação para melhor experiência do usuário, lembrar de executar o comando chcp 65001 no terminal.
    setlocale(LC_ALL, "Portuguese_Brasil");

    // Seed da função rand. Vai gerar uma matriz da relação sempre diferente para verificação das propriedades: reflexiva, simétrica e transitiva.
    srand(time(NULL));

    //Pedindo a ordem da matriz quadrada, isto é, o número de elementos que serão relacionados.
    int n;
    cout<<"Insira a ordem da matriz quadrada:"<<endl;
    cin>> n;

    //Inicializo a matriz com a ordem já estipulada.
    int matriz[n][n];

    //Crio e imprimo a matriz para uma melhor visualização do usuário.
    cout<<"A matriz da relação é dada por:"<<endl;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++){
            matriz[i][j] = rand() % 2;
            if(j==0)
                cout<<"|"<<"\t"<< matriz[i][j]<<"\t";
            else if(j == n-1)
                cout<< matriz[i][j]<<"\t"<<"|"<<endl;
            else
                cout<< matriz[i][j]<<"\t";   
        }

    //Verificando as propriedades da relação.

    //Verificando se a relação é reflexiva, olhando apenas para a diagonal principal.
    for(int x = 0; x<n; x++)
        if(matriz[x][x] == 1){
            if(x==n-1)
                cout<<"A relação é reflexiva!"<<endl;
        }
        else{
            cout<<"A relação não é reflexiva!"<<endl;
            break;
        }  

    //Verificar se a relação é simétrica.

    //Inicializo uma booleana para verificar se o segundo loop foi interrompido.
    bool simetrica = true;
    
    for(int y = 0; y<n && simetrica; y++){
        for(int z = 0; z<n && simetrica; z++){
            if(y!=z){
                if((matriz[y][z] == 1 && matriz[z][y] == 1)||(matriz[y][z] == 0 && matriz[z][y]==0)){
                }
                else{
                    cout<<"A relação não é simétrica!"<<endl;
                    simetrica = false;
                    break;
                }    
            }   
        }
    }
    if(simetrica){
        cout<<"A relação é simétrica!"<<endl;
    }

    //Verificando se a relação é transitiva;

    bool transitiva = true;

    for(int a = 0; a< n && transitiva; a++){
        for(int b = 0; b< n && transitiva; b++){
            int c = 0;
            while(c < n){
                if((matriz[a][b] == 1 && matriz[b][c] ==1) && matriz[a][c] == 1){
                }
                else{
                    cout<<"A relação não é transitiva!"<<endl;
                    transitiva = false;
                    break;
                }
                c++;
            }
        }
    }
    if(transitiva){
        cout<<"A relação é transitiva!"<<endl;
    }

    return 0;
}