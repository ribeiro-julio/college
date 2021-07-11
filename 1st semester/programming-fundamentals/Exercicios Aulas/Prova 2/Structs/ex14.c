#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct{
    char naipe[8];
    char valor[3];
}Carta;

Carta baralho[52];

void preencherBaralho(int i, int j, int indice){
    switch(i){
        case 0: 
            strcpy(baralho[indice].naipe, "Ouro");
            switch(j){
                case 1: strcpy(baralho[indice].valor, "A"); break;
                case 11: strcpy(baralho[indice].valor, "J"); break;
                case 12: strcpy(baralho[indice].valor, "Q"); break;
                case 13: strcpy(baralho[indice].valor, "K"); break;
                default: itoa(j, baralho[indice].valor, 10); break;
            }
        break;
        case 1:
            strcpy(baralho[indice].naipe, "Espadas");
            switch(j){
                case 1: strcpy(baralho[indice].valor, "A"); break;
                case 11: strcpy(baralho[indice].valor, "J"); break;
                case 12: strcpy(baralho[indice].valor, "Q"); break;
                case 13: strcpy(baralho[indice].valor, "K"); break;
                default: itoa(j, baralho[indice].valor, 10); break;
            }
        break;
        case 2:
            strcpy(baralho[indice].naipe, "Copas");
            switch(j){
                case 1: strcpy(baralho[indice].valor, "A"); break;
                case 11: strcpy(baralho[indice].valor, "J"); break;
                case 12: strcpy(baralho[indice].valor, "Q"); break;
                case 13: strcpy(baralho[indice].valor, "K"); break;
                default: itoa(j, baralho[indice].valor, 10); break;
            }
        break;
        case 3:
            strcpy(baralho[indice].naipe, "Paus");
            switch(j){
                case 1: strcpy(baralho[indice].valor, "A"); break;
                case 11: strcpy(baralho[indice].valor, "J"); break;
                case 12: strcpy(baralho[indice].valor, "Q"); break;
                case 13: strcpy(baralho[indice].valor, "K"); break;
                default: itoa(j, baralho[indice].valor, 10); break;
            }
        break;
    }
}

int main(){
    Carta cartasP1[5], cartasP2[5];
    int i, j, indice = 0, pool[10];
    srand(time(NULL));

    for(i = 0; i < 4; i++){
        for(j = 1; j <= 13; j++){
            preencherBaralho(i, j, indice);
            indice++;
        }
    }

    for(i = 0; i < 10; i++){            //Nao deixa que dois valores aleatórios sejam iguais (apenas uma carta de cada no baralho)
        pool[i] = rand()%52;
        for(j = 0; j <= i-1; j++){
            while(pool[i] == pool[j])
                pool[i] = rand()%52;
        }
    }

    for(i = 0; i < 10; i++){            //Distribui as cartas para cada jogador
        if(i <= 4)
            cartasP1[i] = baralho[pool[i]];
        else
            cartasP2[i-5] = baralho[pool[i]];
    }

    printf("Cartas do jogador 1:\n");
    for(i = 0; i < 5; i++)
        printf("%s de %s\n", cartasP1[i].valor, cartasP1[i].naipe);
    printf("Cartas do jogador 2:\n");
    for(i = 0; i < 5; i++)
        printf("%s de %s\n", cartasP2[i].valor, cartasP2[i].naipe);

    return 0;
}