#ifndef PILHA_H
#define PILHA_H

#include <string>
using namespace std;

struct NoPilha {
    string acao;
    NoPilha* prox;
};

class Pilha {
private:
    NoPilha* topo;

public:
    Pilha();
    void push(string acao);
    void pop();
    void mostrar();
};

#endif
