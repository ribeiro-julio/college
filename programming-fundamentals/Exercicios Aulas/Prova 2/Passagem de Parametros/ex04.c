#include <stdio.h>

int preencherVetorA(int vetorA[5]){
    int i, maior;
    for(i = 0; i < 5; i++){
        scanf("%d", &vetorA[i]);
        if(i == 0)
            maior = vetorA[i];
        else{
            if(vetorA[i] > maior)
                maior = vetorA[i];
        }
    }
    return maior;
}

void preencherVetorB(int vetorA[5], float vetorB[5], int maior){
    int i;
    for(i = 0; i < 5; i++){
        vetorB[i] = ((float)vetorA[i]/(float)maior);
    }
}

void imprimirVetorA(int vetorA[5]){
    int i;
    for(i = 0; i < 5; i++)
        printf("%d ", vetorA[i]);
    printf("\n");
}

void imprimirVetorB(float vetorB[5]){
    int i;
    for(i = 0; i < 5; i++)
        printf("%.2f ", vetorB[i]);
    printf("\n");
}

int main(){
    int vetorA[5];
    float vetorB[5];
    int maior;
    maior = preencherVetorA(vetorA);
    printf("Vetor A:\n");
    imprimirVetorA(vetorA);
    preencherVetorB(vetorA, vetorB, maior);
    printf("Vetor B:\n");
    imprimirVetorB(vetorB);
    return 0;
}