#ifndef BUSCA_H
#define BUSCA_H

#include <vector>
#include "Entidade.h"
#include "ListaEncadeada.h"

using namespace std;

Chamado* buscaSequencial(ListaEncadeada& lista, int id);
int buscaBinaria(vector<Chamado>& vetor, int id);

#endif
