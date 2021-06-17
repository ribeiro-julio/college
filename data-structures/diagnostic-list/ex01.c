#include <stdio.h>

void min_to_hours(int total_min, int *hours, int *min){
    if(total_min < 60)
        *min = total_min;
    else{
        *hours = total_min/60;
        *min = total_min - *hours*60;
    }
}

int main(){
    int total_min, hours = 0, min = 0;

    printf("Minutos totais..: ");
    scanf("%d", &total_min);

    min_to_hours(total_min, &hours, &min);

    printf("Horas: %d\nMinutos: %d\n", hours, min);

    return 0;
}