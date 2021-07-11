#include <stdio.h>

int tetranacci(int n){
    if(n == 1 || n == 2 || n == 3)
        return 0;
    else if(n == 4)
        return 1;
    return tetranacci(n-1) + tetranacci(n-2) + tetranacci(n-3) + tetranacci(n-4);
}

int main(int argc, char **argv){
    int n, n_tetranacci;
    if(argc < 2){
        printf("Não foi fornecido o enesimo termo!");
        system("pause");
        exit(1);
    }
    
    n = atoi(argv[1]);
    n_tetranacci = tetranacci(n);
    printf("O %d numero da sequencia de tetranacci e: %d\n", n, n_tetranacci);
    return 0;
}