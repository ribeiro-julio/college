#include <stdio.h>

int main(int argc, char **argv){
    int l, c;
    int **array;
    FILE *file;
    
    if(argc < 2){
        printf("Deve passar o nome do arquivo como parametro!\n");
        exit(1);
    }
    file = fopen(argv[1], "r");
    if(file == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(2);
    }

    fscanf(file, "%d %d", &l, &c);
    printf("%d %d\n", l, c);

    array = (int**)calloc(l, sizeof(int));
    for(int i = 0; i < l; i++)
        array[i] = (int*)calloc(c, sizeof(int));

    for(int i = 0; i < l; i++)
        for(int j = 0; j < c; j++)
            fscanf(file, "%d", &array[i][j]);

    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++)
            printf("%d ", array[i][j]);
        printf("\n");
    }

    for(int i = 0; i < l; i++)
        free(array[i]);
    free(array);
    fclose(file);
    return 0;
}