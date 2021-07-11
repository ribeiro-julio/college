#include <stdio.h>
#include <stdlib.h>

int array_mean(int size, int array[], int reference){
    if(size == 0)
        return 0;
    else if(size == reference)
        return (array[size-1] + array_mean(size-1, array, reference)) / size;
    return array[size-1] + array_mean(size-1, array, reference);
}

int main(int argc, char **argv){
    int size;
    int *array;
    if(argc < 2){
        printf("Não foi fornecido o tamanho do vetor!\n");
        system("pause");
        exit(1);
    }
    
    size = atoi(argv[1]);
    array = (int*)calloc(size, sizeof(int));
    for(int i = 0; i < size; i++){
        printf("Digite array[%d]: ", i);
        scanf("%d", &array[i]);
    }
    printf("%d\n", array_mean(size, array, size));

    free(array);
    return 0;
}