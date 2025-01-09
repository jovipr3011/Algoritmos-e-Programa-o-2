#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char titulo[100];
    char autor[50];
    int ano_publicacao;
} Livro;

int main() {
    Livro livro;

    printf("Cadastro de Livro\n");
    printf("Digite o titulo do livro: ");
    fgets(livro.titulo, 100, stdin);
    int tamanho_titulo = strlen(livro.titulo);
    if (tamanho_titulo > 0 && livro.titulo[tamanho_titulo - 1] == '\n') {
        livro.titulo[tamanho_titulo - 1] = '\0';
    }

    printf("Digite o autor do livro: ");
    fgets(livro.autor, 50, stdin);
    int tamanho_autor = strlen(livro.autor);
    if (tamanho_autor > 0 && livro.autor[tamanho_autor - 1] == '\n') {
        livro.autor[tamanho_autor - 1] = '\0';
    }

    printf("Digite o ano de publicacao: ");
    scanf("%d", &livro.ano_publicacao);

    printf("\nInformacoes do Livro:\n");
    printf("Titulo: %s\n", livro.titulo);
    printf("Autor: %s\n", livro.autor);
    printf("Ano de Publicacao: %d\n", livro.ano_publicacao);

    return 0;
}
