#include <stdio.h>

int main(){
  int n;
  float sum = 0.0;
  printf("Digite n..: \n");
  scanf("%d", &n);
  int i;
  for (i = 1; i <= n; i++) {
    sum += 1/(float)i;
  }
  printf("Resultado da soma..: %.4f\n", sum);
  return 0;
}
