#include <stdio.h>
#include <string.h>

int verificaString(char texto[200], char string[20]){
    char *result = strstr(texto, string);
    if(result == NULL)
        return -1;
    else
        return result - texto;
}

int main(){
    char texto[200] = "0", string[20] = "0";
    int i;

    printf("Forneca o texto:\n");
    setbuf(stdin, NULL);
    fgets(texto, 199, stdin);
    texto[strcspn(texto, "\n")] = 0;
    printf("Forneca a string:\n");
    setbuf(stdin, NULL);
    fgets(string, 199, stdin);
    string[strcspn(string, "\n")] = 0;

    int retorno = verificaString(texto, string);

    printf("A string %s comeca no indice %d da do texto digitado\n", string, retorno);
    printf("%s\n", texto);
    for(i = 0; i <= retorno; i++){
        if(i == retorno)
            printf("|\n");
        else
            printf(" ");
    }

    return 0;
}