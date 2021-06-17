#include <stdio.h>
#include <string.h>

typedef struct{
    char name[100];
    char genre[100];
    int n_members, rank;
}Band;

void fill_bands(Band bands[5]){
    printf("Preenchendo o ranking de bandas:\n");
    for(int i = 0; i < 5; i++){
        printf("Nome da banda #%d: ", i+1);
        setbuf(stdin, NULL);
        fgets(bands[i].name, 99, stdin);
        bands[i].name[strcspn(bands[i].name, "\n")] = 0;
        printf("Genero musical da banda #%d: ", i+1);
        setbuf(stdin, NULL);
        fgets(bands[i].genre, 99, stdin);
        bands[i].genre[strcspn(bands[i].genre, "\n")] = 0;
        printf("Quantidade de integrantes da banda #%d: ", i+1);
        scanf("%d", &bands[i].n_members);
        bands[i].rank = i+1;
        printf("--------------------------------------\n");
    }
}

void get_band(Band bands[5]){
    int rank;

    printf("Digite o rank que deseja pesquisar: ");
    scanf("%d", &rank);
    printf("--------------------------------------\n");
    printf("Banda #%d\n", bands[rank-1].rank);
    printf("Nome: %s\n", bands[rank-1].name);
    printf("Genero: %s\n", bands[rank-1].genre);
    printf("Quantidade de integrantes: %d\n", bands[rank-1].n_members);
}

int main(){
    Band bands[5];

    fill_bands(bands);

    for(int i = 0; i < 5; i++){
        printf("Banda #%d\n", bands[i].rank);
        printf("Nome: %s\n", bands[i].name);
        printf("Genero: %s\n", bands[i].genre);
        printf("Quantidade de integrantes: %d\n", bands[i].n_members);
        printf("--------------------------------------\n");
    }

    get_band(bands);

    return 0;
}