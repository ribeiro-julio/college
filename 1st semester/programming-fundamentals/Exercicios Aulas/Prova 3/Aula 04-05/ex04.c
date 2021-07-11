#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[30], sport[30];
    int age, height;
}Athlete;

int main(){
    Athlete athletes[5];
    int highest_age = 0, highest_age_i, highest_height = 0, highest_height_i;
    FILE *file;

    file = fopen("athletes.dat", "rb");
    if(file == NULL){
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    fread(athletes, sizeof(athletes), 5, file);
    fclose(file);

    for(int i = 0; i < 5; i++){
        puts(athletes[i].name);
        puts(athletes[i].sport);
        printf("Idade: %d\n", athletes[i].age);
        if(athletes[i].age > highest_age){
            highest_age = athletes[i].age;
            highest_age_i = i;
        }
        printf("Altura: %d\n", athletes[i].height);
        if(athletes[i].height > highest_height){
            highest_height = athletes[i].height;
            highest_height_i = i;
        }
        printf("-----------------------------\n");
    }

    printf("Atleta mais velho:\n");
    puts(athletes[highest_age_i].name);
    puts(athletes[highest_age_i].sport);
    printf("Idade: %d\n", athletes[highest_age_i].age);
    printf("Altura: %d\n", athletes[highest_age_i].height);
    printf("-----------------------------\n");
    printf("Atleta mais alto:\n");
    puts(athletes[highest_height_i].name);
    puts(athletes[highest_height_i].sport);
    printf("Idade: %d\n", athletes[highest_height_i].age);
    printf("Altura: %d\n", athletes[highest_height_i].height);

    return 0;
}