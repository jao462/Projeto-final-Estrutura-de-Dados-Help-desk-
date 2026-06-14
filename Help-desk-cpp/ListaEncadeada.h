#ifndef LISTA_H
#define LISTA_H

#include "Entidade.h"

struct No {
    Ticket dado;
    No* prox;
};

class ListaEncadeada {
private:
    No* inicio;

public:
    ListaEncadeada();
    void inserir(Ticket t);
    void listar();
    Ticket* buscarPorId(int id);
    No* getInicio();
};

#endif
