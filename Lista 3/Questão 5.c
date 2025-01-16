#include <stdio.h>

int contarCaracteres(char *str) {
    int count = 0;
    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}

int main() {
    char string[100];
    printf("Digite uma string: ");
    scanf("%s", string);

    int tamanho = contarCaracteres(string);
    printf("A string possui %d caracteres\n", tamanho);
    return 0;
}
