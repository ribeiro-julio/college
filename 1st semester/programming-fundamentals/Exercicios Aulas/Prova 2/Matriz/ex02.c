#include <stdio.h>
#define LINHA 3
#define COLUNA 3

int main(){
    int matriz[LINHA][COLUNA], somaPrincipal = 0, somaSecundaria = 0;
    int i, j;
    
    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++){
            printf("Digite [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            if(i == j)
                somaPrincipal += matriz[i][j];
            if(i+j == COLUNA-1)
                somaSecundaria += matriz[i][j];
        }
    }

    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
    printf("Soma Principal = %d\n", somaPrincipal);
    printf("Soma Secundaria = %d\n", somaSecundaria);

    return 0;
}