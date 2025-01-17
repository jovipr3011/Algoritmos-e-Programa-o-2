#include <stdio.h>

int main() {
    FILE *arquivo = fopen("saida.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    fprintf(arquivo, "Linha 4\n");
    fprintf(arquivo, "Linha 5\n");

    fclose(arquivo);
    return 0;
}
