#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    char telefone[15];
    char email[50];
} Contato;

int main() {
    Contato contato;

    printf("Cadastro de Contato\n");
    printf("Digite o nome do contato: ");
    fgets(contato.nome, 50, stdin);
    int tamanho_nome = strlen(contato.nome);
    if (tamanho_nome > 0 && contato.nome[tamanho_nome - 1] == '\n') {
        contato.nome[tamanho_nome - 1] = '\0';
    }

    printf("Digite o telefone do contato: ");
    fgets(contato.telefone, 15, stdin);
    int tamanho_telefone = strlen(contato.telefone);
    if (tamanho_telefone > 0 && contato.telefone[tamanho_telefone - 1] == '\n') {
        contato.telefone[tamanho_telefone - 1] = '\0';
    }

    printf("Digite o email do contato: ");
    fgets(contato.email, 50, stdin);
    int tamanho_email = strlen(contato.email);
    if (tamanho_email > 0 && contato.email[tamanho_email - 1] == '\n') {
        contato.email[tamanho_email - 1] = '\0';
    }

    printf("\nInformacoes do Contato:\n");
    printf("Nome: %s\n", contato.nome);
    printf("Telefone: %s\n", contato.telefone);
    printf("Email: %s\n", contato.email);

    return 0;
}
