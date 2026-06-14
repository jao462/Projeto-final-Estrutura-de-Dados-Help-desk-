#ifndef BUSCA_H
#define BUSCA_H

#include "Entidade.h"

class Busca {
public:
    Ticket* sequencial(Ticket** v, int n, int id);
    Ticket* binaria(Ticket** v, int n, int id);
};

#endif
