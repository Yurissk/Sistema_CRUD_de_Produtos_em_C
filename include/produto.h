#ifndef PRODUTO_H
#define PRODUTO_H

#define MAX_PRODUTOS 100

typedef struct produto
{
    char nome[50];
    double preco;
    int ref;
    int quantidade;
} Produto;

void limparBufferDeEntrada(void);

void cadastrarProduto(Produto *produtos, int *total);

void listarProdutos(Produto *produtos, int total);

void editarProdutos(Produto *produtos, int *total);

void deletarProdutos(Produto *produtos, int *total);

#endif
