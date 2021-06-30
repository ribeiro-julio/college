#include <stdio.h>

#define N 10

void bubbleSort(int vetor[N]){
    int aux;
    int i, j;
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            if (vetor[i] < vetor[j]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

void preencherVetor(int vetor[N]){
    int i;
    for(i = 0; i < N; i++)
        scanf("%d", &vetor[i]);
}

void imprimirVetor(int vetor[N]){
    int i;
    for(i = 0; i < N; i++)
        printf("%d ", vetor[i]);
    printf("\n");
}

int main(){
    int vetor[N];
    preencherVetor(vetor);
    printf("Vetor original:\n");
    imprimirVetor(vetor);
    bubbleSort(vetor);
    printf("Vetor ordenado:\n");
    imprimirVetor(vetor);
    return 0;
}