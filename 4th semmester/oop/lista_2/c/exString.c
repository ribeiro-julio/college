// Julio Cesar Garcia Ribeiro - RA: 1994484

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char frase[50];
    char letra;
    int count = 0;

    printf("Digite uma frase: ");
    setbuf(stdin, NULL);
    fgets(frase, 49, stdin);
    frase[strcspn(frase, "\n")] = '\0';
    printf("Digite uma letra minuscula: ");
    setbuf(stdin, NULL);
    scanf("%c", &letra);

    if(letra < 97 || letra > 122) {
        printf("Letra invalida\n");
        exit(1);
    }

    for(int i = 0; i < strlen(frase); i++) {
        if ((frase[i] >= 65 && frase[i] <= 90) || (frase[i] >= 97 && frase[i] <= 122)) {
            if(letra == frase[i] || letra-32 == frase[i]) {
                printf("Letra encontrada na posicao frase[%d]\n", i);
                count++;
            }
        }
    }

    if(count == 0)
        printf("Letra nao foi encontrada na frase\n");
    else
        printf("A letra %c foi encontrada %d vezes na frase\n", letra, count);
}