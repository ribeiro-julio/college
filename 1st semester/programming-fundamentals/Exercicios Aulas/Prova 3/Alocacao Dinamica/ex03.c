#include <stdio.h>

int *multiplyArray(int A[], int B[], int size){
    int *C;
    
    C = (int*)calloc(size, sizeof(int));
    for(int i = 0; i < size; i++){
        C[i] = A[i]*B[i];
    }
    return C;
}

int main(){
    int *A, *B, *C, size;

    printf("Size of array: ");
    scanf("%d", &size);

    A = (int*)calloc(size, sizeof(int));
    B = (int*)calloc(size, sizeof(int));

    for(int i = 0; i < size; i++){
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < size; i++){
        printf("B[%d]: ", i);
        scanf("%d", &B[i]);
    }
    C = multiplyArray(A, B, size);
    for(int i = 0; i < size; i++){
        printf("C[%d]: %d\n", i, C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}