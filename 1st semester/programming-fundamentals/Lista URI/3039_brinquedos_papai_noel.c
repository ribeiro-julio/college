#include <stdio.h>
#include <string.h>

int main(){
    int n, i, carrinhos = 0, bonecas = 0;
    char crianca[200] = "", sexo[2] = "";
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        setbuf(stdin, NULL);
        scanf("%199s %1s", &crianca, sexo);
        if(sexo[0] == 'M')
            carrinhos++;
        else if(sexo[0] == 'F')
            bonecas++;
    }
    printf("%d carrinhos\n", carrinhos);
    printf("%d bonecas\n", bonecas);
    return 0;
}