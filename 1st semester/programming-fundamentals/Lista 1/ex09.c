#include <stdio.h>

int main(){
  float old, new, percentage = 0.0;
  char option;
  do {
    printf("Digite o valor antigo..: \n");
    scanf("%c", &old);
    printf("Digite o novo valor..: \n");
    scanf("%f", &new);
    percentage = (new/old)*100;
    printf("O aumento foi de %.2f %%\n", percentage);
    printf("Calcular o percentual de aumento para o proximo produto? (s ou n)..: \n");
    setbuf(stdin, NULL);
    scanf("%c", &option);
    while(option != 's' && option != 'n'){
      printf("Opcao invalida!\n");
      printf("Calcular o percentual de aumento para o proximo produto? (s ou n)..: \n");
      setbuf(stdin, NULL);
      scanf("%c", &option);
    }
    if (option == 'n')
      break;
  } while(option == 's');
}
