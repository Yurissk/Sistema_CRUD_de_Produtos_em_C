#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "produto.h"

void limparBufferDeEntrada(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void verificarCapacidade(Produto **produtos, int *total, int *capacidade)
{
    if (*total >= *capacidade)
    {
        /*
        Se capacidade for 0, começa com 10
        caso contrario, dobra de tamanho
        */
        int novaCapacidade = (*capacidade == 0) ? 10 : (*capacidade * 2);

        printf("\n[Aviso] Aumentando Capacidade de %d para %d produtos\n", *capacidade, novaCapacidade);

        Produto *temp = realloc(*produtos, novaCapacidade * sizeof(Produto));

        if (temp == NULL)
        {
            printf("Erro critico: memoria insuficiente");
            free(*produtos);
            exit(1);
        }

        *produtos = temp;
        *capacidade = novaCapacidade;
    }
}

void cadastrarProduto(Produto **produtos, int *total, int *capacidade)
{
    int opcao;
    char buffer[50];

    do
    {
        printf("\n");
        printf("1 - Cadastrar novo produto\n");
        printf("2 - Sair para o Menu principal\n");
        printf("Escolha: ");

        if (scanf("%d", &opcao) != 1)
        {
            printf("Entrada invalida! Digite um numero.\n");
            limparBufferDeEntrada();
            continue;
        }

        limparBufferDeEntrada();

        switch (opcao)
        {

        case 1:

            verificarCapacidade(produtos, total, capacidade);
            printf("\n---Novo Produto---\n");

            printf("Nome: ");
            fgets((*produtos)[*total].nome, sizeof((*produtos)[*total].nome), stdin);
            (*produtos)[*total].nome[strcspn((*produtos)[*total].nome, "\n")] = '\0';

            printf("Preco: ");
            fgets(buffer, sizeof(buffer), stdin);
            (*produtos)[*total].preco = strtod(buffer, NULL);

            printf("Referencia: ");
            fgets(buffer, sizeof(buffer), stdin);
            (*produtos)[*total].ref = (int)strtol(buffer, NULL, 10);

            printf("Quantidade: ");
            fgets(buffer, sizeof(buffer), stdin);
            (*produtos)[*total].quantidade = (int)strtol(buffer, NULL, 10);

            (*total)++;

            for (int i = 0; i < *total; i++)
            {
                printf("\n___Lista atualizada____\n");
                printf("Nome: %s\n", (*produtos)[i].nome);
                printf("Preco: %.2f\n", (*produtos)[i].preco);
                printf("Referencia: %d\n", (*produtos)[i].ref);
                printf("Quantidade: %d\n", (*produtos)[i].quantidade);
            }

            break;
        case 2:
            printf("\nRetornando ao menu principal!\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }

    } while (opcao != 2);

    printf("\n");
}

void listarProdutos(Produto *produtos, int total)
{
    for (int i = 0; i < total; i++)
    {
        printf("Nome: %s\n", produtos[i].nome);
        printf("Preco: %.2f\n", produtos[i].preco);
        printf("Ref: %d\n", produtos[i].ref);
        printf("Qtd: %d\n\n", produtos[i].quantidade);

        printf("\n");
    }
}

void editarProdutos(Produto *produtos, int *total)
{
    int idx;

    if (*total == 0)
    {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    for (int i = 0; i < *total; i++)
    {
        printf("\n___Produtos Cadastrados____\n");
        printf("Indice - %d\n", i);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Preco: %.2f\n", produtos[i].preco);
        printf("Referencia: %d\n", produtos[i].ref);
        printf("Quantidade: %d\n", produtos[i].quantidade);
    }

    printf("\nIndice do produto: \n");
    scanf("%d", &idx);
    limparBufferDeEntrada();

    printf("\n");

    if (idx < 0 || idx >= *total)
    {
        printf("Indice invalido.\n");
        return;
    }

    printf("Novo nome: ");
    fgets(produtos[idx].nome, sizeof(produtos[idx].nome), stdin);
    produtos[idx].nome[strcspn(produtos[idx].nome, "\n")] = '\0';

    printf("Nova quantidade: ");
    scanf("%d", &produtos[idx].quantidade);

    printf("Novo preco: ");
    scanf("%lf", &produtos[idx].preco);

    printf("Nova ref: ");
    scanf("%d", &produtos[idx].ref);
    limparBufferDeEntrada();

    printf("\n");
}

void deletarProdutos(Produto *produtos, int *total)
{
    int idx;

    if (*total == 0)
    {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    for (int i = 0; i < *total; i++)
    {
        printf("\n___Produtos Cadastrados____\n");
        printf("Indice - %d\n", i);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Preco: %.2f\n", produtos[i].preco);
        printf("Referencia: %d\n", produtos[i].ref);
        printf("Quantidade: %d\n", produtos[i].quantidade);
    }

    printf("\nIndice do produto: \n");
    scanf("%d", &idx);
    limparBufferDeEntrada();

    if (idx < 0 || idx >= *total)
    {
        printf("Indice invalido.\n");
        return;
    }

    for (int i = idx; i < *total - 1; i++)
        produtos[i] = produtos[i + 1];

    (*total)--;

    printf("\n");
}
