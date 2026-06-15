#include "Pilha.h"
#include <iostream>

using namespace std;

Pilha::Pilha() {
    topo = nullptr;
    tamanho = 0;
}

Pilha::~Pilha() {
    limpar();
}

void Pilha::empilhar(string acao) {
    NoPilha* novo = new NoPilha;
    novo->acao = acao;
    novo->prox = topo;
    topo = novo;
    tamanho++;
}

string Pilha::desempilhar() {
    if (topo == nullptr) {
        return "";
    }

    NoPilha* temp = topo;
    string acao = temp->acao;
    topo = topo->prox;
    delete temp;
    tamanho--;
    return acao;
}

bool Pilha::vazia() {
    return topo == nullptr;
}

void Pilha::listar() {
    if (vazia()) {
        cout << "Historico vazio.\n";
        return;
    }

    cout << "\n--- HISTORICO DE ACOES (pilha) ---\n";
    NoPilha* atual = topo;
    int i = 1;
    while (atual != nullptr) {
        cout << i << ". " << atual->acao << "\n";
        atual = atual->prox;
        i++;
    }
    cout << "----------------------------------\n";
}

void Pilha::limpar() {
    while (!vazia()) {
        desempilhar();
    }
}
