// Julio Cesar Garcia Ribeiro - RA: 1994484

#include <stdio.h>

int main(int argc, int *argv[]) {
    int a;

    printf("Entre com o valor: ");
    scanf("%d", &a);

    a % 2 == 0 ? printf("Numero par\n") : printf("Numero impar\n");
}