#include <stdio.h>
#define LINHA 5
#define COLUNA 5

int main(){
    int matriz[LINHA][COLUNA], iMaior, maior, jMenor, minimax;
    int i, j;

    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++){
            printf("Digite [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            if(i == 0 && j == 0){
                maior = matriz[i][j];
                iMaior = i;
            }
            else{
                if(matriz[i][j] > maior){
                    maior = matriz[i][j];
                    iMaior = i;
                }
            }       
        }
    }

    minimax = maior;
    for(j = 0; j < COLUNA; j++){
        if(matriz[iMaior][j] < minimax){
            minimax = matriz[iMaior][j];
            jMenor = j;
        }
    }
    
    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
    printf("Valor minimax: %d; Indice deste valor: [%d][%d]\n", minimax, iMaior, jMenor);
    
    return 0;
}