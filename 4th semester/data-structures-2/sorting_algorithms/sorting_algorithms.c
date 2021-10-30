#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>

int bubble_sort(int array[], int n) {
    int comparisons = 0;

    bool changed = true;
    while(changed) {
        changed = false;
        for(int i = 0; i < n-1; i++) {
            comparisons++;
            if(array[i] > array[i+1]) {
                int aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
                changed = true;
            }
        }
    }

    return comparisons;
}

// -------------------------------------------------------

int selection_sort(int array[], int n) {
    int comparisons = 0;

    for(int i = 0; i < n-1; i++) {
        int min = array[i];
        int i_min;
        for(int j = i+1; j < n; j++) {
            comparisons++;
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

    return comparisons;
}

// -------------------------------------------------------

int insertion_sort(int array[], int n) {
    int comparisons = 0;

    for(int i = 1; i < n; i++) {
        int aux = array[i];
        int j = i-1;
        while(j >= 0 && aux < array[j]) {
            comparisons++;
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = aux;
    }

    return comparisons;
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
        merge_sort(array, start, middle);
        merge_sort(array, middle + 1, end);
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
            int aux = array[right];
            array[right] = array[left];
            array[left] = aux;
        }
    }
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

void printArray(FILE *file, int *array, int n) {
    for(int i = 0; i < n; i++)
        fprintf(file, " %d", array[i]);
}

bool getParams(FILE *file, int *n, char *method) {
    char buffer[13];

    fgets(buffer, 12, file);
    buffer[strcspn(buffer, "\r")] = 0;
    buffer[strcspn(buffer, "\n")] = 0;
    
    *n = atoi(buffer);
    if(*n == 0)
        return false;

    *method = fgetc(file);
    if(*method != 'c' && *method != 'd' && *method != 'r') {
        return false;
    }

    return true;
}

bool fillOutput(FILE *file, int bubble[], int selection[], int insertion[], int merge[], int quick[], int n) {
    int comparisons;
    clock_t start_time;
    int time_taken_millis;

    fprintf(file, "insertionSort:");
    start_time = clock();
    comparisons = insertion_sort(insertion, n);
    time_taken_millis = (int)((clock()-start_time)*1E3/CLOCKS_PER_SEC);
    printArray(file, insertion, n);
    fprintf(file, ", %d comp", comparisons);
    fprintf(file, ", %d ms\n", time_taken_millis);

    fprintf(file, "selectionSort:");
    start_time = clock();
    comparisons = selection_sort(selection, n);
    time_taken_millis = (int)((clock()-start_time)*1E3/CLOCKS_PER_SEC);
    printArray(file, selection, n);
    fprintf(file, ", %d comp", comparisons);
    fprintf(file, ", %d ms\n", time_taken_millis);

    fprintf(file, "bubbleSort:");
    start_time = clock();
    comparisons = bubble_sort(bubble, n);
    time_taken_millis = (int)((clock()-start_time)*1E3/CLOCKS_PER_SEC);
    printArray(file, bubble, n);
    fprintf(file, ", %d comp", comparisons);
    fprintf(file, ", %d ms\n", time_taken_millis);

    //fprintf(file, "mergeSort:");

    //fprintf(file, "quickSort:");
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("O programa deve receber 3 parametros [nome_do_programa] [arquivo_de_entrada] [arquivo_de_saida]\n");
        //exit(1);
    }

    //FILE *input = fopen(argv[1], "r");
    FILE *input = fopen("./input/input3.txt", "r");
    if(input == NULL) {
        printf("Erro ao abrir o arquivo de entrada\n");
        exit(2);
    }
    //FILE *output = fopen(argv[2], "w");
    FILE *output = fopen("./output/output3.txt", "w");
    if(output == NULL) {
        printf("Erro ao abrir o arquivo de saida\n");
        exit(2);
    }

    int n;
    char method;

    if(getParams(input, &n, &method)) {
        int input_array[n];

        if(method == 'c') {
            for(int i = 1; i <= n; i++)
                input_array[i-1] = i;
        } else if (method == 'd') {
            int aux = n;
            for(int i = 0; i < n; i++) {
                input_array[i] = aux;
                aux--;
            }
        } else if (method == 'r') {
            srand(time(NULL));
            for(int i = 0; i < n; i++) {
                input_array[i] = (rand() % 32001);
            }
        }

        int *bubble = input_array;
        int *selection = input_array;
        int *insertion = input_array;
        int *merge = input_array;
        int *quick = input_array;

        fillOutput(output, bubble, selection, insertion, merge, quick, n);
    } else
        fprintf(output, "Arquivo inválido!");

    fclose(input);
    fclose(output);

    return 0;
}