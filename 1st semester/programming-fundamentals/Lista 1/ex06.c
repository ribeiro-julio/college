#include <stdio.h>

int main(){
  int num1, num2;
  int soma = 0;
  int i;
  printf("Digite o intervalo inferior..: \n");
  scanf("%d", &num1);
  printf("Digite o intervalo superior..: \n");
  scanf("%d", &num2);
  for (i = ++num1; i < num2; i++){
    soma += i;
  }
  printf("Soma dos valores no intevalo aberto (%d, %d) e..: %d\n", num1, num2, soma);

  return 0;
}
