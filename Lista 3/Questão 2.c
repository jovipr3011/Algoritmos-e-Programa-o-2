#include <stdio.h>

int somaArray(int *array, int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += *(array + i);
    }
    return soma;
}

int main() {
    int numeros[] = {1, 2, 3, 4, 5};
    int tamanho = 5;
    int soma = somaArray(numeros, tamanho);
    printf("A soma dos elementos do array e: %d\n", soma);
    return 0;
}
