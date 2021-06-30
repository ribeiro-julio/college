#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char word[15], string[200];
    int found = 0, line = 1;
    FILE *file;

    file = fopen("./lorem.txt", "r");
    if(file == NULL){
        printf("Erro ao abrir o arquivo!");
        system("pause");
        exit(1);
    }

    printf("Digite uma palavra: ");
    scanf("%s", word);

    while(1){
        fgets(string, 200, file);
        string[strcspn(string, "\n")] = '\0';
        if(strstr(string, word) != NULL){
            found = 1;
            break;
        }
        if(feof(file))
            break;
        line++;
    }

    if(found == 1)
        printf("A palavra %s foi encontrada na linha %d, e o seu conteudo e:\n%s\n", word, line, string);
    else
        printf("A palavra %s nao foi encontrada no arquivo\n", word);

    fclose(file);
    return 0;
}