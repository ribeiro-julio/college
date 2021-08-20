#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



/*
 *  Inicio funções doubly linked list
 */

typedef struct {
    int id;
    char name[100];
    char sex;
    float weight;
    int height;
} Patient;

typedef struct ListNode *ListNodePtr;

typedef struct ListNode {
    Patient patient;
    ListNodePtr next;
    ListNodePtr previous;
} ListNode;

typedef struct {
    ListNodePtr start;
    int count;
} List;

void destroy(List *list) {
    ListNodePtr aux;
    while(list->start != NULL) {
        aux = list->start;
        list->start = list->start->next;
        free(aux); 
    }
    
    list->count = 0;
}

void init(List *list) {
    list->start = NULL;
    list->count = 0;
}

bool isEmpty(List *list) {
    return list->count == 0; 
}

void insert(List *list, Patient patient) {
    ListNodePtr new;
    new = (ListNodePtr)malloc(sizeof(ListNode));
    new->patient = patient;

    if(isEmpty(list)) {         // Primeira inserção
        new->next = NULL;
        new->previous = NULL;
        list->start = new;
    } else if(patient.id < list->start->patient.id) {     // Menor que o primeiro elemento da lista
        new->previous = NULL;
        list->start->previous = new;
        new->next = list->start;
        list->start = new;
    } else {        // Aqui tem que percorrer e encontrar o ponto de insersão
        ListNodePtr aux = list->start;
        while(aux->next != NULL && patient.id > aux->next->patient.id)
            aux = aux->next;

        new->next = aux->next;      // proximo elemento recebe o da posição de inserção
        if(aux->next != NULL)       // Se não for o ultimo elemento atualiza o anterior do próximo
            aux->next->previous = new;
        new->previous = aux;        // o anterior do novo elemento aponta para o da posição de inserção
        aux->next = new;            // o proximo do antigo elemente aponta para o novo elemento
    }
    list->count++;
}

/*
 *  Fim funções doubly linked list
 */



/*
 *  Começo funções auxiliares
 */

// Preenche a lista com os elementos do arquivo -> retorna o codigo da operacao (se for valido) e o id do paciente a pesquisar (se codigo for 3)
bool handleFile(List *list, FILE *file, int *operation, int *patient_id) {
    Patient patient;
    char line[10] = "";

    line[0] = fgetc(file);

    while(1){
        if(line[0] == '{') {    // Se o primeiro caractere da linha for um { segue com a leitura formatada
            if(fscanf(file, "%d,%[^,],%c,%f,%d}\n", &patient.id, patient.name, &patient.sex, &patient.weight, &patient.height) == 5) {  // Devem ser lidos 5 dados no formato indicado
                insert(list, patient);
                line[0] = fgetc(file);      // Le o primeiro caractere da proxima linha
            } else {        // Se os dados dos pacientes não estiver no formato especificado retorna um falso
                return false;
            }
        } else {
            if(line[0] == '1' || line[0] == '2' || line[0] == '3') {
                char next = fgetc(file);
                if(next == '\r' || next == '\n' || next == EOF)    // Entra aqui se for um digito único (1, 2, ou 3), impossibilitando 10, 20, 30...
                    *operation = atoi(line);
            }
            break;
        }
    }

    if(*operation == 3) {       // Se for uma busca tem que ler o id indicado no arquivo
        fgets(line, 9, file);
        if(line[0] == '\n')     // Se tiver lido um \n (no caso de ter /r/n le novamente) para não dar erros
            fgets(line, 9, file);
        *patient_id = atoi(line);
    }

    return true;
}

// Procura pelo paciente na lista, se encontrar escreve no arquivo, se nao, escreve uma mensagem de erro no arquivo
void searchPatient(List *list, int patient_id, FILE *file) {
    ListNodePtr aux;
    for(aux = list->start; aux != NULL; aux = aux->next) {
        if(aux->patient.id == patient_id) {
            fprintf(file, "{%d,%s,%c,%.1f,%d}", aux->patient.id, aux->patient.name, aux->patient.sex, aux->patient.weight, aux->patient.height);
            return;
        }
    }
    
    fprintf(file, "Paciente nao encontrado no arquivo de entrada!");
}

// Escreve os pacientes em ordem crescente no arquivo de saída
void writeListToFileIncreasing(List *list, FILE *file) {
    ListNodePtr aux;
    for(aux = list->start; aux != NULL; aux = aux->next)
        fprintf(file, "{%d,%s,%c,%.1f,%d}\n", aux->patient.id, aux->patient.name, aux->patient.sex, aux->patient.weight, aux->patient.height);
}

// Escreve os pacientes em ordem decrescente no arquivo de saída
void writeListToFileDecreasing(List *list, FILE *file) {
    ListNodePtr aux;
    for(aux = list->start; aux->next != NULL; aux = aux->next);     // Vai para o ultimo elemento
    do {
        fprintf(file, "{%d,%s,%c,%.1f,%d}\n", aux->patient.id, aux->patient.name, aux->patient.sex, aux->patient.weight, aux->patient.height);
        aux = aux->previous;
    } while(aux != NULL);
}

/*
 *  Fim funções auxiliares
 */



int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Quantidade invalida de parametros -> [nome_do_programa entrada.txt saida.txt]\n");
        exit(1);
    }

    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");
    if(input == NULL) {
        printf("Erro ao abrir o arquivo de entrada\n");
        exit(2);
    }
    if(output == NULL) {
        printf("Erro ao abrir o arquivo de saida\n");
        exit(2);
    }

    int operation = -99, patient_id = -99;
    List patientList;
    init(&patientList);
    if(handleFile(&patientList, input, &operation, &patient_id)) {
        if(operation == 1)
            writeListToFileIncreasing(&patientList, output);
        else if (operation == 2)
            writeListToFileDecreasing(&patientList, output);
        else if (operation == 3)
            searchPatient(&patientList, patient_id, output);
        else
            fprintf(output, "Arquivo em formato invalido!");
    } else {
        fprintf(output, "Arquivo em formato invalido!");
    }

    destroy(&patientList);
    fclose(input);
    fclose(output);

    return 0;
}