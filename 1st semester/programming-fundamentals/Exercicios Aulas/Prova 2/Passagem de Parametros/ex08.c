#include <stdio.h>

void maior_menor(int vetor[10], int* maior, int* menor){
    int i;
    for(i = 0; i < 10; i++){
        if(i == 0){
            *maior = vetor[i];
            *menor = vetor[i];
        }
        else{
            if(vetor[i] > *maior)
                *maior = vetor[i];
            else if(vetor[i] < *menor)
                *menor = vetor[i];
        }
    }
}

int main(){
    int vetor[10], maior, menor;
    int i;
    for(i = 0; i < 10; i++)
        scanf("%d", &vetor[i]);
    maior_menor(vetor, &maior, &menor);
    printf("Maior: %d; Menor = %d", maior, menor);
    return 0;
}