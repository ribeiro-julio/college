#include <stdio.h>
#include <stdlib.h>

int main(){
  int target = rand() % 100;
  int hunch, guesses = 0;
  do {
    printf("Guess..: \n");
    scanf("%d", &hunch);
    if(hunch < target){
      printf("HIGHER\n");
      guesses++;
    }
    else if(hunch > target){
      printf("LOWER\n");
      guesses++;
    }
    else{
      printf("ACERTOU!\n");
      break;
    }
  } while(hunch != target);
  return 0;
}
