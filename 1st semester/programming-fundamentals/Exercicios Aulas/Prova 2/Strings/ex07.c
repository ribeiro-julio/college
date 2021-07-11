#include <stdio.h>
#include <string.h>

int main(){
    char string[200] = "0", caracteres[38] = "abcdefghijklmnopqrstuvwxyz0123456789";
    int ocorrencias[37], maiorOcorrencia;
    int i;
    for(i = 0; i < 37; i++)
        ocorrencias[i] = 0;
    
    printf("Forneca a string:\n");
    setbuf(stdin, NULL);
    fgets(string, 199, stdin);
    string[strcspn(string, "\n")] = 0;

    int j;
    for(i = 0; i < 38; i++){
        for(j = 0; j < strlen(string); j++){
            if(caracteres[i] == string[j] || caracteres[i] == string[j]+32){
                ocorrencias[i] += 1;
            }
        }
    }

    for(i = 0; i < 37; i++){
        if(i == 0)
            maiorOcorrencia = ocorrencias[i];
        else
            if(ocorrencias[i] > maiorOcorrencia)
                maiorOcorrencia = ocorrencias[i];
    }

    for(i = 0; i < 37; i++){
        if(ocorrencias[i] == maiorOcorrencia)
            printf("O caractere que mais aparece e %c. Apareceu %d vezes.\n", caracteres[i], ocorrencias[i]);
    }

    return 0;
}