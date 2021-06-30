#include <stdio.h>

typedef struct{
    char name[30];
    char registration_number[8];
}Student;

int main(){
    Student students[4];
    FILE *file;

    file = fopen("Alunos.dat", "wb");
    if(file == NULL){
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    for(int i = 0; i < 4; i++){
        printf("Nome [%d]: ", i+1);
        setbuf(stdin, NULL);
        scanf("%s", &students[i].name);
        printf("Matricula [%d]: ", i+1);
        setbuf(stdin, NULL);
        scanf("%s", &students[i].registration_number);
        printf("--------------------------\n");
    }

    fwrite(students, sizeof(Student), 4, file);

    fclose(file);
    return 0;
}