#include "Menu.h"
#include "ListaEncadeada.h"
#include "Pilha.h"
#include "Ordenacao.h"
#include "Busca.h"
#include <iostream>
using namespace std;

void Menu::executar() {
    ListaEncadeada lista;
    Pilha pilha;
    Ordenacao ord;
    Busca bus;

    int op;
    int id = 1;

    do {
        cout << "\n===== HELP DESK =====\n";
        cout << "1. Abrir chamado\n";
        cout << "2. Listar chamados\n";
        cout << "3. Ver historico\n";
        cout << "4. Sair\n";
        cout << "Opcao: ";
        cin >> op;

        if (op == 1) {
            Ticket t;
            t.id = id++;

            cin.ignore();
            cout << "Nome: ";
            getline(cin, t.nome);

            cout << "Descricao: ";
            getline(cin, t.descricao);

            cout << "Prioridade (1-3): ";
            cin >> t.prioridade;

            lista.inserir(t);
            pilha.push("Chamado aberto: " + t.nome);
        }

        else if (op == 2) {
            lista.listar();
        }

        else if (op == 3) {
            pilha.mostrar();
        }

    } while (op != 4);
}
