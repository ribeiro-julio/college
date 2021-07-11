#include<stdio.h>

int main(){
  int vetor[] = { 2, 4, 6, 7, 9, 3 };
  int soma = 0;
  int i;
  for (i = 0; i < 6; i++) {
    soma += vetor[i];
  }
  printf("A soma e..: %d\n", soma);
  return 0;
}
