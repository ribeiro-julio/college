// Julio Cesar Garcia Ribeiro - RA: 1994484

#include <stdio.h>

int main(int argc, char *argv[]) {
    int tamanhoi = 3;
    int tamanhoj = 3;
    int matriz[tamanhoi][tamanhoj];

    printf("Entre com os valores:\n");
    for(int i = 0; i < tamanhoi; i++) {
        for(int j = 0; j < tamanhoj; j++) {
            printf("matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("--------------------------\n");

    for(int i = tamanhoi-1; i >= 0; i--) {
        for(int j = tamanhoj-1; j >= 0; j--)
            printf("matriz[%d][%d]: %d\n", i, j, matriz[i][j]);
    }
    
    return 0;
}