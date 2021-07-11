#include <stdio.h>
#define LINHA 6
#define COLUNA 6

int main(){
    int matriz[LINHA][COLUNA], n, ocorrencias = 0;
    int i, j;
    
    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++){
            printf("Digite [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("Digite N: ");
    scanf("%d", &n);

    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
    
    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++){
            if(matriz[i][j] > n){
                ocorrencias++;
            }
        }
    }

    if(ocorrencias == 0)
        printf("Nenhum valor maior que %d!", n);
    else
        printf("Foram encontrados %d valores maiores que %d", ocorrencias, n);

    return 0;
}