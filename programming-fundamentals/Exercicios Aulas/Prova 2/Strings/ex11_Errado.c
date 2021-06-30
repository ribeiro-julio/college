#include <stdio.h>
#include <string.h>

int main(){
    char frase[200] = "0";

    printf("Forneca a string:\n");
    setbuf(stdin, NULL);
    fgets(frase, 199, stdin);
    frase[strcspn(frase, "\n")] = 0;

    char *result = strstr(frase, "TECLADO");

    if(result == NULL)
        printf("%s", frase);
    else{
        int inicio = result - frase;
        strncat(frase, " OU MOUSE ", inicio+7);
        printf("%s", frase);
    }
}