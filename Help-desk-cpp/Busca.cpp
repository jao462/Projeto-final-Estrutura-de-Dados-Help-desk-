#include "Busca.h"

Ticket* Busca::sequencial(Ticket** v, int n, int id) {
    for (int i = 0; i < n; i++) {
        if (v[i]->id == id)
            return v[i];
    }
    return nullptr;
}

Ticket* Busca::binaria(Ticket** v, int n, int id) {
    int ini = 0, fim = n - 1;

    while (ini <= fim) {
        int meio = (ini + fim) / 2;

        if (v[meio]->id == id)
            return v[meio];

        if (v[meio]->id < id)
            ini = meio + 1;
        else
            fim = meio - 1;
    }

    return nullptr;
}
