#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int codigo;
    float preco;
    int quantidade;
} Produto;

int main() {
    Produto produto;
    float valor_total;

    printf("Cadastro de Produto\n");
    printf("Digite o nome do produto: ");
    fgets(produto.nome, 50, stdin);
    int tamanho_nome = strlen(produto.nome);
    if (tamanho_nome > 0 && produto.nome[tamanho_nome - 1] == '\n') {
        produto.nome[tamanho_nome - 1] = '\0';
    }

    printf("Digite o codigo do produto: ");
    scanf("%d", &produto.codigo);

    printf("Digite o preco do produto: ");
    scanf("%f", &produto.preco);

    printf("Digite a quantidade em estoque: ");
    scanf("%d", &produto.quantidade);

    valor_total = produto.preco * produto.quantidade;

    printf("\nInformacoes do Produto:\n");
    printf("Nome: %s\n", produto.nome);
    printf("Codigo: %d\n", produto.codigo);
    printf("Preco: %.2f\n", produto.preco);
    printf("Quantidade: %d\n", produto.quantidade);
    printf("Valor total em estoque: %.2f\n", valor_total);

    return 0;
}

