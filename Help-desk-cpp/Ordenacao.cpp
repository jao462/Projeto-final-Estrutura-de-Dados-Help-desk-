#include "Ordenacao.h"

void Ordenacao::bubbleSort(Ticket** v, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j]->prioridade < v[j + 1]->prioridade) {
                Ticket* temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

void Ordenacao::selectionSort(Ticket** v, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (v[j]->prioridade > v[min]->prioridade)
                min = j;
        }

        Ticket* temp = v[i];
        v[i] = v[min];
        v[min] = temp;
    }
}
