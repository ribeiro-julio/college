#include <stdio.h>
#define LINHA 5
#define COLUNA 5

int main(){
    int matriz[LINHA][COLUNA], maior, menor, count = 0;
    int i, j, k;
    
    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++){
            printf("Digite [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            if(i == 0 && j == 0){
                maior = matriz[i][j];
                menor = matriz[i][j];
            }
            else{
                if(matriz[i][j] > maior)
                    maior = matriz[i][j];
                else if(matriz[i][j] < menor)
                    menor = matriz[i][j];
            }
        }
    }

    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }

    for(k = menor; k <= maior; k++){
        for(i = 0; i < LINHA; i++){
            for(j = 0; j < COLUNA; j++){
                if(k == matriz[i][j])
                    count++;
            }
        }
        if(count > 0){
            printf("%d aparece %d vez(es)\n", k, count);
            count = 0;
        }
    }
    
    return 0;
}