#include <stdio.h>
#include <string.h>

char retornaMaiusculo(char letra){
    return letra -= 32;
}

int main(){
    char frase[200] = "0";

    printf("Forneca a string:\n");
    setbuf(stdin, NULL);
    fgets(frase, 199, stdin);
    frase[strcspn(frase, "\n")] = 0;

    if(frase[0] >= 97 && frase[0] <= 122)
        frase[0] -= 32;
    int i;
    for(i = 0; i < strlen(frase); i++){
        if(frase[i] == ' ' && (frase[i+1] >= 97 && frase[i+1] <= 122))
            frase[i + 1] = retornaMaiusculo(frase[i + 1]);
    }

    printf("%s\n", frase);
    
    return 0;
}