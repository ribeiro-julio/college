#include <stdio.h>

typedef struct{
    char nome[30], matricula[20], curso[20];
}Aluno;

int main(){
    Aluno aluno[5];

    int i;
    for(i = 0; i < 5; i++){
        printf("Forneca o nome do aluno %d..: ", i+1);
        setbuf(stdin, NULL);
        fgets(aluno[i].nome, 29, stdin);
        aluno[i].nome[strcspn(aluno[i].nome, "\n")] = '\0';

        printf("Forneca a matricula do aluno %d..: ", i+1);
        setbuf(stdin, NULL);
        fgets(aluno[i].matricula, 9, stdin);
        aluno[i].matricula[strcspn(aluno[i].matricula, "\n")] = '\0';

        printf("Forneca o curso do aluno %d..: ", i+1);
        fgets(aluno[i].curso, 9, stdin);
        aluno[i].curso[strcspn(aluno[i].curso, "\n")] = '\0';
    }
    
    for(i = 0; i < 5; i++){
        printf("--------------------\n");
        puts(aluno[i].nome);
        puts(aluno[i].matricula);
        puts(aluno[i].curso);
    }

    return 0;
}