#include <stdio.h>

void inverteArray(int esq, int dir, int array[]){
    int aux;
    if(esq >= dir)
        return;
    aux = array[esq];
    array[esq] = array[dir];
    array[dir] = aux;
    inverteArray(esq+1, dir-1, array);
}

int main(){
    int array[] = { 2, 6, 4, 8, 5, 4, 3, 5, 6, 8, 10 };
    int n = sizeof(array)/sizeof(int) - 1;
    inverteArray(0, n, array);
    for(int i = 0; i < n+1; i++)
        printf("%d ", array[i]);
    return 0;
}