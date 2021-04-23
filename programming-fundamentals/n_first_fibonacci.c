#include <stdio.h>

int main(){
  int limite, interacoes = 3;
  int n = 0, n1 = 1, n2 = 1;
  printf("Digite o numeros de valores a exibir da Sequencia de Fibonacci..: \n");
  scanf("%d", &limite);
  int i;
  printf("1, 1, ");
  while (interacoes <= limite) {
    n = n1 + n2;
    if (limite != interacoes)
      printf("%d, ", n);
    else
      printf("%d. ", n);
    n2 = n1;
    n1 = n;
    interacoes++;
  }
  return 0;
}
