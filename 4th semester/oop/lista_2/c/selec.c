// Julio Cesar Garcia Ribeiro - RA: 1994484

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    if(a >= b) {
        printf("A maior ou igual a B\n");
    } else {
        printf("B maior ou igual a A\n");
    }
    
    return 0;
}