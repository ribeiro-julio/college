#include <stdio.h>

int main(){
    int matriz[3][5], princ = 0, sec = 0;
    int i, j;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("Digite [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            if(j < 2)
                matriz[i][j+3] = matriz[i][j];
        }
    }

    for(j = 0; j < 3; j++){
        princ += (matriz[0][j] * matriz[1][j+1] * matriz[2][j+2]);
        sec += (matriz[2][j] * matriz[1][j+1] * matriz[0][j+2]);
    }

    printf("Matriz:\n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
    printf("Matriz de Sarrus:\n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 5; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
    printf("Determinante da matriz e: %d", princ-sec);

    return 0;
}