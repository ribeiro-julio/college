#include <stdio.h>

int somaArray(int tamanho, int array[]){
    if(tamanho == 0)
        return 0;
    return array[tamanho-1] + somaArray(tamanho-1, array);
}

int main(){
    int array[] = { 2, 6, 4, 8, 5, 4, 3, 5, 6, 8 };
    int tamanho = sizeof(array)/sizeof(int);
    printf("Soma = %d", somaArray(tamanho, array));
    return 0;
}