#include <stdio.h>

int main(){
  int cents, umR = 0, cinquenta = 0, vinteCinco = 0, dez = 0, cinco = 0, umC = 0;
  do {
    printf("Digite o valor em centavos (maior que zero)..: \n");
    scanf("%d", &cents);
  } while(cents < 0);

  while (cents >= 100) {
    umR++;
    cents -= 100;
  }
  while (cents >= 50) {
    cinquenta++;
    cents -= 50;
  }
  while (cents >= 25) {
    vinteCinco++;
    cents -= 25;
  }
  while (cents >= 10) {
    dez++;
    cents -= 10;
  }
  while (cents >= 5) {
    cinco++;
    cents -= 5;
  }
  if (cents <= 4)
    umC = cents;

  printf("O menor numero de moedas e..: \n");
  printf("%d de 1 real \n", umR);
  printf("%d de 50 centavos \n", cinquenta);
  printf("%d de 25 centavos \n", vinteCinco);
  printf("%d de 10 centavos \n", dez);
  printf("%d de 5 centavos \n", cinco);
  printf("%d de 1 centavo \n", umC);

  return 0;
}
