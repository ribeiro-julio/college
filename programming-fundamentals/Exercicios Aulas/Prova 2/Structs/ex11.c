#include <stdio.h>
#include <stdio.h>

typedef struct{
    char nome[30], estilo[30];
    int integrantes, ranking;
}Banda;

Banda bandas[5];

void preencherBandas(){
    int i;
    printf("--------------------------\n");
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
        printf("--------------------------\n");
    }
}

void pesquisaRanking(){
    int ranking, i;
    printf("--------------------------\n");
    printf("Digite um numero de 1 ate 5: ");
    scanf("%d", &ranking);
    puts(bandas[ranking-1].nome);
    puts(bandas[ranking-1].estilo);
    printf("%d integrantes\n", bandas[ranking-1].integrantes);
    printf("--------------------------\n");
}

void pesquisaEstilo(){
    char estilo[30];
    int i, ocorrencias = 0;
    printf("--------------------------\n");
    printf("Digite um estilo musical: ");
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
            ocorrencias++;
        }
    }
    if(ocorrencias == 0)
        printf("Nao foram encontradas bandas desse estilo!\n");
    printf("--------------------------\n");
}

void pesquisaNome(){
    char banda[30];
    int i, encontrou;
    printf("--------------------------\n");
    printf("Digite o nome de uma banda: ");
    setbuf(stdin, NULL);
    fgets(banda, 29, stdin);
    banda[strcspn(banda, "\n")] = 0;
    for(i = 0; i < 5; i++){
        if(strcmp(bandas[i].nome, banda) == 0){
            printf("Banda encontrada!\n");
            printf("Posicao %d do ranking:\n", bandas[i].ranking);
            puts(bandas[i].nome);
            puts(bandas[i].estilo);
            printf("%d integrantes\n", bandas[i].integrantes);
            encontrou = 1;
        }
    }
    if(encontrou == 0)
        printf("Banda nao encontrada!");
    printf("--------------------------\n");
}

int main(){
    int opcao = 1;
    do{
        printf("Selecone uma opcao:\n");
        printf("1 -> Preencher bandas\n");
        printf("2 -> Procurar banda por ranking\n");
        printf("3 -> Procurar banda por tipo de musica\n");
        printf("4 -> Procurar banda por nome\n");
        printf("5 -> Sair\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1: 
                system("cls");
                preencherBandas();
                break;
            case 2: 
                system("cls");
                pesquisaRanking();
                break;
            case 3: 
                system("cls");
                pesquisaEstilo();
                break;
            case 4: 
                system("cls");
                pesquisaNome();
                break;
            case 5: exit(0); break;
            default: 
                system("cls");
                printf("Opcao invalida\n");
                break;
        }
    } while(1);

    return 0;
}