#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char c;
    FILE *file;
    file = fopen("./text.txt", "r+");
    if(file == NULL){
        printf("Erro ao abrir o arquivo!");
        system("pause");
        exit(1);
    }

    while(1){
        if(feof(file))
            break;
        c = fgetc(file);
        if(c >= 97 && c <= 122){
            fseek(file, -1, SEEK_CUR);
            fputc(c-32, file);
        }
    }

    fclose(file);
    return 0;
}