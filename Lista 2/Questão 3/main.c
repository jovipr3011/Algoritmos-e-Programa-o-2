#include <stdio.h>
#include <string.h>
#include "login.h"

void cadastrarUsuario(Usuario usuarios[], int *quantidade) {
    if (*quantidade < 100) {
        printf("Digite o nome do usuario: ");
        scanf("%s", usuarios[*quantidade].usuario);
        printf("Digite a senha: ");
        scanf("%s", usuarios[*quantidade].senha);
        (*quantidade)++;
        printf("Usuario cadastrado com sucesso\n");
    } else {
        printf("Limite de usuarios atingido\n");
    }
}

int autenticarUsuario(Usuario usuarios[], int quantidade) {
    char usuario[50], senha[50];
    printf("Digite o nome do usuario: ");
    scanf("%s", usuario);
    printf("Digite a senha: ");
    scanf("%s", senha);

    for (int i = 0; i < quantidade; i++) {
        if (strcmp(usuarios[i].usuario, usuario) == 0 && strcmp(usuarios[i].senha, senha) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    Usuario usuarios[100];
    int quantidade = 0;
    int opcao;

    do {
        printf("\n1. Cadastrar Usuario\n");
        printf("2. Autenticar Usuario\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarUsuario(usuarios, &quantidade);
                break;
            case 2:
                if (autenticarUsuario(usuarios, quantidade)) {
                    printf("Login realizado com sucesso\n");
                } else {
                    printf("Usuario ou senha invalidos\n");
                }
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida\n");
        }
    } while (opcao != 0);

    return 0;
}
