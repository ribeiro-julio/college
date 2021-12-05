// JULIO CESAR GARCIA RIBEIRO   RA: 1994484

#include <stdio.h>
#include <stdlib.h>
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

void write_registry_fixed_size(FILE *file, Professor professor) {
    // Para escrever código com 3 digitos
    if(professor.code < 10)
        fprintf(file, "00");
    else if(professor.code < 100)
        fprintf(file, "0");

    fprintf(file, "%d|%s", professor.code, professor.name);

    // Calcula a quantidade de espaços depois do nome (comprimento fixo)
    int spaces = 30 - strlen(professor.name);
    // Letra com acento ocupa 2 valores, faz isso pra arrumar a quantidade
    //    de espaços necessárias
    // Se tiver 2 ocorrencias de códigos negativos tira um espaço (uma letra)
    //    sendo gerada por 2 codigos
    int count = 0;
    for(int j = 0 ; professor.name[j] != '\0'; j++) {
        if(professor.name[j] < 0)
            count++;
        if(count == 2){
            spaces++;
            count = 0;
        }
    }
    for(int j = 0; j < spaces; j++)
        fputc(' ', file);

    fprintf(file, "|%c|", professor.sex);

    // Para escrever a idade 2 digitos
    if(professor.age < 10)
        fprintf(file, "0");

    fprintf(file, "%d|%s", professor.age, professor.specialty);

    // Calcula a quantidade de espaços depois da especialidade
    spaces = 30 - strlen(professor.specialty);
    // Mesma coisa de tirar os espaços a mais com a especialidade...
    count = 0;
    for(int j = 0 ; professor.specialty[j] != '\0'; j++) {
        if(professor.specialty[j] < 0)
            count++;
        if(count == 2){
            spaces++;
            count = 0;
        }
    }
    for(int j = 0; j < spaces; j++)
        fputc(' ', file);

    fprintf(file, "|%s|\n", professor.phone_number);
}

// ----------------------Função escrever saída----------------------

void write_output(FILE *file, FILE *data, int size) {
    fprintf(file, "size=%d top=-1\n", size);

    char buffer[size+2];
    // Pula a primeira linha
    fgets(buffer, size+1, data);
    char c = fgetc(data);
    while(c != EOF) {
        if(c == '*')
            fgets(buffer, size+1, data);    // Ignora a linha
        else
            fputc(c, file);

        c = fgetc(data);
    }
}

// ----------------------Main----------------------

int main(int argc, char *argv[]) {
    if(argc != 5) {
        printf("Quantidade inválida de parâmetros! [nome_programa] [arquivo"\
            "_entrada.txt] [arquivo_operacoes.txt] [arquivo_saida"\
            "_temporario.txt] [arquivo_saida]\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Erro ao abrir o arquivo de entrada\n");
        return 2;
    }
    FILE *operations = fopen(argv[2], "r");
    if (operations == NULL) {
        printf("Erro ao abrir o arquivo de operações\n");
        return 2;
    }
    FILE *temp_output = fopen(argv[3], "w+");
    if (temp_output == NULL) {
        printf("Erro ao abrir o arquivo de saída temporário\n");
        return 2;
    }
    FILE *output = fopen(argv[4], "w");
    if (output == NULL) {
        printf("Erro ao abrir o arquivo de saída\n");
        return 2;
    }

    // Copia arquivo de entrada pro arquivo de saída temporário e fecha 
    // arquivo de entrada
    char c = fgetc(input);
    while(c != EOF) {
        fputc(c, temp_output);
        c = fgetc(input);
    }
    fclose(input);

    // Struct para adicionar professores no arquivo
    Professor professor;

    char op;
    int offset;
    int top;
    while(!feof(operations)) {
        op = fgetc(operations);
        // Inserir professor
        if(op == 'i') {
            fscanf(operations, " %d,%[^,],%c,%d,%[^,],%s\n", 
                &professor.code, professor.name, &professor.sex, 
                &professor.age, professor.specialty, professor.phone_number);

            // Vai para o começo do arquivo pra pegar o top
            fseek(temp_output, 0, SEEK_SET);
            fscanf(temp_output, "size=%d top=%d\n", &offset, &top);

            if(top == -1) {
                // Escreve no fim do arquivo
                fseek(temp_output, 0, SEEK_END);
                write_registry_fixed_size(temp_output, professor);
            } else {
                // Vai até a posição livre
                fseek(temp_output, (offset*top)+top, SEEK_CUR);

                // Atualiza a posicao livre
                int top_aux;
                fscanf(temp_output, "*%d", &top_aux);
                fseek(temp_output, 0, SEEK_SET);
                if(top_aux == -1 || top_aux >= 10)
                    fprintf(temp_output, "size=%d top=%d\n", offset, top_aux);
                else
                    fprintf(temp_output, "size=%d top=0%d\n", offset, top_aux);

                // Escreve o novo registro
                fseek(temp_output, (offset*top)+top, SEEK_CUR);
                write_registry_fixed_size(temp_output, professor);
            }

        // Deletar professor
        } else if(op == 'd') {
            int code;
            fscanf(operations, " %d\n", &code);

            // Vai para o começo do arquivo pra pegar o top
            fseek(temp_output, 0, SEEK_SET);
            fscanf(temp_output, "size=%d top=%d\n", &offset, &top);

            // Procura o professor a deletar
            int line = 0;
            while(!feof(temp_output)) {
                // Se linha começar com * ignora a linha pois está deletada
                if(fgetc(temp_output) == '*') {
                    char buffer[offset+2];
                    fgets(buffer, offset+1, temp_output);
                } else {
                    // Volta um catactere para ler do início da linha
                    fseek(temp_output, -1, SEEK_CUR);

                    fscanf(temp_output, "%d|%[^|]|%c|%d|%[^|]|%[^|]|\n", 
                        &professor.code, professor.name, &professor.sex, 
                        &professor.age, professor.specialty, professor.phone_number);
                }

                // Se encontrou faz o que precisa
                if(professor.code == code) {
                    // Coloca do top no começo do registro
                    fseek(temp_output, -1*(offset+1), SEEK_CUR);
                    fprintf(temp_output, "*%d|", top);

                    // Atualiza o top
                    fseek(temp_output, 0, SEEK_SET);
                    if(line == -1 || line >= 10)
                        fprintf(temp_output, "size=%d top=%d\n", offset, line);
                    else
                        fprintf(temp_output, "size=%d top=0%d\n", offset, line);
                    
                    break;
                }
                
                // Atualiza o registro que está lendo (top) (nro_linha - 1)
                line++;
            }
        } else {
            fprintf(temp_output, "Arquivo invalido");
            fprintf(output, "Arquivo invalido");

            return 0;
        }
    }

    fclose(operations);

    // Volta para o início do arquivo
    fseek(temp_output, 0, SEEK_SET);
    // Salva os dados no arquivo de saída
    write_output(output, temp_output, offset);

    fclose(temp_output);
    fclose(output);

    return 0;
}