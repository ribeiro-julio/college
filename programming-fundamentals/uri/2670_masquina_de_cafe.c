#include <stdio.h>

int main(){
    int a, b, c, tempo1, tempo2, tempo3;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    tempo1 = b*2 + c*4;
    tempo2 = a*2 + c*2;
    tempo3 = a*4 + b*2;
    if(tempo1 <= tempo2 && tempo1 <= tempo3)
        printf("%d\n", tempo1);
    else if(tempo2 <= tempo1 && tempo2 <= tempo3)
        printf("%d\n", tempo2);
    else if(tempo3 <= tempo1 && tempo3 <= tempo2)
        printf("%d\n", tempo3);
    return 0;
}