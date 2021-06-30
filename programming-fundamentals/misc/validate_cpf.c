#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validarDigito1(int numeros[]){
    int i, soma = 0;
    for(i = 0; i < 9; i++){
        soma += (numeros[i]*(10-i));
    }
    soma *= 10;
    if(soma % 11 == numeros[9] || (soma % 11 == 10 && numeros[9] == 0))
        return 1;
    else
        return 0;
}

int validarDigito2(int numeros[]){
    int i, soma = 0;
    for(i = 0; i < 10; i++){
        soma += (numeros[i]*(11-i));
    }
    soma *= 10;
    if(soma % 11 == numeros[10] || (soma % 11 == 10 && numeros[10] == 0))
        return 1;
    else
        return 0;
}

int main(){
    char cpf[15];
    int numeros[11];
    int i, indice = 0;

    printf("Digite o CPF (###.###.###-##):\n");
    setbuf(stdin, NULL);
    scanf("%s", &cpf);

    for(i = 0; i < 14; i++){
        if(i == 3 || i == 7 || i == 11)
            continue;
        else{
            numeros[indice] = ((int)cpf[i])-48;
            indice++;
        }
    }

    if(validarDigito1(numeros) == 1){
        if(validarDigito2(numeros) == 1)
            printf("O CPF %s e valido\n", cpf);
        else
            printf("O CPF %s nao e valido\n", cpf);
    }
    else
        printf("O CPF %s nao e valido\n", cpf);

    return 0;
}