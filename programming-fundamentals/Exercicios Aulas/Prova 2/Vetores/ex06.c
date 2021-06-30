#include<stdio.h>

int main(){
  int valores[] = { 22, 14, 10, 50, 79, 41, 84, 16, 24, 40 };
  int maior = 0, menor = valores[0], soma = 0;
  float media = 0;
  int i;
  for (i = 0; i < 10; i++) {
    if (valores[i] > maior) {
      maior = valores[i];
    }
    else if(valores[i] < menor){
      menor = valores[i];
    }
    soma += valores[i];
  }
  media = soma/10;
  printf("O maior valor e: %d; O menor valor e: %d; A media dos valores e: %.2f\n", maior, menor, media);
  return 0;
}
