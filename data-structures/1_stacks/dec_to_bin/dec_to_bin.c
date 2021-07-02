#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "static_stack.h"
#include "dynamic_stack.h"

unsigned int countLines(FILE *file)
{
    int lines = 0;
    char current, previous;

    current = fgetc(file);
    while (current != EOF) {
        if (current == '\n' && previous != '\n')
            lines++;
        previous = current;
        current = fgetc(file);
    }

    if (previous != '\n')
        lines++;

    rewind(file);

    return lines;
}

bool isInt(char *string) {
    for(int i = 0; i < 11; i++) {
        if(string[i] == '\0')
            break;
        if(string[i] < 48 || string[i] > 57)
            return false;
    }

    return true;
}

void dynamicDecToBin(int dec, DynamicStack *bin){

}

void staticDecToBin(int dec, DynamicStack *bin){

}

int main(int argc, char *argv[]){
    if(argc < 3) {
        printf("Nao foram fornecidos todos os parametros [nome_do_programa entrada.txt saida.txt]\n");
        //exit(1);
    }

    FILE *input = fopen("./input/entrada01.txt", "r");  //  arrumar
    //FILE *input = fopen(argv[1], "r");
    FILE *output = fopen("./output/saida01.txt", "w");   // arrumar
    //FILE *output = fopen(argv[2], "w");
    if(input == NULL) {
        printf("Erro ao abrir o arquivo de entrada\n");
        exit(2);
    }
    if(output == NULL) {
        printf("Erro ao abrir o arquivo de saida\n");
        exit(2);
    }

    int lines = countLines(input);
    printf("Linhas: %d\n", lines);

    char identifier = fgetc(input);
    rewind(input);
    if(identifier != 'e' && identifier != 'd') {
        printf("Arquivo invalido! [identificador]\n");
        fclose(input);
        fprintf(output, "Arquivo invalido!");
        fclose(output);
        exit(2);
    }

    // qnt de digitos de 2^32 + \0
    char line[11] = "";

    if(identifier == 'e') {
        //StaticStack input_integers;
        //StaticStack output_binary;

        //staticInit(&input_integers);
        //staticInit(&output_integers);

        for(int i = 0; i < lines; i++) {
            fgets(line, 10, input);
            line[strcspn(line, "\r")] = '\0';
            line[strcspn(line, "\n")] = '\0';
            
            if(i == 0)
                continue;

            if(!isInt(line)) {
                printf("Arquivo invalido! [numeros invalidos]\n");
                fclose(input);
                fprintf(output, "Arquivo invalido!");
                fclose(output);
                exit(2);
            } //else
                //staticPush(&input_integers, atoi(line));
        }
    } else if(identifier == 'd') {
        DynamicStack input_integers;
        DynamicStack output_binary;

        dynamicInit(&input_integers);
        dynamicInit(&output_binary);

        for(int i = 0; i < lines; i++) {
            fgets(line, 10, input);
            line[strcspn(line, "\r")] = '\0';
            line[strcspn(line, "\n")] = '\0';
            
            if(i == 0)
                continue;

            if(!isInt(line)) {
                printf("Arquivo invalido! [numeros invalidos]\n");
                fclose(input);
                fprintf(output, "Arquivo invalido!");
                fclose(output);
                destroy(&input_integers);
                destroy(&output_binary);
                exit(2);
            } else
                printf("%d\n", atoi(line));
                //dynamicPush(&input_integers, atoi(line));
        }
        dynamicWriteToFile(&input_integers, output);
    }

    return 0;
}