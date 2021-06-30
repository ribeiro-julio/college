#include <stdio.h>

typedef struct{
    int hora, min, seg;
}Horario;

void converteHorario(int total_segundos, Horario* hor){
    if(total_segundos >= 3600){
        hor->hora = total_segundos/3600;
        total_segundos -= (3600*(hor->hora));
    }
    if(total_segundos >= 60){
        hor->min = total_segundos/60;
        total_segundos -= (60*(hor->min));
    }
    hor->seg = total_segundos;
}

int main(){
    int total_segundos;
    Horario hor = { 0, 0, 0 };
    scanf("%d", &total_segundos);
    converteHorario(total_segundos, &hor);
    printf("%dh:%dm:%ds", hor.hora, hor.min, hor.seg);
    return 0;
}