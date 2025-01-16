#include <stdio.h>

typedef struct {
    int x;
    int y;
} Ponto;

void atualizarPonto(Ponto *p, int novoX, int novoY) {
    p->x = novoX;
    p->y = novoY;
}

int main() {
    Ponto ponto = {0, 0};
    printf("Ponto inicial: x = %d, y = %d\n", ponto.x, ponto.y);

    atualizarPonto(&ponto, 5, 10);
    printf("Ponto atualizado: x = %d, y = %d\n", ponto.x, ponto.y);
    return 0;
}
