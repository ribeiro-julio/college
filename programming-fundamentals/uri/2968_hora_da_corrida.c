#include <stdio.h>
#include <math.h>

int main(){
    int v, n, i;
    double placa;
    scanf("%d %d", &v, &n);
    n *= v;
    for (i = 1; i < 9; i++) {
        placa = ((double)n*(double)i)/10;
        v = ceil(placa);
        printf("%d ", v);
    }
    placa = ((double)n*(double)i)/10;
    v = ceil(placa);
    printf("%d\n", v);
    return 0;
}