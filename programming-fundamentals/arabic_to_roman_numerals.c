#include <stdio.h>

int main(){
    char romanos[13][3] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
    int arabicos[13] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
    int numero, i, count, j;

    printf("Digite o numero: ");
    scanf("%d", &numero);

    while(numero > 0){
        for(i = 12; i >= 0; i--){
            if(numero >= arabicos[i]){
                count = numero/arabicos[i];
                numero -= count*arabicos[i];
                for(j = 0; j < count; j++){
                    printf("%s", romanos[i]);
                }
                count = 0;
            }
        }
    }
}