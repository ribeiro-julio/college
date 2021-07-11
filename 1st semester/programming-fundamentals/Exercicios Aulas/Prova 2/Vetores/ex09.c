#include<stdio.h>

int main(){
  int valores[10];
  int maior = 0, indice;
  int i;
  for (i = 0; i < 10; i++) {
    printf("Digite um valor..: \n");
    scanf("%d", &valores[i]);
    if(valores[i] > maior){
      maior = valores[i];
      indice = i;
    }
  }
  printf("O maior valor e: %d; Este valor se encontra no indice %d do vetor\n", maior, indice);
}
