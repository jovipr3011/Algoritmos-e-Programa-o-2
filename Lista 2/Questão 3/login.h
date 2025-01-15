#ifndef LOGIN_H
#define LOGIN_H

typedef struct {
    char usuario[50];
    char senha[50];
} Usuario;

void cadastrarUsuario(Usuario usuarios[], int *quantidade);
int autenticarUsuario(Usuario usuarios[], int quantidade);

#endif
