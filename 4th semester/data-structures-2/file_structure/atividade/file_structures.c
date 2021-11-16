// JULIO CESAR GARCIA RIBEIRO   RA: 1994484

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// ----------------------Struct Professor----------------------

typedef struct {
    int code;
    char name[31];
    char sex;
    int age;
    char specialty[31];
    char phone_number[15];
} Professor;

// ----------------------Funções Tamanho Fixo----------------------

void write_registry_fixed_size(FILE *file, Professor professors[], int n) {
    for(int i = 0; i < n; i++) {
        // Para escrever código com 3 digitos
        if(professors[i].code < 10)
            fprintf(file, "00");
        else if(professors[i].code < 100)
            fprintf(file, "0");

        fprintf(file, "%d|%s", professors[i].code, professors[i].name);

        // Calcula a quantidade de espaços depois do nome (comprimento fixo)
        int spaces = 30 - strlen(professors[i].name);
        // Letra com acento ocupa 2 valores, faz isso pra arrumar a quantidade
        //    de espaços necessárias
        // Se tiver 2 ocorrencias de códigos negativos tira um espaço (uma letra)
        //    sendo gerada por 2 codigos
        int count = 0;
        for(int j = 0 ; professors[i].name[j] != '\0'; j++) {
            if(professors[i].name[j] < 0)
                count++;
            if(count == 2){
                spaces++;
                count = 0;
            }
        }
        for(int j = 0; j < spaces; j++)
            fputc(' ', file);

        fprintf(file, "|%c|", professors[i].sex);

        // Para escrever a idade 2 digitos
        if(professors[i].age < 10)
            fprintf(file, "0");

        fprintf(file, "%d|%s", professors[i].age, professors[i].specialty);

        // Calcula a quantidade de espaços depois da especialidade
        spaces = 30 - strlen(professors[i].specialty);
        // Mesma coisa de tirar os espaços a mais com a especialidade...
        count = 0;
        for(int j = 0 ; professors[i].specialty[j] != '\0'; j++) {
            if(professors[i].specialty[j] < 0)
                count++;
            if(count == 2){
                spaces++;
                count = 0;
            }
        }
        for(int j = 0; j < spaces; j++)
            fputc(' ', file);

        fprintf(file, "|%s|", professors[i].phone_number);

        if(i != n-1)
            fprintf(file, "\n");
    }
}

void read_registry_fixed_size(FILE *file, FILE *data) {
    // Volta para o início do arquivo "output"
    rewind(data);

    // Cria estrutura pra salvar os dados do arquivo
    Professor professors[10];

    // Salva os dados do arquivo na estrutura
    int i = 0;
    while(fscanf(data, "%d|%[^|]|%c|%d|%[^|]|%[^|]|\n", &professors[i].code, 
            professors[i].name, &professors[i].sex, &professors[i].age, 
            professors[i].specialty, professors[i].phone_number) == 6) {
                
        // Formata o nome (tira os espaços do tamanho fixo)
        for(int j = 29; j >= 0; j--) {
            if(professors[i].name[j] != ' ') {
                professors[i].name[j+1] = '\0';
                break;
            }

        }
        //Formata a especialidade
        for(int j = 29; j >= 0; j--) {
            if(professors[i].specialty[j] != ' ') {
                professors[i].specialty[j+1] = '\0';
                break;
            }
        }
        i++;
    }
        
    
    // Escreve os dados no outro arquivo
    int n = i;
    for(i = 0; i < n; i++) {
        // Para escrever código com 3 digitos
        fprintf(file, "{");
        if(professors[i].code < 10)
            fprintf(file, "00");
        else if(professors[i].code < 100)
            fprintf(file, "0");

        // Escreve os campos
        fprintf(file, "%d,%s,%c,", professors[i].code, 
            professors[i].name, professors[i].sex);

        // Para escrever a idade 2 digitos
        if(professors[i].age < 10)
            fprintf(file, "0");

        // Escreve os campos
        fprintf(file, "%d,%s,%s}\n", professors[i].age, professors[i].specialty, 
            professors[i].phone_number);
    }
}

// ----------------------Funções Indicador de Tamanho----------------------

void write_registry_size_indicator(FILE *file, Professor professors[], int n) {
    for(int i = 0; i < n; i++) {
        // Cacula o tamanho do registro (codigo = 3, sexo = 1, idade = 2;
        //   telefone = 14 + 6 delimitadores)
        int register_size = 3 + strlen(professors[i].name) + 1 + 2 + 
            strlen(professors[i].specialty) + 14 + 6;

        // Escreve tamanho do registro
        fprintf(file, "%d ", register_size);

        // Para escrever código com 3 digitos
        if(professors[i].code < 10)
            fprintf(file, "00");
        else if(professors[i].code < 100)
            fprintf(file, "0");

        // Escreve os campos
        fprintf(file, "%d|%s|%c|", professors[i].code, 
            professors[i].name, professors[i].sex);

        // Para escrever a idade 2 digitos
        if(professors[i].age < 10)
            fprintf(file, "0");

        // Escreve os campos
        fprintf(file, "%d|%s|%s|", professors[i].age, professors[i].specialty, 
            professors[i].phone_number);
    }
}

void read_registry_size_indicator(FILE *file, FILE *data) {
    // Volta para o início do arquivo "output"
    rewind(data);

    // Cria estrutura pra salvar os dados do arquivo
    Professor professors[10];

    // Como cada char equivale a 1 byte, pega a quantidade de bytes a serem 
    //   lidos (primeira informação), depois le byte a byte até que se tenha
    //   lido a quantidade de bytes requeridas.
    // Salva os caracteres lidos em um array
    char c;
    char buffer[256] = "";
    int bytes_to_read, bytes_read;
    while(fscanf(data, "%d ", &bytes_to_read) == 1) {
        bytes_read = 0;
        while(bytes_read < bytes_to_read) {
            buffer[bytes_read] = fgetc(data);
            bytes_read++;
        }

        // Copia o buffer para o arquivo com a formatação correta
        int i = 0;
        fprintf(file, "{");
        while(1) {
            if(buffer[i] == '\0' || buffer[i+1] == '\0') {
                fprintf(file, "}\n");
                break;
            } else if(buffer[i] == '|') {
                fprintf(file, ",");
                i++;
                continue;
            } else {
                fputc(buffer[i], file);
                i++;
            }
        }

        // Limpa o buffer para o proximo registro
        memset(buffer, 0, sizeof(buffer));
    }
}

// ----------------------Funções Delimitadores----------------------

void write_registry_delimiter(FILE *file, Professor professors[], int n) {
    for(int i = 0; i < n; i++) {
        // Para escrever código com 3 digitos
        if(professors[i].code < 10)
            fprintf(file, "00");
        else if(professors[i].code < 100)
            fprintf(file, "0");

        // Escreve os campos
        fprintf(file, "%d|%s|%c|", professors[i].code, professors[i].name, 
            professors[i].sex);

        // Para escrever a idade 2 digitos
        if(professors[i].age < 10)
            fprintf(file, "0");

        fprintf(file, "%d|%s|%s|", professors[i].age, professors[i].specialty, 
            professors[i].phone_number);

        // Registros separados por um #
        if(i != n-1)
            fprintf(file, "# ");
    }
}

void read_registry_delimiter(FILE *file, FILE *data) {
    // Volta para o início do arquivo "output"
    rewind(data);

    // Cria estrutura pra salvar os dados do arquivo
    Professor professors[10];

    // Salva os dados do arquivo na estrutura
    int i = 0;
    while(fscanf(data, "%d|%[^|]|%c|%d|%[^|]|%[^|]|# ", &professors[i].code, 
            professors[i].name, &professors[i].sex, &professors[i].age, 
            professors[i].specialty, professors[i].phone_number) == 6)
        i++;
    
    // Escreve os dados no outro arquivo
    int n = i;
    for(i = 0; i < n; i++) {
        // Para escrever código com 3 digitos
        fprintf(file, "{");
        if(professors[i].code < 10)
            fprintf(file, "00");
        else if(professors[i].code < 100)
            fprintf(file, "0");

        // Escreve os campos
        fprintf(file, "%d,%s,%c,%d,%s,%s}\n", professors[i].code, 
            professors[i].name, professors[i].sex, professors[i].age, 
            professors[i].specialty, professors[i].phone_number);
    }
}

// ----------------------Receber Valores do Arquivo de Entrada----------------------

bool handle_input(FILE *file, Professor professors[], int *method, int *size) {
    char c = fgetc(file);
    int i = 0;
    while(c == '{') {
        // Salva um professor no vetor / Se não ler 6 campos o arquivo eh inválido
        if(fscanf(file, "%d,%[^,],%c,%d,%[^,],%[^}]}", &professors[i].code, 
                professors[i].name, &professors[i].sex, &professors[i].age, 
                professors[i].specialty, professors[i].phone_number) != 6)
            return false;
        
        // Garante a idade em 2 digitos
        if(professors[i].age >= 100)
            professors[i].age = 99;

        c = fgetc(file);
        // Se for um \r ou \n le novamente
        if(c == '\r')
            c = fgetc(file);
        if(c == '\n')
            c = fgetc(file);

        // Incrementa indice
        i++;
    }

    // Se for um codigo valido returna verdadeiro, seta o metodo e a quantidade de professores
    if(c == '1' || c == '2' || c == '3') {
        *method = c - '0';
        *size = i;

        return true;
    }

    // Senao retorna falso
    return false;
}

// ----------------------Main----------------------

int main(int argc, char *argv[]) {
    if(argc != 4) {
        printf("Quantidade inválida de parâmetros! [nome_programa] [arquivo"\
            "_entrada.txt] [arquivo_saida.txt] [arquivo_leitura.txt]\n");
        exit(1);
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Erro ao abrir o arquivo de entrada\n");
        exit(2);
    }
    FILE *output = fopen(argv[2], "w+");
    if (output == NULL) {
        printf("Erro ao abrir o arquivo de entrada\n");
        exit(2);
    }
    FILE *read = fopen(argv[3], "w");
    if (read == NULL) {
        printf("Erro ao abrir o arquivo de entrada\n");
        exit(2);
    }


    Professor professors[10];
    int size = 0;
    int method = 0;
    if (handle_input(input, professors, &method, &size)) {
        if(method == 1) {
            write_registry_fixed_size(output, professors, size);
            read_registry_fixed_size(read, output);
        } else if (method == 2) {
            write_registry_size_indicator(output, professors, size);
            read_registry_size_indicator(read, output);
        } else {
            write_registry_delimiter(output, professors, size);
            read_registry_delimiter(read, output);
        }
    } else {
        fprintf(output, "Arquivo inválido");
        fprintf(read, "Arquivo inválido");
    }

    fclose(input);
    fclose(output);
    fclose(read);

    return 0;
}