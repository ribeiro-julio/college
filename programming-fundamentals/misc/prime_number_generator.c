#include <stdio.h>

int main(){
  int counter = 0, divisions, num = 0;
  while(counter < 10000){
    num++;
    divisions = 0;
    int i;
    for (i = 1; i <= num; i++) {
      if(num % i == 0)
        divisions++;
        if (divisions > 2) {  //Otimizar o código -> sai do laço se existem mais de dois divisores
          break;
        }
    }
    if (divisions == 2) {
      printf("%d ", num);
      counter++;
    }
  }
  return 0;
}
