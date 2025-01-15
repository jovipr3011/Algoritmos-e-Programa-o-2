#include <stdio.h>
#include "calculadora.h"

int main() {
    float num1, num2, resultado;
    int opcao;

    do {
        printf("\nCalculadora Simples\n");
        printf("1. Adicao\n");
        printf("2. Subtracao\n");
        printf("3. Multiplicacao\n");
        printf("4. Divisao\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 0) {
            printf("Saindo...\n");
            break;
        }

        printf("Digite o primeiro numero: ");
        scanf("%f", &num1);
        printf("Digite o segundo numero: ");
        scanf("%f", &num2);

        switch (opcao) {
            case 1:
                resultado = adicionar(num1, num2);
                printf("Resultado: %.2f\n", resultado);
                break;
            case 2:
                resultado = subtrair(num1, num2);
                printf("Resultado: %.2f\n", resultado);
                break;
            case 3:
                resultado = multiplicar(num1, num2);
                printf("Resultado: %.2f\n", resultado);
                break;
            case 4:
                resultado = dividir(num1, num2);
                if (num2 != 0) {
                    printf("Resultado: %.2f\n", resultado);
                }
                break;
            default:
                printf("Opção invlida\n");
        }
    } while (opcao != 0);

    return 0;
}
