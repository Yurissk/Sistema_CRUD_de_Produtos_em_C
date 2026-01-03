#include <stdio.h>
#include <locale.h>
#include <string.h>

#define MAX_PRODUTOS 100

void limparBufferDeEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

struct produto
{
    char nome[50];
    double preco;
    int ref[4];
    int quantidade;
};

void cadastrarProduto(struct produto *produtos, int *total)
{
    int opcao;
    do
    {
        printf("1 - Adicionar novo produto\n");
        printf("2 - Sair para o Menu principal\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        limparBufferDeEntrada();

        switch (opcao)
        {
        case 1:
            printf("\nCadastrando novo produto...\n");

            printf("Nome: ");
            fgets(produtos[*total].nome, sizeof(produtos[*total].nome), stdin);
            produtos[*total].nome[strcspn(produtos[*total].nome, "\n")] = '\0'; // remove o \n

            printf("Preço: R$ ");
            scanf("%lf", &produtos[*total].preco);

            printf("Referência (número inteiro): ");
            scanf("%d", &produtos[*total].ref);

            printf("Quantidade: ");
            scanf("%d", &produtos[*total].quantidade);
            limparBufferDeEntrada();

            (*total)++; // incrementa o total
            printf("\n Produto cadastrado com sucesso!\n");
            break;

        case 2:
            printf("\nVoltando ao menu principal...\n");
            break;

        default:
            printf("\nOpção inválida!\n");
        }
    } while (opcao != 2);
}

void listarProdutos(struct produto *produtos, int *total){
    for (int i = 0; i < *total; i++)
    {
        printf("Nome: %s\n", produtos[i].nome);
        printf("Preço: %lf\n", produtos[i].preco);
        printf("Referencia: %d\n", produtos[i].ref);
        printf("Estoque: %d\n", produtos[i].quantidade);
    }
}

void editarProdutos(struct produto *produtos, int *total){
    int escolhaProduto;

    for(int i = 0; i < *total; i++){
        printf("Produto: %d", i);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Referencia: %d\n", produtos[i].ref);
    }

    printf("\nSelecione o produto por indice que deseja editar: \n");
    scanf("%d", &escolhaProduto);
    limparBufferDeEntrada();

    if (escolhaProduto >= 0 && escolhaProduto < *total)
    {   
        int escolhaEdicao;
        printf("Você escolheu o produto: %d - %s\n Quantidade: %d\n Preco: %f", produtos[escolhaProduto].ref, 
        produtos[escolhaProduto].nome, 
        produtos[escolhaProduto].quantidade, 
        produtos[escolhaProduto].preco);

        printf("\n");
        printf("O que deseja atualizar?\n 1. Nome \n 2. Quantidade \n 3. Preco \n 4. ref \n 5. Editar todos");
        scanf("%d", &escolhaEdicao);
        limparBufferDeEntrada();


        switch (escolhaEdicao)
        {
        case 1:
            printf("Nome atual: %s\n", produtos[escolhaProduto].nome);
            printf("Novo nome: \n");
            fgets(produtos[escolhaProduto].nome, sizeof(produtos[escolhaProduto].nome), stdin);
            produtos[escolhaProduto].nome[strcspn(produtos[escolhaProduto].nome, "\n")] = '\0';

            break;
        case 2:
            printf("Quantidade atual: %d\n", produtos[escolhaProduto].quantidade);
            printf("Nova quantidade: \n");
            scanf("%d", &produtos[escolhaProduto].quantidade);
            limparBufferDeEntrada(); 
            break;
        case 3:
            printf("Preco atual: %f\n", produtos[escolhaProduto].preco);
            printf("Novo preco: \n");
            scanf("%lf", &produtos[escolhaProduto].preco);
            limparBufferDeEntrada(); 
            break;
        case 4:
            printf("REF atual: %d\n", produtos[escolhaProduto].ref);
            printf("Nova REF: \n");
            scanf("%d", &produtos[escolhaProduto].ref);
            limparBufferDeEntrada(); 
            break;
        case 5:
            printf("Nome atual: %s\n", produtos[escolhaProduto].nome);
            printf("Novo nome: \n");
            fgets(produtos[escolhaProduto].nome, sizeof(produtos[escolhaProduto].nome), stdin);
            produtos[escolhaProduto].nome[strcspn(produtos[escolhaProduto].nome, "\n")] = '\0';

            printf("Quantidade atual: %d\n", produtos[escolhaProduto].quantidade);
            printf("Nova quantidade: \n");
            scanf("%d", &produtos[escolhaProduto].quantidade);
            limparBufferDeEntrada(); 

            printf("Preco atual: %f\n", produtos[escolhaProduto].preco);
            printf("Novo preco: \n");
            scanf("%lf", &produtos[escolhaProduto].preco);
            limparBufferDeEntrada(); 

            printf("REF atual: %d\n", produtos[escolhaProduto].ref);
            printf("Nova REF: \n");
            scanf("%d", &produtos[escolhaProduto].ref);
            limparBufferDeEntrada(); 
            break;
        
        default:
        printf("Opcao invalida.\n");
            break;
        }
    } else {
        printf("Opcao invalida.\n");
    }

}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    struct produto produtos[MAX_PRODUTOS];
    int totalProdutos = 0;
    int total = 0;
    int opcao;

    do
    {
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Editar produto\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        limparBufferDeEntrada();

        switch (opcao)
        {
        case 1:
            cadastrarProduto(produtos, &totalProdutos);
            break;

        case 2:
            printf("\nLista de produtos cadastrados no sistema:\n");

            listarProdutos(produtos, &totalProdutos);
            break;

        case 3:
            editarProdutos(produtos, &totalProdutos);
            break;

        case 0:
            printf("\nSaindo do sistema...\n");
            break;

        default:
            printf("\nOpção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}
