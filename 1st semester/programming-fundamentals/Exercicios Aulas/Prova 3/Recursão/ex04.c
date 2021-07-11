#include <stdio.h>
#include <string.h>

void converter(char bin[], int num){
    if(num == 0)
        return;
    if(num%2 == 1){
        strcat(bin, "1");
        converter(bin, num/2);
    }
    else{
        strcat(bin, "0");
        converter(bin, num/2);
    }
}

void inverter(int esq, int dir, char bin[]){
    int aux;
    if(esq >= dir)
        return;
    aux = bin[esq];
    bin[esq] = bin[dir];
    bin[dir] = aux;
    inverter(esq+1, dir-1, bin);
}

int main(){
    char bin[20] = "";
    int num;
    printf("Digite o decimal: ");
    scanf("%d", &num);
    converter(bin, num);
    int n = strlen(bin) - 1;
    inverter(0, n, bin);
    printf("Decimal: %d; Binario: %s", num, bin);
    return 0;
}