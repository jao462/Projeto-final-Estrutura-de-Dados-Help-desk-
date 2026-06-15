#include "Busca.h"

Chamado* buscaSequencial(ListaEncadeada& lista, int id) {
    return lista.buscar(id);
}

int buscaBinaria(vector<Chamado>& vetor, int id) {
    int inicio = 0;
    int fim = vetor.size() - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (vetor[meio].id == id) {
            return meio;
        } else if (vetor[meio].id < id) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}
