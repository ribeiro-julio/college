#include <stdio.h>

int main(){
    int *array, size;

    printf("Size of array: ");
    scanf("%d", &size);

    array = (int*)malloc(size*sizeof(int));

    for(int i = 0; i < size; i++){
        printf("array[%d]: ", i);
        scanf("%d", &array[i]);
    }
    for(int i = 0; i < size; i++){
        printf("array[%d]: %d\n", i, array[i]);
    }
    return 0;
}