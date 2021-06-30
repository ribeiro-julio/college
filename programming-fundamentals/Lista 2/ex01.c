#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float grade1, grade2, mean;
}Student;

int main(){
    Student student;
    FILE *file;

    file = fopen("./students.txt", "w");
    if(file == NULL){
        printf("Erro ao abrir o arquivo!");
        system("pause");
        exit(1);
    }

    for(int i = 0; i < 10; i++){
        printf("Nome do aluno %d: ", i+1);
        setbuf(stdin, NULL);
        fgets(student.name, 49, stdin);
        student.name[strcspn(student.name, "\n")] = '\0';
        printf("Notas do aluno %d (separadas com espaco): ", i+1);
        scanf("%f %f", &student.grade1, &student.grade2);
        student.mean = (student.grade1 + student.grade2) / 2;
        printf("Media do aluno %d: %.2f\n", i+1,student.mean);
        printf("============================\n");
        fprintf(file, "%s,%.2f,%.2f,%.2f\n", student.name, student.grade1, student.grade2, student.mean);
    }

    fclose(file);
    return 0;
}