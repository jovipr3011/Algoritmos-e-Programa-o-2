#include <stdio.h>
#include "alunos.h"

void adicionarAluno(Aluno alunos[], int *quantidade) {
    if (*quantidade < 100) {
        printf("Digite o nome do aluno: ");
        scanf("%s", alunos[*quantidade].nome);

        float soma = 0;
        for (int i = 0; i < 3; i++) {
            printf("Digite a nota %d: ", i + 1);
            scanf("%f", &alunos[*quantidade].notas[i]);
            soma += alunos[*quantidade].notas[i];
        }

        alunos[*quantidade].media = soma / 3;
        (*quantidade)++;
    } else {
        printf("Limite de alunos atingido\n");
    }
}

void listarAlunos(Aluno alunos[], int quantidade) {
    if (quantidade == 0) {
        printf("Nenhum aluno cadastrado\n");
    } else {
        printf("\nLista de alunos:\n");
        for (int i = 0; i < quantidade; i++) {
            printf("Nome: %s, Media: %.2f\n", alunos[i].nome, alunos[i].media);
        }
    }
}

int main() {
    Aluno alunos[100];
    int quantidade = 0;
    int opcao;

    do {
        printf("\n1. Adicionar Aluno\n");
        printf("2. Listar Alunos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarAluno(alunos, &quantidade);
                break;
            case 2:
                listarAlunos(alunos, quantidade);
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
