#include <stdio.h>
 int main(){
   int num;
   int maior = 0;
   int menor = 0;
   do {
     printf("Digite um numero \n");
     scanf("%d", &num);
     if (menor == 0)
       menor = num;
     if (num > maior)
      maior = num;
     if (num < menor)
       menor = num;
   } while(num != 0);
   printf("Maior numero..: %d \n", maior);
   printf("Menor numero..: %d \n", menor);
   return 0;
 }
