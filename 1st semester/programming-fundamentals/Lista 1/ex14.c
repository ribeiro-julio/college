#include <stdio.h>

int main(){
  int limite, num = 0, counter = 0, sum = 0;
  printf("Informe o numero para calcular o quadrado..: \n");
  scanf("%d", &limite);
  while(counter < limite){
    num++;
    if(num % 2 != 0){
      sum += num;
      counter++;
    }
  }
  printf("O quadrado de %d e %d \n", limite, sum);
  return 0;
}
