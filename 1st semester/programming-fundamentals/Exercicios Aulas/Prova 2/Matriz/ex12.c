#include <stdio.h>
#define LINHA 5
#define COLUNA 5

int main(){
    int matriz[LINHA][COLUNA], matrizTrocada[LINHA][COLUNA];
    int i, j;
    
    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++){
            printf("Digite [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Matriz original:\n");
    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }

    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++){
            if(i == 0)
                matrizTrocada[i][j] = matriz[2][j];
            else if(i == 2)
                matrizTrocada[i][j] = matriz[0][j];
            else
                matrizTrocada[i][j] = matriz[i][j];
        }
    }

    printf("Matriz trocada:\n");
    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++)
            printf("%d ", matrizTrocada[i][j]);
        printf("\n");
    }

    return 0;
}