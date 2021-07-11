#include <stdio.h>

void funcao(char letra, float notas[]){
    float resultado = 0;
    int i;
    if(letra == 'A'){
        for(i = 0; i < 3; i++)
            resultado += notas[i];
        resultado /= 3.0;
        printf("A media e: %.2f", resultado);
    }
    else if(letra == 'P'){
        resultado += 5.0*notas[0];
        resultado += 3.0*notas[1];
        resultado += 2.0*notas[2];
        resultado /= 10.0;
        printf("A media ponderada e: %.2f", resultado);
    }
    else if(letra == 'S'){
        for(i = 0; i < 3; i++)
            resultado += notas[i];
        printf("A soma das notas e: %.2f", resultado);
    }
}

int main(){
    float notas[3];
    char opcao;
    int i;
    for(i = 0; i < 3; i++){
        printf("Digite a nota %d do aluno: ", i+1);
        scanf("%f", &notas[i]);
    }
    printf("Selecione uma opcao:\n");
    printf("A -> Media\n");
    printf("P -> Media ponderada\n");
    printf("S -> Soma das notas\n");
    setbuf(stdin, NULL);
    scanf("%c", &opcao);
    funcao(opcao, notas);
    return 0;
}