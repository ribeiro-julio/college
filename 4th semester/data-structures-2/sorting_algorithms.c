#include <stdio.h>
#include <stdbool.h>

void bubble_sort(int array[], int n) {
    bool changed = true;
    while(changed) {
        changed = false;
        for(int i = 0; i < n-1; i++) {
            if(array[i] > array[i+1]) {
                int aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
                changed = true;
            }
        }
    }
}


int main() {
    int rand[] = { 35, 15, 36, 13, 1, 40, 11, 17, 37, 33 };
    int decres[] = { 40, 37, 36, 35, 33, 17, 15, 13, 11, 1 };

    bubble_sort(rand, sizeof(rand)/sizeof(rand[0]));
    bubble_sort(decres, sizeof(decres)/sizeof(decres[0]));

    printf("Vetor randomico organizado: {");
    for(int i = 0; i < sizeof(rand)/sizeof(rand[0]); i++)
        printf(" %d", rand[i]);
    printf(" }\n");

    printf("Vetor decrescente organizado: {");
    for(int i = 0; i < sizeof(decres)/sizeof(decres[0]); i++)
        printf(" %d", decres[i]);
    printf(" }\n");

    return 0;
}