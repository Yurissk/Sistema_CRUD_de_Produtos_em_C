# Sistema CRUD de Produtos em C

Um aplicativo simples de gerenciamento de produtos desenvolvido em linguagem C, com operações básicas de criar, ler, atualizar e deletar produtos.

## Características

- **Cadastrar Produtos**: Adicione novos produtos com nome, preço, referência e quantidade
- **Listar Produtos**: Visualize todos os produtos cadastrados
- **Editar Produtos**: Modifique informações de produtos existentes
- **Deletar Produtos**: Remova produtos do sistema
- **Menu Interativo**: Interface simples em linha de comando
- **Suporte a Português**: Toda a interface em português

## Estrutura do Projeto

```
Sistema_CRUD_de_Produtos_em_C/
├── include/
│   └── produto.h          # Definições de estruturas e funções
├── src/
│   ├── main.c             # Programa principal com menu
│   └── produto.c          # Implementação das operações CRUD
└── bin/                   # Diretório para executáveis compilados
```

## Compilação

Para compilar o projeto, use:

```bash
gcc -o bin/sistema src/main.c src/produto.c -I include
```

## Uso

Execute o programa:

```bash
bin/sistema
```

Você verá o menu principal:
```
1 - Cadastrar
2 - Listar
3 - Editar
4 - Deletar
0 - Sair
```

Escolha a opção desejada digitando o número correspondente.

## Dados de Produto

Cada produto contém:
- **Nome**: Nome do produto (até 50 caracteres)
- **Preço**: Valor do produto
- **Referência**: Código identificador único
- **Quantidade**: Quantidade em estoque

## Requisitos

- Compilador C (GCC, Clang, etc.)
- Sistema operacional Windows, Linux ou macOS

## Notas

- O sistema armazena produtos em memória durante a execução
- Os dados são perdidos ao encerrar o programa (sem persistência em arquivo)
- Máximo de 100 produtos pode ser armazenado inicialmente

## Melhorias Futuras

- Salvar dados em arquivo
- Busca por produto
- Ordenação de produtos
- Sistema de autenticação
