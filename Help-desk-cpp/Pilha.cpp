#include "Pilha.h"
#include <iostream>
using namespace std;

Pilha::Pilha() {
    topo = nullptr;
}

void Pilha::push(string acao) {
    NoPilha* novo = new NoPilha{acao, topo};
    topo = novo;
}

void Pilha::pop() {
    if (topo != nullptr) {
        NoPilha* temp = topo;
        topo = topo->prox;
        delete temp;
    }
}

void Pilha::mostrar() {
    NoPilha* aux = topo;

    cout << "\nHISTORICO:\n";
    while (aux != nullptr) {
        cout << "- " << aux->acao << "\n";
        aux = aux->prox;
    }
}
