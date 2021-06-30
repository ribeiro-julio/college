#include <stdio.h>

int **allocate(int l, int c){
    int **array;
    array = (int**)calloc(l, sizeof(int));
    for(int i = 0; i < l; i++)
        array[i] = (int*)calloc(c, sizeof(int));
    return array;
}

int main(){
    int **array, l, c;
    printf("[Lines] [Collums]: ");
    scanf("%d %d", &l, &c);
    array = allocate(l, c);
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            printf("array[%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++)
            printf("array[%d][%d] = %d\n", i, j, array[i][j]);
    }
    return 0;
}