#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LINHA 15
#define COLUNA 15
#define TAM 15

int main(){
    char sequencias[LINHA][COLUNA], alfabeto[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", maiorSequencia[TAM] = "0";
    int maior, count = 0;
    int i, j, k;
    srand(time(NULL));

    for(i = 0; i < LINHA; i++)
        for(j = 0; j < COLUNA; j++)
            sequencias[i][j] = alfabeto[rand()%26];

    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++)
            printf("%c", sequencias[i][j]);
        printf("\n");
    }

    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA-1; j++){
            if(j == 0 && i == 0)
                maior = count;
            if(sequencias[i][j+1] == sequencias[i][j]+1)
                count++;
            else{
                if(count >= maior){
                    maior = count;
                    for(k = 0; k < maior; k++)
                        maiorSequencia[k] = sequencias[j][i-(k+1)];
                }
                count = 0;
            }
        }
    }
    for(j = 0; j < COLUNA; j++){
        for(i = 0; i < LINHA-1; i++){
            if(sequencias[i+1][j] == sequencias[i][j]+1)
                count++;
            else{
                if(count >= maior){
                    maior = count;
                    for(k = 0; k < maior; k++)
                        maiorSequencia[k] = sequencias[j][i-(k+1)];
                }
                count = 0;
            }
        }
    }

    printf("A maior sequencia e %s", maiorSequencia);

    return 0;
}