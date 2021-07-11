#include <stdio.h>
#define LINHA 5
#define COLUNA 5

int main(){
    int matriz[LINHA][COLUNA], iMaior, jMaior, maior;
    int i, j;
    
    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++){
            printf("Digite [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            if(i == 0 && j == 0){
                maior = matriz[i][j];
                iMaior = i;
                jMaior = j;
            }
            else{
                if(matriz[i][j] > maior){
                    maior = matriz[i][j];
                    iMaior = i;
                    jMaior = j;
                }
            }       
        }
    }

    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
    printf("Indice com maior valor: [%d][%d]\n", iMaior, jMaior);

    return 0;
}