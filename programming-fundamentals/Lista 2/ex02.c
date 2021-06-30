#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float grade1, grade2, mean;
}Student;

int main(){
    Student students[10];
    float general_mean = 0, highest_mean = 0;
    int highest_mean_i;
    FILE *file;

    file = fopen("./students.txt", "r");
    if(file == NULL){
        printf("Erro ao abrir o arquivo!");
        system("pause");
        exit(1);
    }

    for(int i = 0; i < 10; i++){
        fscanf(file, "%[^,],%f,%f,%f\n", students[i].name, &students[i].grade1, &students[i].grade2, &students[i].mean); //Formatar a leitura do arquivo
        puts(students[i].name);
        printf("Nota 1 = %.2f; Nota 2 = %.2f\n", students[i].grade1, students[i].grade2);
        printf("Media = %.2f\n", students[i].mean);
        printf("=======================\n");
        general_mean += students[i].mean;
        if(students[i].mean > highest_mean){
            highest_mean = students[i].mean;
            highest_mean_i = i;
        }
    }
    general_mean /= 10;
    printf("A maior nota foi do aluno: %s, igual a %.2f\n", students[highest_mean_i].name, students[highest_mean_i].mean);

    fclose(file);
    return 0;
}