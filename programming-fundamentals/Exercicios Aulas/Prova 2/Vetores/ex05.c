#include<stdio.h>

int main(){
  int vetor1[] = { 22, 58, 79, 50 };
  int vetor2[] = { 22, 14, 10, 50, 79 };
  printf("Valores comuns..: ");
  int i, j;
  for (i = 0; i < 4; i++) {
      for (j = 0; j < 5; j++) {
        if(vetor1[i] == vetor2[j]){
          printf("%d  ", vetor1[i]);
        }
      }
  }
  return 0;
}
