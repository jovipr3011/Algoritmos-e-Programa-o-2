#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    float notas[3];
    float media;
} Aluno;

Aluno alunos[100];
int quantidade = 0;

void adicionarAluno() {
    if (quantidade < 100) {
        printf("Digite o nome do aluno: ");
        scanf("%s", alunos[quantidade].nome);

        float soma = 0;
        for (int i = 0; i < 3; i++) {
            printf("Digite a nota %d: ", i + 1);
            scanf("%f", &alunos[quantidade].notas[i]);
            soma += alunos[quantidade].notas[i];
        }

        alunos[quantidade].media = soma / 3;
        quantidade++;
    } else {
        printf("Limite de alunos atingido\n");
    }
}

void listarAlunos() {
    if (quantidade == 0) {
        printf("Nenhum aluno cadastrado\n");
    }else{

    printf("\nLista de Alunos:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("Nome: %s, Media: %.2f\n", alunos[i].nome, alunos[i].media);
    }
}
}

int main() {
    int opcao;

    do {
        printf("\n1. Adicionar Aluno\n");
        printf("2. Listar Alunos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarAluno();
                break;
            case 2:
                listarAlunos();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
