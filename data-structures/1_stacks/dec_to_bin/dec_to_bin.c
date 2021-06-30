#include <stdio.h>
#include <stdbool.h>
#include "static_stack.h"
#include "dynamic_stack.h"

int main(int argc, char *argv[]){
    if(argc < 3) {
        printf("Nao foram fornecidos todos os parametros [nome_do_programa entrada.txt saida.txt]\n");
        exit(1);
    }

    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");
    if(input == NULL) {
        printf("Erro ao abrir o arquivo de entrada\n");
        exit(2);
    }
    if(output == NULL) {
        printf("Erro ao abrir o arquivo de saida\n");
        exit(2);
    }

    // Conta a quantidade de linhas -> atentar com arquivos com linhas vazias e letras diferentes de 'e' e 'd'
    char c = fgetc(input);
    int count = 1;
    while(c != EOF){
        if(c == '\n')
            count++;
        c = fgetc(input);
    }
    rewind(input);

    c = fgetc(input);
    if(c != 'e' && c != 'd') {
        fclose(input);
        fprintf(output, "Arquivo invalido!");
        fclose(output);
        exit(2);
    }

    if(c == 'e'){
        StaticStack static_stack;
        char *line;
        //fread(line, );
    } else if(c == 'd') {

    }

    return 0;
}