#ifndef ALUNOS_H
#define ALUNOS_H

typedef struct {
    char nome[50];
    float notas[3];
    float media;
} Aluno;

void adicionarAluno(Aluno alunos[], int *quantidade);
void listarAlunos(Aluno alunos[], int quantidade);

#endif
