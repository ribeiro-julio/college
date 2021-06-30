#include <stdio.h>

int calculaPotencia(int x, int y){
    if(y == 0)
        return 1;
    return x*calculaPotencia(x, y-1);
}

int main(){
    int x, y;
    printf("Base e expoente: ");
    scanf("%d %d", &x, &y);
    printf("Reultado: %d^%d = %d", x, y, calculaPotencia(x, y));
    return 0;
}