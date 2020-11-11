#include <iostream>

using namespace std;

struct no{
    int info;
    struct no * next;
};

typedef struct no * noPtr;

noPtr topo1 = NULL, topo2 = NULL, topo3 = NULL;