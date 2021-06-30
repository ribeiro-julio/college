#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[30], estilo[30];
    int integrantes, ranking;
}Banda;

int main(){
    Banda bandas[5];
    char estilo[30];
    int i;

    for(i = 0; i < 5; i++){
        printf("Digite o nome da banda n. %d do ranking:\n", i+1);
        setbuf(stdin, NULL);
        fgets(bandas[i].nome, 29, stdin);
        bandas[i].nome[strcspn(bandas[i].nome, "\n")] = 0;
        printf("Digite o estilo da banda:\n");
        setbuf(stdin, NULL);
        fgets(bandas[i].estilo, 29, stdin);
        bandas[i].estilo[strcspn(bandas[i].estilo, "\n")] = 0;
        printf("Digite a quantidade de integrantes da banda: ");
        setbuf(stdin, NULL);
        scanf("%d", &bandas[i].integrantes);
        bandas[i].ranking = i+1;
    }
    
    printf("Digite um estilo musical:");
    setbuf(stdin, NULL);
    fgets(estilo, 29, stdin);
    estilo[strcspn(estilo, "\n")] = 0;

    for(i = 0; i < 5; i++){
        if(strcmp(bandas[i].estilo, estilo) == 0){
            printf("----------------------\n");
            printf("Posicao %d do ranking:\n", bandas[i].ranking);
            puts(bandas[i].nome);
            puts(bandas[i].estilo);
            printf("%d integrantes\n", bandas[i].integrantes);
        }
    }
    
    return 0;
}