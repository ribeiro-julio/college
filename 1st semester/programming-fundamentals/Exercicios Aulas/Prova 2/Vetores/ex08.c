#include<stdio.h>

int main(){
  int vetor1[] = { 22, 54, 457, 50, 79, 48, 22, 16, 222, 40 };
  int vetor2[] = { 22, 14, 10, 50, 79, 41, 84, 16, 24, 40 };
  int diferenca[10];
  int count = 0, indice = 0;
  int i, j;
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      if(vetor1[i] != vetor2[j]){
        count++;
      }
    }
    if(count == 10){
      diferenca[indice] = vetor1[i];
      indice++;
    }
    count = 0;
  }
  for (i = 0; i < indice; i++) {
    printf("%d ", diferenca[i]);
  }
  printf("\n");
  return 0;
}
