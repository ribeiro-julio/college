#include <stdio.h>

int main(){
  int par[5], impar[5], aux, count_par = 0, count_impar = 0, i, count = 0;
  do {
    scanf("%d", &aux);
    if(aux % 2 == 0){
      if(count_par > 4){
        for (i = 0; i < count_par; i++) {
          printf("par[%d] = %d\n", i, par[i]);
        }
        count_par = 0;
      }
      par[count_par] = aux;
      count_par++;
    }
    else{
      if(count_impar > 4){
        for (i = 0; i < count_impar; i++) {
          printf("impar[%d] = %d\n", i, impar[i]);
        }
        count_impar = 0;
      }
      impar[count_impar] = aux;
      count_impar++;
    }
    count++;
  } while(count < 15);
  for (i = 0; i < count_impar; i++) {
    printf("impar[%d] = %d\n", i, impar[i]);
  }
  for (i = 0; i < count_par; i++) {
    printf("par[%d] = %d\n", i, par[i]);
  }
  return 0;
}
