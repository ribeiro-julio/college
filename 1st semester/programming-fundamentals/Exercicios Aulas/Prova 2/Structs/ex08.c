#include <stdio.h>

typedef struct{
    char nome[30], estilo[30];
    int integrantes, ranking;
}Banda;

int main(){
    Banda bandas[5];
    int i, ranking;

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
    
    printf("Digite um numero de 1 ate 5: ");
    scanf("%d", &ranking);
    puts(bandas[ranking-1].nome);
    puts(bandas[ranking-1].estilo);
    printf("%d integrantes\n", bandas[ranking-1].integrantes);

    return 0;
}