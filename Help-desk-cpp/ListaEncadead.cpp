#include "ListaEncadeada.h"
#include <iostream>
using namespace std;

ListaEncadeada::ListaEncadeada() {
    inicio = nullptr;
}

void ListaEncadeada::inserir(Ticket t) {
    No* novo = new No{t, inicio};
    inicio = novo;
}

void ListaEncadeada::listar() {
    No* aux = inicio;

    while (aux != nullptr) {
        cout << "\nID: " << aux->dado.id;
        cout << "\nNome: " << aux->dado.nome;
        cout << "\nDescricao: " << aux->dado.descricao;
        cout << "\nPrioridade: " << aux->dado.prioridade << "\n";
        aux = aux->prox;
    }
}

Ticket* ListaEncadeada::buscarPorId(int id) {
    No* aux = inicio;

    while (aux != nullptr) {
        if (aux->dado.id == id)
            return &aux->dado;
        aux = aux->prox;
    }
    return nullptr;
}

No* ListaEncadeada::getInicio() {
    return inicio;
}
