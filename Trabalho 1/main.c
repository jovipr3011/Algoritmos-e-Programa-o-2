#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVROS 100
#define MAX_USUARIOS 100

typedef struct {
    char titulo[50];
    char autor[50];
    int ano;
} Livro;

typedef struct {
    char nome[50];
    int idade;
} Usuario;

typedef struct {
    Livro livros[MAX_LIVROS];
    Usuario usuarios[MAX_USUARIOS];
    int totalLivros;
    int totalUsuarios;
} Biblioteca;

void inicializarBiblioteca(Biblioteca *b) {
    b->totalLivros = 0;
    b->totalUsuarios = 0;
}

void adicionarLivro(Biblioteca *b) {
    if (b->totalLivros < MAX_LIVROS) {
        printf("Digite o titulo do livro: ");
        scanf("%s", b->livros[b->totalLivros].titulo);
        printf("Digite o autor do livro: ");
        scanf("%s", b->livros[b->totalLivros].autor);
        printf("Digite o ano do livro: ");
        scanf("%d", &b->livros[b->totalLivros].ano);
        b->totalLivros++;
    } else {
        printf("Biblioteca cheia\n");
    }
}

void adicionarUsuario(Biblioteca *b) {
    if (b->totalUsuarios < MAX_USUARIOS) {
        printf("Digite o nome do usuario: ");
        scanf("%s", b->usuarios[b->totalUsuarios].nome);
        printf("Digite a idade do usuario: ");
        scanf("%d", &b->usuarios[b->totalUsuarios].idade);
        b->totalUsuarios++;
    } else {
        printf("Biblioteca cheia de usuarios\n");
    }
}

void listarLivros(Biblioteca *b) {
    for (int i = 0; i < b->totalLivros; i++) {
        printf("Livro %d: Titulo: %s, Autor: %s, Ano: %d\n",
               i + 1, b->livros[i].titulo, b->livros[i].autor, b->livros[i].ano);
    }
}

void listarUsuarios(Biblioteca *b) {
    for (int i = 0; i < b->totalUsuarios; i++) {
        printf("Usuario %d: Nome: %s, Idade: %d\n",
               i + 1, b->usuarios[i].nome, b->usuarios[i].idade);
    }
}

int buscarLivroRecursivo(Biblioteca *b, int indice, char titulo[]) {
    if (indice >= b->totalLivros) {
        return -1;
    }
    if (strcmp(b->livros[indice].titulo, titulo) == 0) {
        return indice;
    }
    return buscarLivroRecursivo(b, indice + 1, titulo);
}

void buscarLivro(Biblioteca *b) {
    char titulo[50];
    printf("Digite o titulo do livro para buscar: ");
    scanf("%s", titulo);
    int indice = buscarLivroRecursivo(b, 0, titulo);
    if (indice != -1) {
        printf("Livro encontrado: Titulo: %s, Autor: %s, Ano: %d\n",
               b->livros[indice].titulo, b->livros[indice].autor, b->livros[indice].ano);
    } else {
        printf("Livro nao encontrado\n");
    }
}

int main() {
    Biblioteca biblioteca;
    inicializarBiblioteca(&biblioteca);
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar Livro\n");
        printf("2. Adicionar Usuario\n");
        printf("3. Listar Livros\n");
        printf("4. Listar Usuarios\n");
        printf("5. Buscar Livro\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            adicionarLivro(&biblioteca);
            break;
        case 2:
            adicionarUsuario(&biblioteca);
            break;
        case 3:
            listarLivros(&biblioteca);
            break;
        case 4:
            listarUsuarios(&biblioteca);
            break;
        case 5:
            buscarLivro(&biblioteca);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida\n");
            return 0;
            break;

        }
    } while (opcao != 0);

    return 0;
}
