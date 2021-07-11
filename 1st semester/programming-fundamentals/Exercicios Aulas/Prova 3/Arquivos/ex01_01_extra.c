#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    int array[5][5];
    FILE *file;

    file = fopen("numbers.txt", "r");
    if(file == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            fscanf(file, "%d", &array[i][j]);

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++)
            printf("%d ", array[i][j]);
        printf("\n");
    }

    fclose(file);
    return 0;
}