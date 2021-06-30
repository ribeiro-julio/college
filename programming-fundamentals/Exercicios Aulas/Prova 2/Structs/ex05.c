#include <stdio.h>

typedef struct{
    char nome[30];
    char matricula[10];
    int notas[4];
    float media;
}Aluno;

int main(){
    Aluno aluno[5];
    int i, j, soma = 0, maiorP1, iMaiorP1, iMaiorMedia, iMenorMedia;
    float maiorMedia, menorMedia;

    for(i = 0; i < 5; i++){
        printf("Digite o nome do aluno:\n");
        setbuf(stdin, NULL);
        fgets(aluno[i].nome, 29, stdin);
        aluno[i].nome[strcspn(aluno[i].nome, "\n")] = 0;
        printf("Digite a matricula do aluno:\n");
        setbuf(stdin, NULL);
        fgets(aluno[i].matricula, 9, stdin);
        aluno[i].matricula[strcspn(aluno[i].matricula, "\n")] = 0;
        for(j = 0; j < 4; j++){
            printf("Digite a nota %d do aluno %d: ", j+1, i+1);
            scanf("%d", &aluno[i].notas[j]);
            soma += aluno[i].notas[j];
            if(j == 0 && i == 0){
                maiorP1 = aluno[i].notas[j];
                iMaiorP1 = i;
            }
            else if(j == 0){
                if(aluno[i].notas[j] >= maiorP1){
                    maiorP1 = aluno[i].notas[j];
                    iMaiorP1 = i;
                }
            }
        }
        aluno[i].media = (float)soma/4;
        printf("Media do aluno %d: %.2f\n", i+1, aluno[i].media);
        if(i == 0){
            maiorMedia = aluno[i].media;
            menorMedia = aluno[i].media;
            iMaiorMedia = i;
            iMenorMedia = i;
        }
        else{
            if(aluno[i].media >= maiorMedia){
                maiorMedia = aluno[i].media;
                iMaiorMedia = i;
            }
            if(aluno[i].media <= menorMedia){
                menorMedia = aluno[i].media;
                iMenorMedia = i;
            }
        }
        if((int)aluno[i].media >= 6)
            printf("Aprovado\n");
        else if((int)aluno[i].media < 2)
            printf("Reprovado\n");
        else
            printf("Exame\n");
        soma = 0;
    }
    printf("Maior nota na P1: %s - Nota: %d\n", aluno[iMaiorP1].nome, maiorP1);
    printf("Maior media: %s - Media: %.2f\n", aluno[iMaiorMedia].nome, aluno[iMaiorMedia].media);
    printf("Menor media: %s - Media: %.2f\n", aluno[iMenorMedia].nome, aluno[iMenorMedia].media);
    return 0;
}