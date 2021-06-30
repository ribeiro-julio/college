#include <stdio.h>
#include <string.h>

int main(){
    char senhaDigitada[200], senha[14] = "senhaforte123";
    int retorno;

    do{
        printf("Forneca a senha:\n");
        setbuf(stdin, NULL);
        fgets(senhaDigitada, 199, stdin);
        senhaDigitada[strcspn(senhaDigitada, "\n")] = 0;

        retorno = strcmp(senha, senhaDigitada);

        if(retorno < 0)
            printf("Errou a senha -> Digitou um valor maior\n");
        else if(retorno > 0)
            printf("Errou a senha -> Digitou um valor menor\n");
        else
            printf("Acertou a senha\n");
    }while(retorno != 0);

    return 0;
}