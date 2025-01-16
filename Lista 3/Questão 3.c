#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array, tamanho;

    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    array = (int *)malloc(tamanho * sizeof(int));
    if (array == NULL) {
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    for (int i = 0; i < tamanho; i++) {
        printf("Digite o valor para o elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Valores inseridos no array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}
