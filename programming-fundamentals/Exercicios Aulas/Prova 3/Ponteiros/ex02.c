#include <stdio.h>

int main(){
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    for(int i = 0; i< 10; i++)
        printf("Endereco da posicao %d: %p\n", i, &a[i]);
    return 0;
}