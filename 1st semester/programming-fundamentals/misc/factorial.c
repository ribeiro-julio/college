#include <stdio.h>

int fatorial(int n){
    int i, fatorial = 1;
    for(i = n; i > 0; i--)
        fatorial *= i;
    return fatorial;
}

int main(){
    int n;
    printf("Digite n: ");
    scanf("%d", &n);
    printf("%d! e: %d", n, fatorial(n));
    return 0;
}