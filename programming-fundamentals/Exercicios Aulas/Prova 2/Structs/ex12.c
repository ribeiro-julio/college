#include <stdio.h>

typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    char descricao[60];
    Data data;
}Compromisso;

int main(){
    Compromisso compromissos[5];
    int i, mes, ocorrencias = 0;

    for(i = 0; i < 5; i++){
        printf("Digite a descricao do compromisso %d:\n", i+1);
        setbuf(stdin, NULL);
        fgets(compromissos[i].descricao, 29, stdin);
        compromissos[i].descricao[strcspn(compromissos[i].descricao, "\n")] = 0;
        printf("Digite o dia do compromisso %d: ", i+1);
        scanf("%d", &compromissos[i].data.dia);
        printf("Digite o mes do compromisso %d: ", i+1);
        scanf("%d", &compromissos[i].data.mes);
        printf("Digite o ano do compromisso %d: ", i+1);
        scanf("%d", &compromissos[i].data.ano);
        printf("------------------------------\n");
    }


    while(ocorrencias < 5){
        printf("Digite um mes para procurar compromissos: ");
        scanf("%d", &mes);

        for(i = 0; i< 5; i++){
            if(compromissos[i].data.mes == mes){
                puts(compromissos[i].descricao);
                printf("Data: %d/%d/%d\n", compromissos[i].data.dia, compromissos[i].data.mes, compromissos[i].data.ano);
                printf("------------------------------\n");
                ocorrencias++;
            }
        }
        if(ocorrencias == 0)
            printf("Nenhum compromisso para esse mes!\n");
    }

    return 0;
}