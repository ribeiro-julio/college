#include <stdio.h>

int main(){
  double m[12][12], resultado = 0.0;
  char o;
  int i, j;
  setbuf(stdin, NULL);
  scanf("%c", &o);
  for (i = 0; i < 12; i++)
    for (j = 0; j < 12; j++)
      scanf("%lf", &m[i][j]);
  for (i = 0; i <= 10; i++)
    for (j = 0; j <= 10-i; j++)
      resultado += m[i][j];
  if (o == 'M'){
    resultado = resultado/66.0;
  }
  printf("%.1lf\n", resultado);
  return 0;
}
