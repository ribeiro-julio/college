// Julio Cesar Garcia Ribeiro - RA: 1994484

#include <stdio.h>

int main(int argc, int *argv[]) {
    int a, b;
    int opcao;

    printf("Entre com os dois valores (separados por espaco): ");
    scanf("%d %d", &a, &b);

    printf("Menu de opcoes:\n");
    printf("1 - Somar (a+b)\n");
    printf("2 - Multiplicar (a*b)\n");
    printf("3 - Subtrair (a-b)\n");
    printf("4 - Dividir (a/b)\n");
    printf("Escolha uma opcao:\n");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1: 
            printf("A soma de a + b e: %d\n", a+b);
            break;
        case 2: 
            printf("A multiplicacao de a * b e: %d\n", a*b);
            break;
        case 3: 
            printf("A subtracao de a - b e: %d\n", a-b);
            break;
        case 4: 
            printf("A divisao de a / b e: %d\n", a/b);
            break;
        default:
            printf("Opcao invalida\n");
    }
}