#include <stdio.h>

int exponentiation(int base, int exponent){
    if(exponent == 1)
        return base;
    return base * exponentiation(base, exponent-1);
}

int main(){
    int base, exponent;

    printf("Base: ");
    scanf("%d", &base);
    printf("Expoente: ");
    scanf("%d", &exponent);

    printf("Resultado: %d\n", exponentiation(base, exponent));

    return 0;
}