#include <stdio.h>

int main(){
    int n, k, notas[1000], i, maiorNota, j, classificados = 0;
    for (i = 0; i < n; i++)
        notas[i] = 0;
    scanf("%d", &n);
    scanf("%d", &k);
    for(i = 0; i < n; i++){
        scanf("%d", &notas[i]);
        if(notas[i] > maiorNota)
            maiorNota = notas[i];
    }
    for(i = maiorNota; i > 0; i--){
        for(j = 0; j < n; j++){
            if(i == notas[j])
                classificados++;
        }
        if(classificados >= k)
            break;
    }
    printf("%d\n", classificados);
    return 0;
}