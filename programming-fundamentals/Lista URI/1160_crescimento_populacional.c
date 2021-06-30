#include <stdio.h>

int main(){
  int t = 0, pa = 0, pb = 0, tempo = 0, i;
  double g1 = 0.0, g2 = 0.0, aux_g = 0.0;
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    scanf("%d %d %lf %lf", &pa, &pb, &g1, &g2);
    while (tempo <= 101){
      pa *= (1+(g1/100));
      pb *= (1+(g2/100));
      tempo++;
      if (pa > pb)
        break;
      }
      if (tempo >= 101)
        printf("Mais de 1 seculo.\n");
      else
        printf("%d anos.\n", tempo);
      tempo = 0;
  }
  return 0;
}
