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
    int tamanho;

public:
    Pilha();
    ~Pilha();

    void empilhar(string acao);
    string desempilhar();
    bool vazia();
    void listar();
    void limpar();
};

#endif
