#include <stdio.h>
#include <string.h>

char alfabeto[27] = " abcdefghijklmnopqrstuvwxyz", codigos[27][5] = { "0", "2", "22", "222", "3", "33", "333", "4", "44", "444", "5", "55", "555", "6", "66", "666", "7", "77", "777", "7777", "8", "88", "888", "9", "99", "999", "9999" };

int getAtual(char letra, char atual[]){
    int i;
    for(i = 0; i < 27; i++){
        if(letra == alfabeto[i]){
            strcpy(atual, codigos[i]);
            return 0;
        }
        else if(letra == '\0'){
            strcpy(atual, codigos[i]);
            return 0;
        }
        else if(letra == alfabeto[i]-32){
            strcpy(atual, codigos[i]);
            return 1;
        }
    }
}

int getProxima(char letra, char proxima[]){
    int i;
    for(i = 0; i < 27; i++){
        if(letra == alfabeto[i]){
            strcpy(proxima, codigos[i]);
            return 0;
        }
        else if(letra == '\0'){
            strcpy(proxima, codigos[i]);
            return 0;
        }
        else if(letra == alfabeto[i]-32){
            strcpy(proxima, codigos[i]);
            return 1;
        }
    }
}

int main(){
    char frase[141];
    char atual[5], proxima[5];
    int count, i, retornoAtual, retornoProxima;
    scanf("%d", &count);
    for(count; count > 0; count--){
        setbuf(stdin, NULL);
        fgets(frase, 140, stdin);
        frase[strcspn(frase, "\n")] = '\0';
        for(i = 0; i < strlen(frase); i++){
            retornoAtual = getAtual(frase[i], atual);
            retornoProxima = getProxima(frase[i+1], proxima);
            if(retornoAtual == 0){
                if(atual[0] != proxima[0] || retornoProxima == 1)
                    printf("%s", atual);
                else
                    printf("%s*", atual);
            }
            else{
                if(atual[0] != proxima[0] || retornoProxima == 1)
                    printf("#%s", atual);
                else
                    printf("#%s*", atual);
            }
        }
        printf("\n");
    }
}