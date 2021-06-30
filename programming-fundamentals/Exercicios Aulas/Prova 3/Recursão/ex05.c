#include <stdio.h>

int recursiva(int a){   //Soma os valores positivos até a
    if(a <= 0)
        return 0;
    else
        return a + recursiva(a-1);
}

int naoRecursiva(int a){
    int soma = 0;
    for(int i = 1; i <= a; i++)
        soma += i;
    return soma;
}

int main(){
    int a;
    printf("A: ");
    scanf("%d", &a);
    printf("Recursiva = %d; Nao recursiva = %d", recursiva(a), naoRecursiva(a));
    return 0;
}