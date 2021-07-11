// Julio Cesar Garcia Ribeiro - RA: 1994484

#include <stdio.h>

int main(int argc, char *argv[]) {
    int a = 0, b = 15;

    do {
        printf("O Valor de B dentro do DO é: %d\n", b);
        b--;
    } while(b >= a);

    return 0;
}