#include <stdio.h>

int main(){
    int matrizA[100][100], matrizB[100][100], multiplicacao[100][100], linhasA = 0, colunasA = 0, linhasB = 0, colunasB = 0;
    int i, j, k;

    printf("Digite a quantidade de linhas da matriz A: ");
    scanf("%d", &linhasA);
    printf("Digite a quantidade de colunas da matriz A: ");
    scanf("%d", &colunasA);
    printf("Digite a quantidade de linhas da matriz B: ");
    scanf("%d", &linhasB);
    printf("Digite a quantidade de colunas da matriz B: ");
    scanf("%d", &colunasB);
    printf("Preencha a matriz A:\n");
    for(i = 0; i < linhasA; i++){
        for(j = 0; j < colunasA; j++){
            printf("[%d][%d]: ", i, j);
            scanf("%d", &matrizA[i][j]);
        }
    }
    printf("Preencha a matriz B:\n");
    for(i = 0; i < linhasB; i++){
        for(j = 0; j < colunasB; j++){
            printf("[%d][%d]: ", i, j);
            scanf("%d", &matrizB[i][j]);
        }
    }

    printf("Matriz A:\n");
    for(i = 0; i < linhasA; i++){
        for(j = 0; j < colunasA; j++)
            printf("%d ", matrizA[i][j]);
        printf("\n");
    }
    printf("Matriz B:\n");
    for(i = 0; i < linhasB; i++){
        for(j = 0; j < colunasB; j++)
            printf("%d ", matrizB[i][j]);
        printf("\n");
    }

    if(linhasB == colunasA){
        for(i = 0; i < linhasA; i++){
            for(j = 0; j < colunasB; j++){
                for(k = 0; k < linhasB; k++){
                    multiplicacao[i][j] += (matrizA[i][k] * matrizB[k][j]);
                }
            }
        }
        printf("AxB:\n");
        for(i = 0; i < linhasA; i++){
            for(j = 0; j < colunasB; j++)
                printf("%d ", multiplicacao[i][j]);
            printf("\n");
        }
    }
    else
        printf("Nao e possivel realizar AxB!");
    
    return 0;
}