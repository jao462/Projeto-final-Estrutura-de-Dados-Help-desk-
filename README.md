# Projeto Help Desk - Estrutura de Dados

Sistema de suporte tecnico em C++ para gerenciamento de chamados.

## Estruturas utilizadas

- **Lista encadeada** - armazena os chamados (alocacao dinamica com `new`/`delete`)
- **Pilha** - guarda o historico de acoes do sistema
- **Ordenacao por bolha** - ordena chamados por prioridade ou por ID
- **Busca sequencial** - procura chamado na lista encadeada
- **Busca binaria** - procura chamado em vetor ordenado por ID

## Como compilar

```bash
cd Help-desk-cpp
g++ -o helpdesk main.cpp Menu.cpp ListaEncadead.cpp Pilha.cpp Ordenacao.cpp Busca.cpp
```

No Windows com MinGW ou g++ instalado, o mesmo comando funciona no PowerShell.

## Como executar

```bash
./helpdesk        # Linux/Mac
helpdesk.exe      # Windows
```

## Funcionalidades do menu

1. Abrir novo chamado
2. Listar chamados
3. Buscar por ID (sequencial)
4. Atualizar status
5. Atribuir tecnico
6. Ordenar por prioridade
7. Buscar por ID (binaria)
8. Ver historico (pilha)
9. Remover chamado
10. Salvar em arquivo
11. Carregar do arquivo

## Observacoes

- Nao utiliza `list`, `stack`, `queue` ou `map` da STL
- Permite `string`, `vector`, `iostream` e `fstream`
