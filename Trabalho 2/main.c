#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    int codigo;
    float preco;
    int quantidade;
} Produto;

typedef struct {
    Produto *produtos;
    int tamanho;
} Inventario;

void adicionarProduto(Inventario *inventario) {
    Produto p;
    printf("Digite o nome do produto: ");
    getchar();
    fgets(p.nome, 100, stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0';

    printf("Digite o código do produto: ");
    scanf("%d", &p.codigo);

    printf("Digite o preço do produto: ");
    scanf("%f", &p.preco);

    printf("Digite a quantidade do produto: ");
    scanf("%d", &p.quantidade);

    inventario->produtos = realloc(inventario->produtos, (inventario->tamanho + 1) * sizeof(Produto));
    if (inventario->produtos == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    inventario->produtos[inventario->tamanho] = p;
    inventario->tamanho++;
}

void listarProdutos(Inventario *inventario) {
    for (int i = 0; i < inventario->tamanho; i++) {
        printf("Nome: %s\n", inventario->produtos[i].nome);
        printf("Código: %d\n", inventario->produtos[i].codigo);
        printf("Preço: %.2f\n", inventario->produtos[i].preco);
        printf("Quantidade: %d\n\n", inventario->produtos[i].quantidade);
    }
}

void buscarProduto(Inventario *inventario, int codigo) {
    for (int i = 0; i < inventario->tamanho; i++) {
        if (inventario->produtos[i].codigo == codigo) {
            printf("Produto encontrado!\n");
            printf("Nome: %s\n", inventario->produtos[i].nome);
            printf("Código: %d\n", inventario->produtos[i].codigo);
            printf("Preço: %.2f\n", inventario->produtos[i].preco);
            printf("Quantidade: %d\n\n", inventario->produtos[i].quantidade);
            return;
        }
    }
    printf("Produto nao encontrado\n");
}

void salvarInventario(Inventario *inventario, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para salvar\n");
        exit(1);
    }

    fprintf(arquivo, "%d\n", inventario->tamanho);
    for (int i = 0; i < inventario->tamanho; i++) {
        fprintf(arquivo, "%s\n%d\n%.2f\n%d\n", inventario->produtos[i].nome, inventario->produtos[i].codigo,
                inventario->produtos[i].preco, inventario->produtos[i].quantidade);
    }

    fclose(arquivo);
}

void carregarInventario(Inventario *inventario, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para carregar\n");
        return;
    }

    fscanf(arquivo, "%d", &inventario->tamanho);
    inventario->produtos = malloc(inventario->tamanho * sizeof(Produto));

    for (int i = 0; i < inventario->tamanho; i++) {
        fscanf(arquivo, " %[^\n]", inventario->produtos[i].nome);
        fscanf(arquivo, "%d", &inventario->produtos[i].codigo);
        fscanf(arquivo, "%f", &inventario->produtos[i].preco);
        fscanf(arquivo, "%d", &inventario->produtos[i].quantidade);
    }

    fclose(arquivo);
}

int main() {
    Inventario inventario = {NULL, 0};
    int opcao;
    int codigo;

    while (1) {
        printf("1. Adicionar Produto\n2. Listar Produtos\n3. Buscar Produto\n4. Salvar Inventário\n5. Carregar Inventario\n6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto(&inventario);
                break;
            case 2:
                listarProdutos(&inventario);
                break;
            case 3:
                printf("Digite o código do produto a ser buscado: ");
                scanf("%d", &codigo);
                buscarProduto(&inventario, codigo);
                break;
            case 4:
                salvarInventario(&inventario, "inventario.txt");
                break;
            case 5:
                carregarInventario(&inventario, "inventario.txt");
                break;
            case 6:
                free(inventario.produtos);
                return 0;
            default:
                printf("Opção invalida\n");
        }
    }

    return 0;
}
