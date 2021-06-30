#include <stdio.h>

int *allocate(int n){
    int *N;
    if(n > 1)
        N = (int*)malloc(n*sizeof(int));
    else
        N = NULL;
    return N;
}

int main(){
    int n, *N;

    printf("Size of array: ");
    scanf("%d", &n);

    N = allocate(n);

    printf("N Address: %p", N);
    return 0;
}