#include <stdio.h>
#include <stdlib.h>

void fill_array(int *array, int n){
    printf("Preencha o vetor:\n");
    for(int i = 0; i < n; i++){
        printf("Array[%d]: ", i);
        scanf("%d", &array[i]);
    }
}

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("N nao foi fornecido como parametro\n");
        exit(1);
    }

    int n = atoi(argv[1]);
    int *array;

    array = calloc(n, sizeof(int));
    fill_array(array, n);

    printf("Valores do vetor:\n");
    for(int i = 0; i < n; i++)
        printf("Array[%d] = %d\n", i, array[i]);

    free(array);

    return 0;
}