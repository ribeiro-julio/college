#include<stdio.h>

int main(){
  int idades[] = { 22, 14, 10, 50, 79, 41, 84, 16, 24, 40 };
  int count = 0;
  int i;
  for (i = 0; i < 10; i++) {
    if(idades[i] > 35){
      count++;
    }
  }
  printf("A quantidade de pessoas com mais de 35 anos e..: %d\n", count);
  return 0;
}
