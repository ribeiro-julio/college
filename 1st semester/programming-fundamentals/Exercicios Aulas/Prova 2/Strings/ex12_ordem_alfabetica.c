#include <stdio.h>
#include <string.h>

int main(){
    char palavra[30] = "0", aux;
    int i, j;

    printf("Forneca a palavra:\n");
    setbuf(stdin, NULL);
    scanf("%s", &palavra);

    for (i = 0; i < strlen(palavra); i++){
        for (j = 0; j < strlen(palavra); j++){
            if (palavra[i] < palavra[j]){
                aux = palavra[i];
                palavra[i] = palavra[j];
                palavra[j] = aux;
            }
        }
    }

    printf("%s", palavra);
    return 0;
}