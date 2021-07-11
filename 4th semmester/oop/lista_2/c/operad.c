// Julio Cesar Garcia Ribeiro - RA: 1994484

#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Impressão de Resultado de Cálculos:\n");

    int a = 3, b = 2;

    int c = a+b;
    printf("O resultado da soma de A e B é: %d\n", c);
    c = a-b;
    printf("O resultado da subtração de A e B é: %d\n", c);
    c = a*b;
    printf("O resultado da multiplicacao de A e B é: %d\n", c);
    c = a/b;
    printf("O resultado da divisao de A e B é: %d\n", c);

    return 0;
}