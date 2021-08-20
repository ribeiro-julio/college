// Julio Cesar Garcia Ribeiro - RA: 1994484

#include <stdio.h>

int main(int argc, char *argv[]) {
    int a = 0;
    int b = 10;

    for(b; b >= a; b--) {
        printf("O Valor de B dentro do FOR é: %d\n", b);
    }

    return 0;
}