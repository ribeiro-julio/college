#include <stdio.h>
#define LINHA 5
#define COLUNA 5

int main(){
    int matriz[LINHA][COLUNA], somaLinha4 = 0, somaColuna2 = 0, somaPrinc = 0, somaSec = 0, somaTudo = 0;
    int i, j;
    
    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++){
            printf("Digite [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            if(i == 3)
                somaLinha4 += matriz[i][j];
            if(j == 1)
                somaColuna2 += matriz[i][j];
            if(i == j)
                somaPrinc += matriz[i][j];
            if(i+j == COLUNA-1)
                somaSec += matriz[i][j];
            somaTudo += matriz[i][j]; 
        }
    }

    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
    printf("Soma dos elementos da linha 4 = %d\n", somaLinha4);
    printf("Soma dos elementos da coluna 2 = %d\n", somaColuna2);
    printf("Soma diagonal principal = %d\n", somaPrinc);
    printf("Soma diagonal secundaria = %d\n", somaSec);
    printf("Soma dos elementos da matriz = %d\n", somaTudo);

    return 0;
}