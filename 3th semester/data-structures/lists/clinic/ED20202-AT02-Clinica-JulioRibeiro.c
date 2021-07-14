#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



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

Patient search(List *list, int patient_id) {
    Patient ret = { .id = -99, .name = "", .sex = ' ', .weight = 0.0, .height = 0};
    ListNodePtr aux;
    for(aux = list->start; aux != NULL; aux = aux->next) {
        if(aux->patient.id == patient_id)
            ret = aux->patient;
    }

    return ret;
}

/*
 *  Fim funções doubly linked list
 */



/*
 *  Começo funções auxiliares
 */

// Conta as linhas do arquivo -> exclui linhas vazias na contagem
int countLines(FILE *file) {
    int lines = 0;
    char current, previous;

    current = fgetc(file);
    while (current != EOF) {
        if (current == '\n' && previous != '\n')
            lines++;
        previous = current;
        current = fgetc(file);
    }

    if (previous != '\n')
        lines++;

    rewind(file);

    return lines;
}

// LER PRIMEIRO CARACTERE DA LINHA, VERIFICAR SE É UM { E DEPOIS LER O RESTO DA LINHA. NÃO PRECISA CONTAR AS LINHAS
// Preenche a lista com os elementos do arquivo -> retorna o codigo da operacao (se for valido) e o id do paciente a pesquisar (se codigo for 3)
void handleFile(List *list, FILE *file, int lines, int *operation, int *patient_id) {
    Patient patient;
    char line[10];
    for(int i = 1; i <= lines; i++) {
        if(fscanf(file, "{%d,%[^,],%c,%f,%d}\n", &patient.id, patient.name, &patient.sex, &patient.weight, &patient.height) == 5)
            insert(list, patient);
        else {
            if(lines == i && *operation == -99) {    // Ultima linha do arquivo e ainda não setou a operação (não será uma busca)
                fgets(line, 1, file);
                if(line[0] == '1' || line[0] == '2' || line[0] == '3')
                    *operation = atoi(line);
            } else {
                if(*operation == -99) {
                    fgets(line, 1, file);
                    if(line[0] == '1' || line[0] == '2' || line[0] == '3')
                        *operation = atoi(line);
                } else {
                    fgets(line, 9, file);
                    *patient_id = atoi(line);
                }
            }
        }
    }
}

// Escreve os pacientes em ordem crescente no arquivo de saída
void writeListToFileIncreasing(List *list, FILE *file) {
    ListNodePtr aux;
    fprintf(file, "{");
    for(aux = list->start; aux != NULL; aux = aux->next) {
        fprintf(file, "%d,%s,%c,%.1f,%d", aux->patient.id, aux->patient.name, aux->patient.sex, aux->patient.weight, aux->patient.height);
    }
    fprintf(file, "}\n");
}

// Escreve os pacientes em ordem decrescente no arquivo de saída
void writeListToFileDecreasing(List *list, FILE *file) {
    ListNodePtr aux;
    fprintf(file, "{");
    for(aux = list->start; aux->next != NULL; aux = aux->next);     // Vai para o ultimo elemento
    do {
        fprintf(file, "%d,%s,%c,%.1f,%d", aux->patient.id, aux->patient.name, aux->patient.sex, aux->patient.weight, aux->patient.height);
        aux = aux->previous;
    } while(aux != NULL);
    fprintf(file, "}\n");
}

// Procura pelo paciente na lista, se encontrar escreve no arquivo, se nao, escreve uma mensagem de erro no arquivo
void searchPatient(List *list, FILE *file) {

}

/*
 *  Fim funções auxiliares
 */



int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Quantidade invalida de parametros -> [nome_do_programa entrada.txt saida.txt]\n");
        //exit(1);
    }

    //FILE *input = fopen(argv[1], "r");
    FILE *input = fopen("./input/entrada03.txt", "r");
    //FILE *output = fopen(argv[2], "w");
    if(input == NULL) {
        printf("Erro ao abrir o arquivo de entrada\n");
        exit(2);
    }
    //if(output == NULL) {
        //printf("Erro ao abrir o arquivo de saida\n");
        //exit(2);
    //}

    int lines = countLines(input);      // Conta a quantidade de linhas não nulas
    int operation = -99, patient_id = -99;
    List patientList;
    init(&patientList);
    handleFile(&patientList, input, lines, &operation, &patient_id);

    


    
    return 0;
}