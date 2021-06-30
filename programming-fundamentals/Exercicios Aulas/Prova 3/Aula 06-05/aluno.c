#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

void cadastrar_alunos(Aluno *alunos){
    for(int i = 0; i < 4; i++){
        printf("Nome do aluno %d: ", i+1);
        setbuf(stdin, NULL);
        fgets(alunos[i].nome, 29, stdin);
        alunos[i].nome[strcspn(alunos[i].nome,"\n")]='\0';

        printf("Idade do aluno %d: ", i+1);
        scanf("%d", &alunos[i].idade);
        printf("-------------------------\n");
    }
}

void mostrar_aluno(Aluno *alunos, int i){
    printf("Aluno %d:\n", i);
    printf("Nome: %s; Idade: %d\n", alunos[i].nome, alunos[i].idade);
}

void mostrar_alunos(Aluno *alunos){
    printf("Alunos cadastrados:\n");
    for(int i = 0 ; i < 4; i++){
        printf("Nome: %s; Idade: %d\n", alunos[i].nome, alunos[i].idade);
        printf("-------------------------\n");
    }
}

void alterar_aluno(Aluno *alunos, int i){
    printf("Novo nome do aluno %d: ", i+1);
    setbuf(stdin, NULL);
    fgets(alunos[i].nome, 29, stdin);
    alunos[i].nome[strcspn(alunos[i].nome,"\n")]='\0';

    printf("Nova idade do aluno %d: ", i+1);
    scanf("%d", &alunos[i].idade);
    printf("-------------------------\n");
}

void salvar_alunos(Aluno *alunos){
    FILE *file = fopen("alunos.dat","wb");
    if(file == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    fwrite(alunos, sizeof(Aluno), 4, file);
    fclose(file);
}

void ler_alunos(Aluno *alunos){
    FILE *file = fopen("alunos.dat","rb");
    if(file == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    fread(alunos, sizeof(Aluno), 4, file);
    fclose(file);
}