#include <stdio.h>

int main(){
    float matriz[3][3] = { { 1.0, 2.0, 3.0 }, { 4.0, 5.0, 6.0 }, { 7.0, 8.0, 9.0 } };
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            printf("Endereco de %d%d = %p\n", i, j, &matriz[i][j]);
}