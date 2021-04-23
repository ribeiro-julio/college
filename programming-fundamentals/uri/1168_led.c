#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
  int n = 0, leds = 0, i = 0, j = 0;
  char numero[1110];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    setbuf(stdin, NULL);
    scanf("%s", numero);
    for (j = 0; j < strlen(numero); j++){
      switch(numero[j]){
        case '0': leds += 6; break;
        case '1': leds += 2; break;
        case '2': leds += 5; break;
        case '3': leds += 5; break;
        case '4': leds += 4; break;
        case '5': leds += 5; break;
        case '6': leds += 6; break;
        case '7': leds += 3; break;
        case '8': leds += 7; break;
        case '9': leds += 6; break;
      }
    }
    printf("%d leds\n", leds);
    leds = 0;
  }
  return 0;
}