// Julio Cesar Garcia Ribeiro - RA: 1994484

#include <stdio.h>

int main(int argc, char *argv[]) {
    int tamanho = 5;
    int vetor[tamanho];

    printf("Entre com os valores:\n");
    for(int i = 0; i < tamanho; i++) {
        printf("vetor[%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    printf("--------------------------\n");

    for(int i = tamanho-1; i >= 0; i--)
        printf("vetor[%d]: %d\n", i, vetor[i]);
    
    return 0;
}