#include <stdio.h>
#include <locale.h>
#include "produto.h"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Produto *produtos = NULL;

    int total = 0;
    int capacidade = 0;
    int opcao;

    do
    {
        printf("1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("3 - Editar\n");
        printf("4 - Deletar\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);
        limparBufferDeEntrada();

        switch (opcao)
        {
        case 1:
            cadastrarProduto(&produtos, &total, &capacidade);
            break;
        case 2:
            listarProdutos(produtos, total);
            break;
        case 3:
            editarProdutos(produtos, &total);
            break;
        case 4:
            deletarProdutos(produtos, &total);
            break;
        }
    } while (opcao != 0);

    return 0;
}
