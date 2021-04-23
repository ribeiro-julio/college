#include <stdio.h>
#include <math.h>

int main(){
    int xf, yf, xi, yi, vi, r1, r2;
    float dist0;
    while(scanf("%d %d %d %d %d %d %d", &xf, &yf, &xi, &yi, &vi, &r1, &r2) != EOF){
    dist0 = sqrt(pow(xi-xf,2)+pow(yi-yf,2)) + (vi*1.5);
    if((dist0-r1-r2) > 0)
        printf("N\n");
    else
        printf("Y\n");
    }
    return 0;
}