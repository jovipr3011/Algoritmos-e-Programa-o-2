#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    float salario;
} Funcionario;

int main() {
    Funcionario funcionario;

    printf("Cadastro de Funcionario\n");
    printf("Digite o nome do funcionario: ");
    fgets(funcionario.nome, 50, stdin);
    int tamanho_nome = strlen(funcionario.nome);
    if (tamanho_nome > 0 && funcionario.nome[tamanho_nome - 1] == '\n') {
        funcionario.nome[tamanho_nome - 1] = '\0';
    }

    printf("Digite a idade do funcionario: ");
    scanf("%d", &funcionario.idade);

    printf("Digite o salario do funcionario: ");
    scanf("%f", &funcionario.salario);

    printf("\n Informacoes do funcionario:\n");
    printf("Nome: %s\n", funcionario.nome);
    printf("Idade: %d\n", funcionario.idade);
    printf("Salario: %.2f\n", funcionario.salario);

    return 0;
}
