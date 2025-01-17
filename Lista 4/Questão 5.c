#include <stdio.h>

int main() {
    FILE *entrada = fopen("entrada.txt", "r");
    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada\n");
        return 1;
    }

    FILE *copia = fopen("copia.txt", "w");
    if (copia == NULL) {
        printf("Erro ao criar o arquivo de copia\n");
        fclose(entrada);
        return 1;
    }

    char c;
    while ((c = fgetc(entrada)) != EOF) {
        fputc(c, copia);
    }

    fclose(entrada);
    fclose(copia);
    return 0;
}
