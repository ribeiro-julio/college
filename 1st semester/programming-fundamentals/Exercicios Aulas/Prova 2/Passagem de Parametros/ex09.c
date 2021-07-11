#include <stdio.h>

typedef struct{
    char nome[30];
}Disciplina;

typedef struct{
    char nome[30];
    char matricula[10];
    Disciplina disciplina;
    float notas[3];
    float media;
}Aluno;

int preencherAlunos(Aluno alunos[]){
    int i, j, iMaiorMedia;
    float soma = 0.0, maiorMedia;
    for(i = 0; i < 5; i++){
        printf("Forneca o nome do aluno %d..: ", i+1);
        setbuf(stdin, NULL);
        fgets(alunos[i].nome, 29, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

        printf("Forneca a matricula do aluno %d..: ", i+1);
        setbuf(stdin, NULL);
        fgets(alunos[i].matricula, 9, stdin);
        alunos[i].matricula[strcspn(alunos[i].matricula, "\n")] = '\0';

        printf("Forneca o nome da disciplina do aluno %d..: ", i+1);
        setbuf(stdin, NULL);
        fgets(alunos[i].disciplina.nome, 30, stdin);
        alunos[i].disciplina.nome[strcspn(alunos[i].disciplina.nome, "\n")] = '\0';

        for(j = 0; j < 3; j++){
            printf("Digite a nota %d do aluno %d: ", j+1, i+1);
            scanf("%f", &alunos[i].notas[j]);
            soma += alunos[i].notas[j];
        }

        alunos[i].media = soma/3.0;

        printf("Media do aluno: %.2f\n", alunos[i].media);

        if(i == 0){
            maiorMedia = alunos[i].media;
            iMaiorMedia = i;
        }
        else{
            if(alunos[i].media > maiorMedia){
                maiorMedia = alunos[i].media;
                iMaiorMedia = i;
            }
        }

        printf("-------------------------\n");

        soma = 0;
    }

    return iMaiorMedia;
}

int indiceMaiorMedia(Aluno alunos){
    int indice;

    return indice;
}

int main(){
    Aluno alunos[5];
    int maiorMedia = preencherAlunos(alunos);
    printf("Aluno com maior media:\n");
    puts(alunos[maiorMedia].nome);
    printf("RA: %s\n", alunos[maiorMedia].matricula);
    printf("Disciplina: %s\n", alunos[maiorMedia].disciplina.nome);
    printf("Media: %.2f\n", alunos[maiorMedia].media);
    return 0;
}