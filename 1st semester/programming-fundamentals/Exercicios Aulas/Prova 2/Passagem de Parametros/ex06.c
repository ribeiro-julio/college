#include <stdio.h>

void preencheMatriz(int matriz[5][5]){
    int i, j;
    for(i = 0; i < 5; i++)
        for(j = 0; j < 5; j++)
            scanf("%d", &matriz[i][j]);
}

void imprimeMatriz(int matriz[5][5]){
    int i, j;
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
}

int somaMatriz(int matriz[5][5]){
    int soma = 0;
    int i, j;
    for(i = 0; i < 5; i++)
        for(j = 0; j < 5; j++)
            soma += matriz[i][j];
    return soma;
}

int main(){
    int matriz[5][5];
    preencheMatriz(matriz);
    imprimeMatriz(matriz);
    printf("Soma = %d", somaMatriz(matriz));
    return 0;
}