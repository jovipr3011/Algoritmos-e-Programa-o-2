#include <stdio.h>

int main() {
    FILE *arquivo = fopen("saida.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo\n");
        return 1;
    }

    fprintf(arquivo, "Linha 1\n");
    fprintf(arquivo, "Linha 2\n");
    fprintf(arquivo, "Linha 3\n");

    fclose(arquivo);
    return 0;
}
