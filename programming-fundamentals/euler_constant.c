#include <stdio.h>

double neperiano(int n){
    double neperiano = 1, fatorial = 1;
    int i, j;
    for(i = 1; i <= n; i++){
        for(j = i; j > 0; j--)
            fatorial *= j;
        neperiano += 1/fatorial;
        fatorial = 1;
    }
    return neperiano;
}

int main(){
    int n;
    do{
        printf("Digite n: ");
        scanf("%d", &n);
    } while(n < 1);
    printf("Com n = %d; e = %.10lf", n, neperiano(n));
    return 0;
}