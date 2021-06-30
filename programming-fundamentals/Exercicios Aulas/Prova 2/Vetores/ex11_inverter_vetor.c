#include<stdio.h>

int main(){
  int valores[10];
  int aux;
  int i;
  for (i = 0; i < 10; i++) {
    printf("Digite um valor..: \n");
    scanf("%d", &valores[i]);
  }
  for (i = 0; i < 5; i++) {
    aux = valores[i];
    valores[i] = valores[9-i];
    valores[9-i] = aux;
  }
  printf("Vetor invertido: \n");
  for (i = 0; i < 10; i++) {
    printf("%d ", valores[i]);
  }
  return 0;
}
