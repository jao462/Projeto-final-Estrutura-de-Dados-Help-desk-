#ifndef ENTIDADE_H
#define ENTIDADE_H

#include <string>

using namespace std;

struct Chamado {
    int id;
    string titulo;
    string descricao;
    string solicitante;
    string tecnico;
    int prioridade;   // 1 = alta, 2 = media, 3 = baixa
    string status;    // aberto, em andamento, resolvido
};

#endif
