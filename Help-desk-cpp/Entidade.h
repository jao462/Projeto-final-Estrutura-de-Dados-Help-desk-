#ifndef ENTIDADE_H
#define ENTIDADE_H

#include <string>
using namespace std;

struct Ticket {
    int id;
    string nome;
    string descricao;
    int prioridade; // 1 baixa, 2 media, 3 alta
};

#endif
