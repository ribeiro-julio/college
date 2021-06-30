#include <stdio.h>

typedef struct {
    char nome[30];
    int idade;
}Aluno;

void cadastrar_alunos(Aluno *alunos);
void mostrar_aluno(Aluno *alunos, int i);
void mostrar_alunos(Aluno *alunos);
void alterar_aluno(Aluno *alunos, int i);
void salvar_alunos(Aluno *alunos);
void ler_alunos(Aluno *alunos);