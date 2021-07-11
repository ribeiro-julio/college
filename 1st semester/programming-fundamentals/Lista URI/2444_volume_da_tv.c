#include <stdio.h>

int main(){
  int v, t, ai;
  scanf("%d %d", &v, &t);
  int i;
  for (i = 0; i < t; i++) {
    scanf("%d", &ai);
    if(v + ai > 100)
      v = 100;
    else if(v + ai > 0)
      v += ai;
    else
      v = 0;
  }
  printf("%d\n", v);
  return 0;
}
