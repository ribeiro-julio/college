#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char** found_strings(FILE *file, char *word, int *count) {
    *count = 0;
    char *found;
    while(!feof(file)) {
        char buffer[1000] = "";
        fgets(buffer, 999, file);

        found = NULL;
        found = strstr(buffer, word);

        if(found)
            (*count)++;
    }

    char **strings = (char**)malloc(*count * sizeof(char*));
    for(int i = 0; i < *count; i++) {
        strings[i] = (char*)malloc(1000 * sizeof(char));
    }
    
    rewind(file);
    int i = 0;
    while(!feof(file)) {
        char buffer[1000] = "";
        fgets(buffer, 999, file);

        found = NULL;
        found = strstr(buffer, word);

        if(found) {
            strcpy(strings[i], buffer);
            i++;
        }
    }

    return strings;
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Quantidade invalida de paarametros\n");
        return 1;
    }
    FILE *input = fopen(argv[2], "r");
    if(input == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 2;
    }

    int count;
    char **strings = found_strings(input, argv[1], &count);

    for(int i = 0; i < count; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}