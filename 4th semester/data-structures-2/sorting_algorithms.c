#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int bubble_sort(int array[], int n) {
    int complexity = 0;

    bool changed = true;
    while(changed) {
        changed = false;
        for(int i = 0; i < n-1; i++) {
            if(array[i] > array[i+1]) {
                complexity++;
                int aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
                changed = true;
            }
        }
    }

    return complexity;
}

// -------------------------------------------------------

int selection_sort(int array[], int n) {
    int complexity = 0;

    for(int i = 0; i < n-1; i++) {
        int min = array[i];
        int i_min;
        for(int j = i+1; j < n; j++) {
            complexity++;
            if(array[j] < min) {
                i_min = j;
                min = array[j];
            }
        }
        if(min != array[i]) {
            int aux = array[i];
            array[i] = min;
            array[i_min] = aux;
        }
    }

    return complexity;
}

// -------------------------------------------------------

int insertion_sort(int array[], int n) {
    int complexity = 0;

    for(int i = 1; i < n; i++) {
        int aux = array[i];
        int j = i-1;
        while(j >= 0 && aux < array[j]) {
            complexity++;
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = aux;
    }

    return complexity;
}

// -------------------------------------------------------

void merge(int array[], int start, int middle, int end) {
    int i, j, k;

    int p1 = start;
    int p2 = middle + 1;

    int aux_size = (end-start) + 1;
    int *aux = (int*)malloc(aux_size*sizeof(int));

    if(aux != NULL) {
        for(int i = 0; i < aux_size; i++) {
            if(p1 <= middle && p2 <= end) {
                if(array[p1] < array[p2])
                    aux[i] = array[p1++];
                else
                    aux[i] = array[p2++];
            } else {
                if(p1 <= middle)
                    aux[i] = array[p1++];
                else
                    aux[i] = array[p2++];
            }
        }
        
        for(j=0, k=start; j < aux_size; j++, k++)
            array[k] = aux[j];
    }
    
    free(aux);
}

void merge_sort(int array[], int start, int end) {
    if(start < end) {
        int middle = (int)floor((start + end)/2);
        // makes array smaller
        merge_sort(array, start, middle);
        merge_sort(array, middle + 1, end);
        // merge small arrays
        merge(array, start, middle, end);
    }
}

// -------------------------------------------------------

int part(int array[], int start, int end) {
    int left = start;
    int right = end;
    int pivot = array[start];

    while(left < right) {
        while(array[left] <= pivot && left <= end)
            left++;
        while(array[right] > pivot && right >= start)
            right--;
        if(left < right) {
            // Troca V[Esq] e V[Dir]
            int aux = array[right];
            array[right] = array[left];
            array[left] = aux;
        }
    }
    // Troca V[Dir] com V[Inicio] 
    int aux = array[start];
    array[start] = array[right];
    array[right] = aux;

    return right;
}

void quick_sort(int array[], int start, int end) {
    if(start < end) {
        int i_pivot = part(array, start, end);
        quick_sort(array, start, i_pivot-1);
        quick_sort(array, i_pivot+1, end);
    }
}

// -------------------------------------------------------

void printArray(int array[], int n) {
    printf("{");
    for(int i = 0; i < n; i++)
        printf(" %d", array[i]);
    printf(" }\n");
}

int main() {
    int rand1[] = { 35, 15, 36, 13, 1, 40, 11, 17, 37, 33 };
    int rand2[] = { 40, 37, 36, 35, 33, 17, 15, 13, 11, 1 };
    int rand3[] = { 44, 23, 76, 38, 100, 52, 53, 80, 52, 99 };
    int rand4[] = { 80, 66, 36, 25, 61, 75, 12, 34, 43, 70 };
    int rand5[] = { 15, 4, 34, 29, 12, 50, 21, 45, 42, 28 };

    printf("Vetor original: ");
    printArray(rand1, sizeof(rand1)/sizeof(rand1[0]));
    int o_b = bubble_sort(rand1, sizeof(rand1)/sizeof(rand1[0]));
    printf("Bubble Sort - Complexidade: %d\n", o_b);
    printArray(rand1, sizeof(rand1)/sizeof(rand1[0]));
    printf("\n");

    printf("Vetor original: ");
    printArray(rand2, sizeof(rand2)/sizeof(rand2[0]));
    int o_s = selection_sort(rand2, sizeof(rand2)/sizeof(rand2[0]));
    printf("Selection Sort - Complexidade: %d\n", o_s);
    printArray(rand2, sizeof(rand2)/sizeof(rand2[0]));
    printf("\n");

    printf("Vetor original: ");
    printArray(rand3, sizeof(rand3)/sizeof(rand3[0]));
    int o_i = insertion_sort(rand3, sizeof(rand3)/sizeof(rand3[0]));
    printf("Insertion Sort - Complexidade: %d\n", o_i);
    printArray(rand3, sizeof(rand3)/sizeof(rand3[0]));
    printf("\n");

    printf("Vetor original: ");
    printArray(rand4, sizeof(rand4)/sizeof(rand4[0]));
    int o_m = 0;
    merge_sort(rand4, 0, sizeof(rand4)/sizeof(rand4[0]) - 1);
    printf("Merge Sort - Complexidade: %d\n", o_m);
    printArray(rand4, sizeof(rand4)/sizeof(rand4[0]));
    printf("\n");

    printf("Vetor original: ");
    printArray(rand5, sizeof(rand5)/sizeof(rand5[0]));
    int o_q = 0;
    quick_sort(rand5, 0, sizeof(rand5)/sizeof(rand5[0]) - 1);
    printf("Quick Sort - Complexidade: %d\n", o_m);
    printArray(rand5, sizeof(rand5)/sizeof(rand5[0]));
    printf("\n");

    return 0;
}