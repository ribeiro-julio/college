#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Nenhum arquivo foi forncido como parametro\n");
        exit(1);
    }

    FILE *input_file, *output_file;

    input_file =  fopen(argv[1], "r");
    if(input_file == NULL){
        printf("Erro ao abrir o arquivo de entrada\n");
        exit(2);
    }
    output_file = fopen("output_file.txt", "w");
    if(output_file == NULL){
        printf("Erro ao abrir o arquivo de saida\n");
        exit(2);
    }

    int lines = 1;
    char c;
    c = fgetc(input_file);
    while(c != EOF){
        if(c == '\n')
            lines++;
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            fputc('*', output_file);
        else
            fputc(c, output_file);
        c = fgetc(input_file);
    }

    printf("Numero de linhas: %d\n", lines);

    fclose(input_file);
    fclose(output_file);

    return 0;
}