// JULIO CESAR GARCIA RIBEIRO   RA: 1994484

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>

// ----------------------Bubble Sort----------------------

unsigned long bubble_sort(int array[], int n) {
    unsigned long comparisons = 0;

    bool changed = true;
    while(changed) {
        changed = false;
        for(int i = 0; i < n-1; i++) {
            // Cada vez que entra no segundo for acontece uma comparação entre os elementos do vetor
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

// ----------------------Selection Sort----------------------

unsigned long selection_sort(int array[], int n) {
    unsigned long comparisons = 0;

    for(int i = 0; i < n-1; i++) {
        int min = array[i];
        int i_min;
        for(int j = i+1; j < n; j++) {
            // Cada vez que entra no segundo for acontece uma comparação entre os elementos do vetor
            comparisons++;
            if(array[j] < min) {
                i_min = j;
                min = array[j];
            }
        }
        // Adição de mais uma comparação para saber se o menor valor já não está em sua posição correta
        comparisons++;
        if(min != array[i]) {
            int aux = array[i];
            array[i] = min;
            array[i_min] = aux;
        }
    }

    return comparisons;
}

// ----------------------Insertion Sort----------------------

unsigned long insertion_sort(int array[], int n) {
    unsigned long comparisons = 0;

    for(int i = 1; i < n; i++) {
        int aux = array[i];
        int j = i-1;
        while(j >= 0 && aux < array[j]) {
            // Cada execução do while acontece uma comparação entre os elementos do vetor
            comparisons++;
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = aux;
    }

    return comparisons;
}

// ----------------------Merge Sort----------------------

void merge(int array[], int start, int middle, int end, unsigned long *comparisons) {
    int i, j, k;

    int p1 = start;
    int p2 = middle + 1;

    int aux_size = (end-start) + 1;
    int *aux = (int*)malloc(aux_size*sizeof(int));

    if(aux != NULL) {
        for(int i = 0; i < aux_size; i++) {
            if(p1 <= middle && p2 <= end) {
                // Única comparação entre os elementos do vetor
                *comparisons = *comparisons + 1;
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

int merge_sort(int array[], int start, int end, unsigned long *comparisons) {
    if(start < end) {
        int middle = (int)floor((start + end)/2);
        merge_sort(array, start, middle, comparisons);
        merge_sort(array, middle + 1, end, comparisons);
        merge(array, start, middle, end, comparisons);
    }
}

// ----------------------Quick Sort----------------------

int part(int array[], int start, int end, unsigned long *comparisons) {
    int left = start;
    int right = end;
    int pivot = array[start];

    while(left < right) {
        while(array[left] <= pivot && left <= end) {
            // Comparações para encontrar o elemento maior que o pivo
            *comparisons = *comparisons + 1;
            left++;
        }
        while(array[right] > pivot && right >= start) {
            // Comparações para encontrar o elemento menor que o pivo
            *comparisons = *comparisons + 1;
            right--;
        }
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

void quick_sort(int array[], int start, int end, unsigned long *comparisons) {
    if(start < end) {
        int i_pivot = part(array, start, end, comparisons);
        quick_sort(array, start, i_pivot-1, comparisons);
        quick_sort(array, i_pivot+1, end, comparisons);
    }
}

// ----------------------Imprimir Array----------------------

void printArray(FILE *file, int *array, int n) {
    for(int i = 0; i < n; i++)
        fprintf(file, " %d", array[i]);
}

// ----------------------Receber Valores do Arquivo de Entrada----------------------

bool getParams(FILE *file, int *n, char *method) {
    char buffer[13];

    // Lê primeira linha do arquivo
    fgets(buffer, 12, file);
    buffer[strcspn(buffer, "\r")] = 0;
    buffer[strcspn(buffer, "\n")] = 0;
    
    *n = atoi(buffer);
    // Se a primera linha for um número não irá retornar zero (também filtra se n for 0 (vetor fazio))
    if(*n == 0)
        return false;

    // Se o proximo caractere, tem que ser c, d, ou r, caso contrário o arquivo é inválido
    *method = fgetc(file);
    if(*method != 'c' && *method != 'd' && *method != 'r') {
        return false;
    }

    return true;
}

// ----------------------Escrever Arquivo de Saída----------------------

bool fillOutput(FILE *file, int bubble[], int selection[], int insertion[], int merge[], int quick[], int n) {
    unsigned long comparisons;
    clock_t start_time;
    int time_taken_millis;

    // Para os métodos simples:
    //  - Inicia o clock, chama o método que retorna o número de comparações, calcula o tempo necessário, printa o vetor, quantidade de comparações e tempo necessário
    // Para os métodos recursivos:
    //  - Inicia o clock, zera variável de comparações e a passa como referência para o método, chama o método, calcula o tempo necessário, printa o vetor, quantidade de comparações e tempo necessário

    fprintf(file, "insertionSort:");
    start_time = clock();
    comparisons = insertion_sort(insertion, n);
    time_taken_millis = (int)((clock()-start_time)*1E3/CLOCKS_PER_SEC);
    printArray(file, insertion, n);
    fprintf(file, ", %lu comp", comparisons);
    fprintf(file, ", %d ms\n", time_taken_millis);

    fprintf(file, "selectionSort:");
    start_time = clock();
    comparisons = selection_sort(selection, n);
    time_taken_millis = (int)((clock()-start_time)*1E3/CLOCKS_PER_SEC);
    printArray(file, selection, n);
    fprintf(file, ", %lu comp", comparisons);
    fprintf(file, ", %d ms\n", time_taken_millis);

    fprintf(file, "bubbleSort:");
    start_time = clock();
    comparisons = bubble_sort(bubble, n);
    time_taken_millis = (int)((clock()-start_time)*1E3/CLOCKS_PER_SEC);
    printArray(file, bubble, n);
    fprintf(file, ", %lu comp", comparisons);
    fprintf(file, ", %d ms\n", time_taken_millis);

    fprintf(file, "mergeSort:");
    start_time = clock();
    comparisons = 0;
    merge_sort(merge, 0, n-1, &comparisons);
    time_taken_millis = (int)((clock()-start_time)*1E3/CLOCKS_PER_SEC);
    printArray(file, merge, n);
    fprintf(file, ", %lu comp", comparisons);
    fprintf(file, ", %d ms\n", time_taken_millis);

    fprintf(file, "quickSort:");
    start_time = clock();
    comparisons = 0;
    quick_sort(quick, 0, n-1, &comparisons);
    time_taken_millis = (int)((clock()-start_time)*1E3/CLOCKS_PER_SEC);
    printArray(file, quick, n);
    fprintf(file, ", %lu comp", comparisons);
    fprintf(file, ", %d ms", time_taken_millis);
}

// ----------------------Main----------------------

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("O programa deve receber 3 parametros [nome_do_programa] [arquivo_de_entrada] [arquivo_de_saida]\n");
        exit(1);
    }

    FILE *input = fopen(argv[1], "r");
    if(input == NULL) {
        printf("Erro ao abrir o arquivo de entrada\n");
        exit(2);
    }
    FILE *output = fopen(argv[2], "w");
    if(output == NULL) {
        printf("Erro ao abrir o arquivo de saida\n");
        exit(2);
    }

    int n;
    char method;
    
    // Pega os dados necessários do arquivo de entrada (se o arquivo de entrada for válido continua, senão mata o programa)
    if(getParams(input, &n, &method)) {
        // Cria um vetor para cada método
        int bubble[n];
        int selection[n];
        int insertion[n];
        int merge[n];
        int quick[n];

        // Preenche os vetores com os valores requeridos
        if(method == 'c') {
            for(int i = 1; i <= n; i++) {
                bubble[i-1] = i;
                selection[i-1] = i;
                insertion[i-1] = i;
                merge[i-1] = i;
                quick[i-1] = i;
            }
        } else if (method == 'd') {
            int aux = n;
            for(int i = 0; i < n; i++) {
                bubble[i] = aux;
                selection[i] = aux;
                insertion[i] = aux;
                merge[i] = aux;
                quick[i] = aux;

                aux--;
            }
        } else if (method == 'r') {
            srand(time(NULL));
            for(int i = 0; i < n; i++) {
                int aux = (rand() % 32001);

                bubble[i] = aux;
                selection[i] = aux;
                insertion[i] = aux;
                merge[i] = aux;
                quick[i] = aux;
            }
        }

        fillOutput(output, bubble, selection, insertion, merge, quick, n);
    } else
        fprintf(output, "Arquivo inválido!");

    // Fecha os arquivos
    fclose(input);
    fclose(output);

    return 0;
}