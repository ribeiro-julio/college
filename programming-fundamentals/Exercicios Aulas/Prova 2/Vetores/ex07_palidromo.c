#include<stdio.h>

int main(){
  int valores[] = { 1, 2, 3, 4, 5, 5, 5, 3, 2, 1 };
  int count = 0;
  int i;
  for (i = 0; i < 5; i++) {
    if(valores[i] == valores[9-i]){
      count++;
    }
  }
  if(count == 5){
    printf("O vetor ");
    for (i = 0; i < 10; i++) {
      printf("%d", valores[i]);
    }
    printf("\n");
    printf("E um palindromo\n");
  }
  else{
    printf("O vetor ");
    for (i = 0; i < 10; i++) {
      printf("%d", valores[i]);
    }
    printf("\n");
    printf("Nao e um palindromo\n");
  }
  return 0;
}
