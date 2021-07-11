#include <stdio.h>
#define LINHA 2
#define COLUNA 7

int main(){
    int matriz[LINHA][COLUNA], n, ocorrencias = 0;
    int i, j;
    
    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++){
            printf("Digite [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
    
    printf("Digite N: ");
    scanf("%d", &n);
    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++){
            if(matriz[i][j] == n){
                printf("Numero encontrado na posicao [%d][%d]\n", i, j);
                ocorrencias++;
            }
        }
    }

    if(ocorrencias == 0)
        printf("Elemento nao encontrado");

    return 0;
}