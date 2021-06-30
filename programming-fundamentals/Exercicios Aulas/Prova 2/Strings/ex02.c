#include <stdio.h>
#include <string.h>

int main(){
    char string[200] = "0", vogais[6] = "aeiou", quantidade = 0;

    printf("Forneca a string:\n");
    setbuf(stdin, NULL);
    fgets(string, 199, stdin);
    string[strcspn(string, "\n")] = 0;

    int i, j;
    for(i = 0; i < strlen(string); i++){
        for(j = 0; j < strlen(vogais); j++){
            if(string[i] == vogais[j]){
                quantidade++;
                break;
            }
        }
    }
    
    printf("Existem %d vogais na string.\n", quantidade);
    
    return 0;
}