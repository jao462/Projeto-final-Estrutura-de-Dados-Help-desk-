#include "ListaEncadeada.h"
#include <iostream>

using namespace std;

ListaEncadeada::ListaEncadeada() {
    inicio = nullptr;
    contador = 0;
}

ListaEncadeada::~ListaEncadeada() {
    limpar();
}

void ListaEncadeada::inserir(Chamado c) {
    No* novo = new No;
    novo->dados = c;
    novo->prox = nullptr;

    if (inicio == nullptr) {
        inicio = novo;
    } else {
        No* atual = inicio;
        while (atual->prox != nullptr) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
    contador++;
}

bool ListaEncadeada::remover(int id) {
    if (inicio == nullptr) {
        return false;
    }

    No* atual = inicio;
    No* anterior = nullptr;

    while (atual != nullptr) {
        if (atual->dados.id == id) {
            if (anterior == nullptr) {
                inicio = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            delete atual;
            contador--;
            return true;
        }
        anterior = atual;
        atual = atual->prox;
    }
    return false;
}

Chamado* ListaEncadeada::buscar(int id) {
    No* atual = inicio;
    while (atual != nullptr) {
        if (atual->dados.id == id) {
            return &atual->dados;
        }
        atual = atual->prox;
    }
    return nullptr;
}

void ListaEncadeada::listar() {
    if (inicio == nullptr) {
        cout << "Nenhum chamado cadastrado.\n";
        return;
    }

    No* atual = inicio;
    cout << "\n--- LISTA DE CHAMADOS ---\n";
    while (atual != nullptr) {
        cout << "ID: " << atual->dados.id
             << " | " << atual->dados.titulo
             << " | Prioridade: " << atual->dados.prioridade
             << " | Status: " << atual->dados.status
             << " | Tecnico: " << atual->dados.tecnico << "\n";
        atual = atual->prox;
    }
    cout << "-------------------------\n";
}

int ListaEncadeada::getTamanho() {
    return contador;
}

void ListaEncadeada::limpar() {
    No* atual = inicio;
    while (atual != nullptr) {
        No* temp = atual;
        atual = atual->prox;
        delete temp;
    }
    inicio = nullptr;
    contador = 0;
}

No* ListaEncadeada::getInicio() {
    return inicio;
}
