#include <stdio.h>
#include <string.h>
#include "produto.h"

void limparBufferDeEntrada(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrarProduto(Produto *produtos, int *total)
{
    int opcao;

    do
    {
        printf("1 - Cadastrar novo produto\n");
        printf("2 - Sair para o Menu principal\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        limparBufferDeEntrada();

        if (opcao == 1)
        {
            printf("Nome: ");
            fgets(produtos[*total].nome, sizeof(produtos[*total].nome), stdin);
            produtos[*total].nome[strcspn(produtos[*total].nome, "\n")] = '\0';

            printf("Preco: ");
            scanf("%lf", &produtos[*total].preco);

            printf("Referencia: ");
            scanf("%d", &produtos[*total].ref);

            printf("Quantidade: ");
            scanf("%d", &produtos[*total].quantidade);
            limparBufferDeEntrada();

            (*total)++;
        }

    } while (opcao != 2);
}

void listarProdutos(Produto *produtos, int total)
{
    for (int i = 0; i < total; i++)
    {
        printf("Nome: %s\n", produtos[i].nome);
        printf("Preco: %.2f\n", produtos[i].preco);
        printf("Ref: %d\n", produtos[i].ref);
        printf("Qtd: %d\n\n", produtos[i].quantidade);
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

    printf("Indice do produto: \n");
    scanf("%d", &idx);
    limparBufferDeEntrada();

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
}

void deletarProdutos(Produto *produtos, int *total)
{
    int idx;

    if (*total == 0)
    {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("Indice do produto: ");
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
}
