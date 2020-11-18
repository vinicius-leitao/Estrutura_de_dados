#include <iostream>

using namespace std;

int main(){

    int a, * p;

    a = 30;
    p = &a;

    cout<< a << "\n";
    cout<< p << "\n";
    cout<< &p << "\n";
    cout<< &a << "\n";
    cout<< *p << "\n";


    return 0;
}