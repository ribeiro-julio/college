#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    char c;
    FILE *file1, *file2, *newfile;
    if(argc < 4){
        printf("Necessario passar 3 parametros (arquivo_1, arquivo_2 e novo_arquivo)\n");
        system("pause");
        exit(1);
    }
    file1 = fopen(argv[1], "r");
    file2 = fopen(argv[2], "r");
    newfile = fopen(argv[3], "w");
    if(file1 == NULL || file2 == NULL || newfile == NULL){
        printf("Erro ao abrir o arquivo 1\n");
        system("pause");
        exit(2);
    }

    while(1){
        c = fgetc(file1);
        if(c == EOF)
            break;
        fputc(c, newfile);
    }

    while(1){
        c = fgetc(file2);
        if(c == EOF)
            break;
        fputc(c, newfile);
    }

    fclose(file1);
    fclose(file2);
    fclose(newfile);
    return 0;
}