#include <stdio.h>

int main(){
  int n, valores[40001], i, maior = 0, count = 0, j;
  scanf("%d", &n);
  for (i = 0; i < 40001; i++){
    valores[i] = 0;
  }
  for (i = 0; i < n; i++){
    scanf("%d", &valores[i]);
    if(valores[i] > maior)
      maior = valores[i];
  }
  for (i = 1; i <= maior; i++){
    for (j = 0; j < n; j++){
      if(i == valores[j])
        count++;
    }
    if(count > 0){
      printf("%d aparece %d vez(es)\n", i, count);
      count = 0;
    }
  }
  return 0;
}
