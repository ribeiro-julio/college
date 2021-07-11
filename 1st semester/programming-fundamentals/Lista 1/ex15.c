#include <stdio.h>

int main(){
  int num, num2 = 1, quadrado = 0, quadradoAnterior = 0;
  printf("Digite o numero..: \n");
  scanf("%d", &num);
  while(1){
    num2++;
    quadradoAnterior = quadrado;
    quadrado = num2*num2;
    if (quadrado > num)
      break;
  }
  printf("O maior quadrado ate o numero %d e ..: %d\n", num, quadradoAnterior);
  return 0;
}
