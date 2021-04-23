#include <stdio.h>

int main(){
    int f, b, m, ef, eb, em, falta = 0;
    scanf("%d %d %d", &f, &b, &m);
    scanf("%d %d %d", &ef, &eb, &em);
    if(ef - f > 0)
        falta += (ef-f);
    if(eb - b > 0)
        falta += (eb-b);
    if(em - m > 0)
        falta += (em-m);
    printf("%d\n", falta);
    return 0;
}