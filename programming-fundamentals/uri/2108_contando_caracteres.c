#include <stdio.h>
#include <string.h>

int main(){
    char entrada[101] = "", maiorPalavra[101] = "";
    int i, count = 0, tamanhoMaiorPalavra = 0, j, indice;
    fgets(entrada, 100, stdin);
    entrada[strcspn(entrada, "\n")] = '\0';
    setbuf(stdin, NULL);
    while(entrada[0] != '0'){
        for (i = 0; i < strlen(entrada); i++){
            if(entrada[i] == ' '){
                printf("%d-", count);
                if(count >= tamanhoMaiorPalavra){
                    tamanhoMaiorPalavra = count;
                    indice = i-tamanhoMaiorPalavra;
                    for(j = 0; j < tamanhoMaiorPalavra; j++){
                        maiorPalavra[j] = entrada[indice];
                        indice++;
                    }
                }
                count = 0;
            }
            else if(strlen(entrada) == i+1){
                count++;
                printf("%d\n", count);
                if(count >= tamanhoMaiorPalavra){
                    tamanhoMaiorPalavra = count;
                    indice = i-tamanhoMaiorPalavra+1;
                    for(j = 0; j < tamanhoMaiorPalavra; j++){
                        maiorPalavra[j] = entrada[indice];
                        indice++;
                    }
                }
                count = 0;
            }
            else
                count++;
        }
        fgets(entrada, 100, stdin);
        entrada[strcspn(entrada, "\n")] = '\0';
        setbuf(stdin, NULL);
    }
    printf("\nThe biggest word: %s\n", maiorPalavra);
    return 0;
}