#include <stdio.h>

typedef struct{
    char nome[30];
    char curso[20];
    int notas[4];
}Aluno;

int main(){
    Aluno aluno;
    float media;
    int i, soma = 0;

    printf("Digite o nome do aluno:\n");
    fgets(aluno.nome, 29, stdin);
    aluno.nome[strcspn(aluno.nome, "\n")] = 0;
    printf("Digite o curso do aluno:\n");
    fgets(aluno.curso, 19, stdin);
    aluno.curso[strcspn(aluno.curso, "\n")] = 0;
    for(i = 0; i < 4; i++){
        printf("Digite a nota %d do aluno: ", i+1);
        scanf("%d", &aluno.notas[i]);
        soma += aluno.notas[i];
    }
    media = (float)soma/4;

    printf("Media: %.2f\n", media);
    if((int)media >= 7)
        printf("Aprovado\n");
    else if((int)media < 3)
        printf("Reprovado\n");
    else
        printf("Exame\n");

    return 0;
}