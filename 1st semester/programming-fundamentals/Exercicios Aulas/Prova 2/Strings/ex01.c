#include <stdio.h>
#include <string.h>

int main(){
    char string[200] = "0";

    printf("Forneca a string:\n");
    setbuf(stdin, NULL);
    fgets(string, 199, stdin);
    string[strcspn(string, "\n")] = 0;

    printf("Numero de caracteres: %d", strlen(string));
    
    return 0;
}