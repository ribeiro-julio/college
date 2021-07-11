// Julio Cesar Garcia Ribeiro - RA: 1994484

#include <stdio.h>

int main(int argc, char *argv[]) {
    int a = 0, b = 15;

    while(b >= a){
        printf("O Valor de B dentro do while é: %d\n", b);
        b--;
    }

    return 0;
}