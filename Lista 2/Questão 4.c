#include <stdio.h>

#define MAX_QUARTOS 10

typedef struct {
    int numero;
    int disponivel;
} Quarto;

void inicializar_quartos(Quarto quartos[], int num_quartos) {
    for (int i = 0; i < num_quartos; i++) {
        quartos[i].numero = i + 1;
        quartos[i].disponivel = 1;
    }
}

int verificar_disponibilidade(Quarto quartos[], int num_quartos, int numero_quarto) {
    for (int i = 0; i < num_quartos; i++) {
        if (quartos[i].numero == numero_quarto) {
            return quartos[i].disponivel;
        }
    }
    return -1;
}

void fazer_reserva(Quarto quartos[], int num_quartos, int numero_quarto) {
    int disponibilidade = verificar_disponibilidade(quartos, num_quartos, numero_quarto);
    if (disponibilidade == 1) {
        for (int i = 0; i < num_quartos; i++) {
            if (quartos[i].numero == numero_quarto) {
                quartos[i].disponivel = 0;
                printf("Reserva confirmada para o quarto %d\n", numero_quarto);
                return;
            }
        }
    }
    printf("Quarto não disponivel ou nao encontrado.\n");
}

void listar_quartos_disponiveis(Quarto quartos[], int num_quartos) {
    for (int i = 0; i < num_quartos; i++) {
        if (quartos[i].disponivel == 1) {
            printf("Quarto %d\n", quartos[i].numero);
        }
    }
}

int main() {
    Quarto quartos[MAX_QUARTOS];
    int num_quartos = MAX_QUARTOS;
    int opcao, numero_quarto;

    inicializar_quartos(quartos, num_quartos);

    while (1) {
        printf("1. Verificar disponibilidade\n2. Fazer reserva\n3. Listar quartos disponiveis\n4. Sair\n");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Numero do quarto: ");
            scanf("%d", &numero_quarto);
            if (verificar_disponibilidade(quartos, num_quartos, numero_quarto) == 1) {
                printf("Quarto disponivel\n");
            } else {
                printf("Quarto nao disponivel\n");
            }
        } else if (opcao == 2) {
            printf("Numero do quarto: ");
            scanf("%d", &numero_quarto);
            fazer_reserva(quartos, num_quartos, numero_quarto);
        } else if (opcao == 3) {
            listar_quartos_disponiveis(quartos, num_quartos);
        } else if (opcao == 4) {
            break;
        }
    }

    return 0;
}
