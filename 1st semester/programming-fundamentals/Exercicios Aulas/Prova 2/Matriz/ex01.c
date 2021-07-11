#include <stdio.h>
#define LINHA 5
#define COLUNA 5

int main(){
    int matriz[LINHA][COLUNA];
    int i, j;

    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++){
            if(i == j)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }

    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
    
    return 0;
}