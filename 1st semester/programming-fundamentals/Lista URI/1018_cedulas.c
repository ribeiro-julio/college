#include <stdio.h>

int main(){
  int n = 0, notas = 0;
  scanf("%d", &n);
  printf("%d\n", n);
  if (n >= 100) {
    notas = n / 100;
    n -= 100*notas;
  }
  printf("%d nota(s) de R$ 100,00\n", notas);
  notas = 0;
  if (n >= 50) {
    notas = n / 50;
    n -= 50*notas;
  }
  printf("%d nota(s) de R$ 50,00\n", notas);
  notas = 0;
  if (n >= 20) {
    notas = n / 20;
    n -= 20*notas;
  }
  printf("%d nota(s) de R$ 20,00\n", notas);
  notas = 0;
  if (n >= 10) {
    notas = n / 10;
    n -= 10*notas;
  }
  printf("%d nota(s) de R$ 10,00\n", notas);
  notas = 0;
  if (n >= 5) {
    notas = n / 5;
    n -= 5*notas;
  }
  printf("%d nota(s) de R$ 5,00\n", notas);
  notas = 0;
  if (n >= 2) {
    notas = n / 2;
    n -= 2*notas;
  }
  printf("%d nota(s) de R$ 2,00\n", notas);
  printf("%d nota(s) de R$ 1,00\n", n);
  return 0;
}
