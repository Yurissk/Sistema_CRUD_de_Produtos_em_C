
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
## Requisitos

- Compilador C (GCC, Clang, etc.)
- Sistema operacional Windows, Linux ou macOS

## Notas

- O sistema armazena produtos em memória durante a execução
- Os dados são perdidos ao encerrar o programa
- Máximo de 100 produtos pode ser armazenado inicialmente

## Melhorias Futuras

- Salvar dados em arquivo
- Busca por produto
- Ordenação de produtos
- Sistema de autenticação
