#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include "Entidade.h"

struct No {
    Chamado dados;
    No* prox;
};

class ListaEncadeada {
private:
    No* inicio;
    int contador;

public:
    ListaEncadeada();
    ~ListaEncadeada();

    void inserir(Chamado c);
    bool remover(int id);
    Chamado* buscar(int id);
    void listar();
    int getTamanho();
    void limpar();
    No* getInicio();
};

#endif
