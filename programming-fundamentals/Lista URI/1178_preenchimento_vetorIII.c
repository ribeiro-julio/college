#include <stdio.h>

int main() {
  double x;
  double n[100];
  scanf("%lf", &x);
  n[0] = x;
  int i;
  printf("N[0] = %.4f\n", n[0]);
  for (i = 1; i < 100; i++) {
    n[i] = n[i-1]/2;
    printf("N[%d] = %.4f\n", i, n[i]);
  }
  return 0;
}
