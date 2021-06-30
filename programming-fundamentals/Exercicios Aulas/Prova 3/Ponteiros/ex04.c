#include <stdio.h>

int main(){
    int numeros[5];
    for(int i = 0; i < 5; i++){
        printf("[%d]: ", i);
        scanf("%d", &*(numeros+i));
    }
    for(int i = 0; i < 5; i++){
        if(*(numeros+i) % 2 == 0)
            printf("Indice: %d; Valor: %d; Endereco: %p\n", i, *(numeros+i), numeros+i);
    }
    return 0;
}