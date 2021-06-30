#include<stdio.h>

int main(){
  int valores[10];
  int count = 0;
  int i;
  for (i = 0; i < 10; i++) {
    printf("Digite um valor..: \n");
    scanf("%d", &valores[i]);
    if(valores[i] % 2 == 0){
      count++;
    }
  }
  printf("Existem %d numeros pares no vetor\n", count);
  return 0;
}
