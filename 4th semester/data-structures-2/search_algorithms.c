#include <stdio.h>

int linearSearch(int *array, int n, int element) {
    // Testa todos os elementos até chegar no
    // requerido ou chegar no fim do vetor
    printf("Busca linear\n");
    int i;
    for(i = 0; i < n; i++) {
        if(array[i] == element) {
            printf("Achou!\nQuantidade de comparacoes..: %d\n", i+1);
            return i;
        }
    }

    printf("Nao achou!\nQuantidade de comparacoes..: %d\n", i+1);
    return -1;
}

int sortedSearch(int *array, int n, int element) {
    // Vetor deve estar ordenado
    // Busca até encontrar o valor requerido ou para se
    // encontrar um valor maior
    printf("Busca ordenada\n");
    int i;
    for(i = 0; i < n; i++) {
        if(array[i] == element) {
            printf("Achou!\nQuantidade de comparacoes..: %d\n", i+1);
            return i;
        } else if (element < array[i])
            break;
    }

    printf("Nao achou!\nQuantidade de comparacoes..: %d\n", i+1);
    return -1;
}

int binarySearch(int *array, int n, int element) {
    // Divisao e conquista
    // Calcula o elemento médio e verifica se o 
    // elemento é maior ou menor que a metade do vetor
    printf("Busca binaria\n");
    int left = 0, right = n-1;
    int count = 0;
    while(left <= right) {
        int middle = left + (right - left) / 2;
        count++;
        if(array[middle] == element) {
            printf("Achou!\nQuantidade de comparacoes..: %d\n", count);
            return middle;
        }
        else if(element > array[middle])    // Elemento é maior que o meio, está do lado direito
            left = middle + 1;
        else if (element < array[middle])   // Elemento é menor que o meio, está do lado esquerdo
            right = middle - 1;
    }

    printf("Nao achou!\nQuantidade de comparacoes..: %d\n", count);
    return -1;
}

int main() {
    int array[] = { 30, 14, 10, 13, 37, 80, 1, 3, 26, 5 };
    int sortedArray[] = { 1, 3, 5, 10, 13, 14, 26, 30, 37, 80 };

    int ret = linearSearch(array, sizeof(array)/sizeof(array[0]), 14);
    printf("Indice..: %d\n\n", ret);

    ret = sortedSearch(sortedArray, sizeof(sortedArray)/sizeof(sortedArray[0]), 14);
    printf("Indice..: %d\n\n", ret);

    ret = binarySearch(sortedArray, sizeof(sortedArray)/sizeof(sortedArray[0]), 14);
    printf("Indice..: %d\n\n", ret);

    return 0;
}