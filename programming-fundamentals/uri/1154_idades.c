#include <stdio.h>

int main(){
  int idade = 0, quantidade = 0;
  float media = 0;
  do {
    scanf("%d", &idade);
    if(idade > 0){
      media += (float)idade;
      quantidade++;
    }
  } while(idade > 0);
  media /= (float)quantidade;
  printf("%.2f\n", media);
  return 0;
}
