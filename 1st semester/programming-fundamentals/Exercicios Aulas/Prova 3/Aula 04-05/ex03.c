#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[30], sport[30];
    int age, height;
}Athlete;

int main(){
    Athlete athletes[5];

    for(int i = 0; i < 5; i++){
        printf("Nome (%d): ", i+1);
        setbuf(stdin, NULL);
        fgets(athletes[i].name, 29, stdin);
        athletes[i].name[strcspn(athletes[i].name, "\n")] = '\0';
        printf("Esporte (%d): ", i+1);
        setbuf(stdin, NULL);
        fgets(athletes[i].sport, 29, stdin);
        athletes[i].sport[strcspn(athletes[i].sport, "\n")] = '\0';
        printf("Idade (%d): ", i+1);
        scanf("%d", &athletes[i].age);
        printf("Altura (%d): ", i+1);
        scanf("%d", &athletes[i].height);
        printf("-----------------------------\n");
    }

    FILE *file;
    file = fopen("athletes.dat", "wb");
    if(file == NULL){
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    fwrite(athletes, sizeof(athletes), 5, file);

    fclose(file);

    return 0;
}