#include "Menu.h"
#include "Busca.h"
#include "Ordenacao.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

Menu::Menu() {
    proximoId = 1;
}

void Menu::limparBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Menu::exibirChamado(Chamado* c) {
    if (c == nullptr) {
        cout << "Chamado nao encontrado.\n";
        return;
    }

    cout << "\nID: " << c->id << "\n";
    cout << "Titulo: " << c->titulo << "\n";
    cout << "Descricao: " << c->descricao << "\n";
    cout << "Solicitante: " << c->solicitante << "\n";
    cout << "Tecnico: " << c->tecnico << "\n";
    cout << "Prioridade: " << c->prioridade << " (1=alta, 2=media, 3=baixa)\n";
    cout << "Status: " << c->status << "\n";
}

void Menu::copiarParaVetor(vector<Chamado>& vetor) {
    vetor.clear();
    No* atual = chamados.getInicio();
    while (atual != nullptr) {
        vetor.push_back(atual->dados);
        atual = atual->prox;
    }
}

void Menu::executar() {
    int opcao = -1;

    while (opcao != 0) {
        cout << "\n====== HELP DESK - SUPORTE TECNICO ======\n";
        cout << "1 - Abrir novo chamado\n";
        cout << "2 - Listar chamados\n";
        cout << "3 - Buscar chamado (busca sequencial)\n";
        cout << "4 - Atualizar status\n";
        cout << "5 - Atribuir tecnico\n";
        cout << "6 - Ordenar por prioridade\n";
        cout << "7 - Buscar chamado (busca binaria)\n";
        cout << "8 - Ver historico de acoes\n";
        cout << "9 - Remover chamado\n";
        cout << "10 - Salvar em arquivo\n";
        cout << "11 - Carregar do arquivo\n";
        cout << "0 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        if (cin.fail()) {
            limparBuffer();
            cout << "Opcao invalida.\n";
            continue;
        }

        if (opcao == 1) {
            Chamado c;
            c.id = proximoId++;
            limparBuffer();

            cout << "Titulo: ";
            getline(cin, c.titulo);
            cout << "Descricao: ";
            getline(cin, c.descricao);
            cout << "Solicitante: ";
            getline(cin, c.solicitante);

            cout << "Prioridade (1=alta, 2=media, 3=baixa): ";
            cin >> c.prioridade;

            c.tecnico = "nao atribuido";
            c.status = "aberto";

            chamados.inserir(c);
            historico.empilhar("Chamado #" + to_string(c.id) + " aberto por " + c.solicitante);
            cout << "Chamado cadastrado com sucesso! ID: " << c.id << "\n";

        } else if (opcao == 2) {
            chamados.listar();

        } else if (opcao == 3) {
            int id;
            cout << "Digite o ID: ";
            cin >> id;

            Chamado* encontrado = buscaSequencial(chamados, id);
            if (encontrado != nullptr) {
                cout << "Encontrado com busca sequencial!\n";
                exibirChamado(encontrado);
            } else {
                cout << "Chamado nao encontrado.\n";
            }

        } else if (opcao == 4) {
            int id;
            cout << "ID do chamado: ";
            cin >> id;
            limparBuffer();

            Chamado* c = chamados.buscar(id);
            if (c == nullptr) {
                cout << "Chamado nao encontrado.\n";
                continue;
            }

            cout << "Novo status (aberto / em andamento / resolvido): ";
            getline(cin, c->status);

            historico.empilhar("Status do chamado #" + to_string(id) + " alterado para " + c->status);
            cout << "Status atualizado.\n";

        } else if (opcao == 5) {
            int id;
            cout << "ID do chamado: ";
            cin >> id;
            limparBuffer();

            Chamado* c = chamados.buscar(id);
            if (c == nullptr) {
                cout << "Chamado nao encontrado.\n";
                continue;
            }

            cout << "Nome do tecnico: ";
            getline(cin, c->tecnico);

            historico.empilhar("Tecnico " + c->tecnico + " atribuido ao chamado #" + to_string(id));
            cout << "Tecnico atribuido.\n";

        } else if (opcao == 6) {
            vector<Chamado> vetor;
            copiarParaVetor(vetor);

            if (vetor.empty()) {
                cout << "Nao ha chamados para ordenar.\n";
                continue;
            }

            ordenarPorPrioridade(vetor);

            cout << "\n--- CHAMADOS ORDENADOS POR PRIORIDADE ---\n";
            for (int i = 0; i < (int)vetor.size(); i++) {
                cout << "ID: " << vetor[i].id
                     << " | " << vetor[i].titulo
                     << " | Prioridade: " << vetor[i].prioridade
                     << " | Status: " << vetor[i].status << "\n";
            }
            cout << "-----------------------------------------\n";

        } else if (opcao == 7) {
            int id;
            cout << "Digite o ID: ";
            cin >> id;

            vector<Chamado> vetor;
            copiarParaVetor(vetor);

            if (vetor.empty()) {
                cout << "Nao ha chamados cadastrados.\n";
                continue;
            }

            ordenarPorId(vetor);
            int pos = buscaBinaria(vetor, id);

            if (pos != -1) {
                cout << "Encontrado com busca binaria!\n";
                exibirChamado(&vetor[pos]);
            } else {
                cout << "Chamado nao encontrado.\n";
            }

        } else if (opcao == 8) {
            historico.listar();

        } else if (opcao == 9) {
            int id;
            cout << "ID do chamado a remover: ";
            cin >> id;

            if (chamados.remover(id)) {
                historico.empilhar("Chamado #" + to_string(id) + " removido");
                cout << "Chamado removido.\n";
            } else {
                cout << "Chamado nao encontrado.\n";
            }

        } else if (opcao == 10) {
            ofstream arquivo("chamados.txt");
            if (!arquivo.is_open()) {
                cout << "Erro ao abrir arquivo para salvar.\n";
                continue;
            }

            arquivo << proximoId << "\n";
            No* atual = chamados.getInicio();
            while (atual != nullptr) {
                arquivo << atual->dados.id << "|"
                        << atual->dados.titulo << "|"
                        << atual->dados.descricao << "|"
                        << atual->dados.solicitante << "|"
                        << atual->dados.tecnico << "|"
                        << atual->dados.prioridade << "|"
                        << atual->dados.status << "\n";
                atual = atual->prox;
            }
            arquivo.close();
            cout << "Dados salvos em chamados.txt\n";

        } else if (opcao == 11) {
            ifstream arquivo("chamados.txt");
            if (!arquivo.is_open()) {
                cout << "Arquivo nao encontrado.\n";
                continue;
            }

            chamados.limpar();
            historico.limpar();

            arquivo >> proximoId;
            limparBuffer();

            string linha;
            while (getline(arquivo, linha)) {
                if (linha.empty()) continue;

                Chamado c;
                size_t p1 = linha.find('|');
                size_t p2 = linha.find('|', p1 + 1);
                size_t p3 = linha.find('|', p2 + 1);
                size_t p4 = linha.find('|', p3 + 1);
                size_t p5 = linha.find('|', p4 + 1);
                size_t p6 = linha.find('|', p5 + 1);

                c.id = stoi(linha.substr(0, p1));
                c.titulo = linha.substr(p1 + 1, p2 - p1 - 1);
                c.descricao = linha.substr(p2 + 1, p3 - p2 - 1);
                c.solicitante = linha.substr(p3 + 1, p4 - p3 - 1);
                c.tecnico = linha.substr(p4 + 1, p5 - p4 - 1);
                c.prioridade = stoi(linha.substr(p5 + 1, p6 - p5 - 1));
                c.status = linha.substr(p6 + 1);

                chamados.inserir(c);
            }
            arquivo.close();
            historico.empilhar("Dados carregados do arquivo");
            cout << "Dados carregados com sucesso.\n";

        } else if (opcao == 0) {
            cout << "Encerrando sistema...\n";
        } else {
            cout << "Opcao invalida.\n";
        }
    }
}
