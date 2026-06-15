#include "Ordenacao.h"

// ordenacao por bolha - prioridade menor = mais urgente
void ordenarPorPrioridade(vector<Chamado>& vetor) {
    int n = vetor.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vetor[j].prioridade > vetor[j + 1].prioridade) {
                Chamado temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

// ordenacao por bolha - necessario para busca binaria por id
void ordenarPorId(vector<Chamado>& vetor) {
    int n = vetor.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vetor[j].id > vetor[j + 1].id) {
                Chamado temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}
