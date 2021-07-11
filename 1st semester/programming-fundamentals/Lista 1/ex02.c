#include <stdio.h>

int main(){
  char character;
  printf("Digite uma letra\n");
  scanf("%c", &character);
  if(character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u')
    printf("Vogal\n");
  else
    printf("Consoante\n");
  return 0;
}
