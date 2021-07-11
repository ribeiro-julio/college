#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

int main(){
    Aluno alunos[4];
    int opcao = 0, i;

    while(opcao >= 0 || opcao <= 6){
        printf("Selecione uma opcao:\n");
        printf("1 - Cadastrar alunos\n");
        printf("2 - Mostrar alunos\n");
        printf("3 - Mostrar aluno\n");
        printf("4 - Alterar aluno\n");
        printf("5 - Salvar alunos\n");
        printf("6 - Ler alunos\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao){
            case 1: cadastrar_alunos(alunos); break;
            case 2: mostrar_alunos(alunos); break;
            case 3: 
                printf("Digite o indice para mostrar: ");
                scanf("%d", &i);
                mostrar_aluno(alunos, i);
            break;
            case 4: 
                printf("Digite o indice para alterar: ");
                scanf("%d", &i);
                alterar_aluno(alunos, i);
            break;
            case 5: salvar_alunos(alunos); break;
            case 6: ler_alunos(alunos); break;
            case 0: exit(0); break;
            default: printf("Opcao invalida!"); break;
        }
    }
}