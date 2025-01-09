#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int matricula;
    float nota1;
    float nota2;
} Aluno;

int main() {
    Aluno aluno;
    float media;

    printf("Cadastro de Aluno\n");
    printf("Digite o nome do aluno: ");
    fgets(aluno.nome, 50, stdin);
    int tamanho_nome = strlen(aluno.nome);
    if (tamanho_nome > 0 && aluno.nome[tamanho_nome - 1] == '\n') {
        aluno.nome[tamanho_nome - 1] = '\0';
    }

    printf("Digite a matricula do aluno: ");
    scanf("%d", &aluno.matricula);

    printf("Digite a primeira nota: ");
    scanf("%f", &aluno.nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &aluno.nota2);

    media = (aluno.nota1 + aluno.nota2) / 2;

    printf("\nInformacoes do Aluno:\n");
    printf("Nome: %s\n", aluno.nome);
    printf("Matricula: %d\n", aluno.matricula);
    printf("Media: %.2f\n", media);

    return 0;
}
