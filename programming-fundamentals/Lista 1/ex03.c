#include <stdio.h>

 int main(){
   int num = 0;
   int divisions = 0;
   printf("Digite um numero inteiro..: \n");
   scanf("%d", &num);
   int i;
   for (i = 1; i <= num; i++) {
     if(num % i == 0)
       divisions++;
   }
   if(divisions == 2)
     printf("Numero primo \n");
   else
    printf("Numero nao primo \n");
   return 0;
 }
