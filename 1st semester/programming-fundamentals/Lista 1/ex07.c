#include <stdio.h>

int main(){
  float tempC, tempK;
  printf("Digite a temperatura em Ceusius..: \n");
  scanf("%f", &tempC);
  tempK = tempC + 273.15;
  printf("Temperatura em Kelvin..: %.2f\n", tempK);
  return 0;
}
