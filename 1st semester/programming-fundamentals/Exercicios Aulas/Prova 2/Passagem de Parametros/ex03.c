#include <stdio.h>

void preencherVetor(int vetor[10]){
    int i;
    for(i = 0; i < 9; i++)
        scanf("%d", &vetor[i]);
}

void alterarVetor(int vetor[], int a){
    int i;
    for(i = 9; i >= 0; i--){
        if(i != 0)
            vetor[i] = vetor[i-1];
        else
            vetor[i] = a;
    }
}

void imprimirVetor(int vetor[10]){
    int i;
    for(i = 0; i < 10; i++)
        printf("%d ", vetor[i]);
    printf("\n");
}

int main(){
    int vetor[10];
    int a;
    preencherVetor(vetor);
    printf("Vetor com lixo:\n");
    imprimirVetor(vetor);
    printf("A = ");
    scanf("%d", &a);
    alterarVetor(vetor, a);
    printf("Vetor alterado:\n");
    imprimirVetor(vetor);
    return 0;
}