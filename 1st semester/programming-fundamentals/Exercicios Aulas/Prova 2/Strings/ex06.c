#include <stdio.h>
#include <string.h>

int main(){
    int dia, mes, ano;
    char string_dia[3] = "0", nome_mes[10] = "0", string_ano[5] = "0";

    do{
        printf("Forneca o dia: ");
        scanf("%d", &dia);
    }while(dia <= 0 || dia > 31);
    do{
        printf("Forneca o mes: ");
        scanf("%d", &mes);
    }while(mes <= 0 || mes > 12);
    printf("Forneca o ano: ");
    scanf("%d", &ano);

    itoa(dia, string_dia, 10);
    switch(mes){
        case 1: strcpy(nome_mes, "janeiro"); break;
        case 2: strcpy(nome_mes, "fevereiro"); break;
        case 3: strcpy(nome_mes, "marco"); break;
        case 4: strcpy(nome_mes, "abril"); break;
        case 5: strcpy(nome_mes, "maio"); break;
        case 6: strcpy(nome_mes, "junho"); break;
        case 7: strcpy(nome_mes, "julho"); break;
        case 8: strcpy(nome_mes, "agosto"); break;
        case 9: strcpy(nome_mes, "setembro"); break;
        case 10: strcpy(nome_mes, "outubro"); break;
        case 11: strcpy(nome_mes, "novembro"); break;
        case 12: strcpy(nome_mes, "dezembro"); break;
    }
    itoa(ano, string_ano, 10);

    printf("%s/%s/%s", string_dia, nome_mes, string_ano);

    return 0;
}