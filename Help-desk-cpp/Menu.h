#ifndef MENU_H
#define MENU_H

#include <vector>
#include "ListaEncadeada.h"
#include "Pilha.h"

class Menu {
private:
    ListaEncadeada chamados;
    Pilha historico;
    int proximoId;

    void limparBuffer();
    void exibirChamado(Chamado* c);
    void copiarParaVetor(vector<Chamado>& vetor);

public:
    Menu();
    void executar();
};

#endif
