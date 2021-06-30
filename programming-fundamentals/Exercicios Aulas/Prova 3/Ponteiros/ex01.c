#include <stdio.h>

int main(){
    int a = 5, b = 3;
    printf("Endereco de A: %d\n", &a);
    printf("Endereco de B: %d\n", &b);
    if(&a > &b)
        printf("Maior endereco e o de A: %p, valor %d\n", &a, a);
    else
        printf("Maior endereco e o de B: %p, valor %d\n", &b, b);
    return 0;
}