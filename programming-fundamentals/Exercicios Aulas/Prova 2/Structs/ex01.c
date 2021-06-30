#include <stdio.h>

typedef struct{
    int hora;
    int minutos;
    int segundos;
}Horario;

typedef struct{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct{
    Data data;
    Horario horario;
    char local[50], descricao[100];
}Compromisso;

int main(){
    return 0;
}