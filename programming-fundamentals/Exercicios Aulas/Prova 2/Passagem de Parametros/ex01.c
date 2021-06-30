#include <stdio.h>

void converteHora(int total_segundos, int* hora, int* min, int* seg){
    if(total_segundos >= 3600){
        *hora = total_segundos/3600;
        total_segundos -= (3600*(*hora));
    }
    if(total_segundos >= 60){
        *min = total_segundos/60;
        total_segundos -= (60*(*min));
    }
    *seg = total_segundos;
}

int main(){
    int total_segundos, hora = 0, min = 0, seg = 0;
    scanf("%d", &total_segundos);
    converteHora(total_segundos, &hora, &min, &seg);
    printf("%dh:%dm:%ds", hora, min, seg);
    return 0;
}