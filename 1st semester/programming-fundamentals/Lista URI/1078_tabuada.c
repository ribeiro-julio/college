#include <stdio.h>

int main(){
  int numero = 0;
  scanf("%d", &numero);
  if(numero >= 2 && numero <= 1000){
    int i;
    for (i = 1; i <= 10; i++) {
      printf("%d x %d = %d\n", i, numero, numero*i);
    }
  }
  return 0;
}
