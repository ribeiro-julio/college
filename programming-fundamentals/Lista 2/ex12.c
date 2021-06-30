#include <stdio.h>
#include <stdlib.h>

int main(){
    int characters = 0, words = 1, lines = 1, character_count = 0;
    char c;
    char letters[26] = "abcdefghijklmnopqrstuvwxyz";
    FILE *file;
    file = fopen("./file.txt", "r");
    if(file == NULL){
        printf("Erro ao abrir o arquivo!");
        system("pause");
        exit(1);
    }

    c = fgetc(file);
    while(c != EOF){
        c = fgetc(file);
        if(c != '\n' && c != '\0')
            characters++;
        if(c == ' ' || c == '\t' || c == '\0' || c == '\n')
            words++;
        if(c == '\n' || c == '\0')
            lines++;
    }
    printf("Characteres: %d; Palavras: %d; Linhas: %d\n", characters, words, lines);

    rewind(file);
    for(int i = 0; i < 26; i++){
        rewind(file);
        c = fgetc(file);
        while(c != EOF){
            if(c == letters[i] || c+32 == letters[i])
                character_count++;
            c = fgetc(file);
        }
        if(character_count > 0){
            printf("%c aparece %d vezes\n", letters[i], character_count);
            character_count = 0;
        }
    }
    fclose(file);
    return 0;
}