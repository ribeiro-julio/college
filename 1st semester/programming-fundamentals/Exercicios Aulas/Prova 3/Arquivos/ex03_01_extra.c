#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    float x = -2.0, y, a, b, c;
    FILE *file;

    if(argc < 4){
        printf("Deve passar a, b e c como parametros!");
        exit(1);
    }
    file = fopen("quad.txt", "w"); 
    if(file == NULL){
        printf("Erro ao abrir o arquivo!");
        exit(2);
    }

    a = atoi(argv[1]);
    b = atoi(argv[2]);
    c = atoi(argv[3]);

    for(int i = 0; i < 19; i++){
        y = ((float)a*x*x) + ((float)b*x) + (float)c;
        fprintf(file, "%.4f\t%.4f\n", x, y);
        x += 0.5;
    }

    fclose(file);
    return 0;
}