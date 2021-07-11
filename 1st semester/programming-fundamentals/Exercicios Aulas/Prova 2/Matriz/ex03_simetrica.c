#include <stdio.h>
#define LINHA 3
#define COLUNA 3

int main(){
    int matriz[LINHA][COLUNA], transposta[LINHA][COLUNA], diferente = 0;
    int i, j;

    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++){
            printf("Digite [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            transposta[j][i] = matriz[i][j];
        }
    }

    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++){
            if(matriz[i][j] != transposta[i][j]){       //Matriz é simétrica quando é igual a sua transposta
                diferente++;
                break;
            }
        }
    }

    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
    if(diferente == 0)
        printf("Matriz Simetrica\n");
    else
        printf("Matriz Assimetrica\n");

    return 0;
}