#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    char c;
    int count = 0;
    FILE *file;
    
    if(argc < 3){
        printf("Deve passar o nome do arquivo e a letra como parametro!\n");
        exit(1);
    }
    file = fopen(argv[1], "r");
    if(file == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(2);
    }

    c = fgetc(file);
    while(c != EOF){
        if(c == argv[2][0] || c+32 == argv[2][0]){
            count++;
        }
        c = fgetc(file);
    }
    printf("O caractere %c aparece %d vezes no arquivo\n", argv[2][0], count);
    fclose(file);

    return 0;
}