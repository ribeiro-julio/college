#include <stdio.h>

int main(){
    int a;
    int *b, **c, ***d;
    printf("A: ");
    scanf("%d", &a);
    b = &a;
    c = &b;
    d = &c;
    printf("Dobro: %d; Triplo: %d; Quadruplo: %d\n", *b+a, **c+*b+a, ***d+**c+*b+a);
    return 0;
}