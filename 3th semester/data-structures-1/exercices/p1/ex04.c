#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode *ListNodePtr;

typedef struct ListNode {
    int x;
    ListNodePtr next;
    ListNodePtr previous;
} ListNode;

typedef struct {
    ListNodePtr start;
    int count;
} List;

void init(List *list) {
    list->start = NULL;
    list->count = 0;
}

bool isEmpty(List *list) {
    return list->count == 0; 
}

void insert(List *list, int x) {
    ListNodePtr new;
    new = (ListNodePtr)malloc(sizeof(ListNode));
    new->x = x;

    if(isEmpty(list)) {         // Primeira inserção
        new->next = NULL;
        new->previous = NULL;
        list->start = new;
    } else if(x < list->start->x) {     // Menor que o primeiro elemento da lista
        new->previous = NULL;
        list->start->previous = new;
        new->next = list->start;
        list->start = new;
    } else {        // Aqui tem que percorrer e encontrar o ponto de insersão
        ListNodePtr aux = list->start;
        while(aux->next != NULL && x > aux->next->x)
            aux = aux->next;

        new->next = aux->next;      // proximo elemento recebe o da posição de inserção
        if(aux->next != NULL)       // Se não for o ultimo elemento atualiza o anterior do próximo
            aux->next->previous = new;
        new->previous = aux;        // o anterior do novo elemento aponta para o da posição de inserção
        aux->next = new;            // o proximo do antigo elemente aponta para o novo elemento
    }
    list->count++;
}

void printListDecreasing(List *list) {        // Em ordem decrescente
    ListNodePtr aux;
    printf("Lista decrescente = { ");
    for(aux = list->start; aux->next != NULL; aux = aux->next);     // Vai para o ultimo elemento
    do {
        printf("%d ", aux->x);
        aux = aux->previous;
    } while(aux != NULL);
    printf("}\n");
}

void printListIncreasing(List *list) {        // Em ordem crescente
    ListNodePtr aux;
    printf("Lista crescente = { ");
    for(aux = list->start; aux != NULL; aux = aux->next) {
        printf("%d ", aux->x);
    }
    printf("}\n");
}

ListNodePtr split(List *list, int n) {      // Retornando um ponteiro do Nó -> P1
    if(isEmpty(list)) {
        printf("Não foi possivel separar -> Lista vazia\n");
        return NULL;
    }

    ListNodePtr aux;
    for(aux = list->start; aux != NULL; aux = aux->next) {
        if(aux->x == n)
            break;
    }

    if(aux == NULL) {
        printf("Não foi possivel separar -> Lista fornecida não tem uma chave igual a n\n");
        return NULL;
    }

    if(aux->next == NULL) {
        printf("Não foi possivel separar -> n fornecido é o último elemento\n");
        return NULL;
    }

    ListNodePtr separada;
    separada = aux->next;
    separada->previous = NULL;
    aux->next = NULL;
    return separada;
}

int main() {
    List list;
    init(&list);
    insert(&list, 10);
    insert(&list, 3);
    insert(&list, 7);
    insert(&list, 9);
    insert(&list, 6);
    insert(&list, 4);
    insert(&list, 8);
    printListIncreasing(&list);

    ListNodePtr ret;
    ret = split(&list, 6);
    if(ret != NULL) {
        List splitted;
        init(&splitted);
        splitted.start = ret;
        printListIncreasing(&list);
        printListDecreasing(&list);
        printListIncreasing(&splitted);
        printListDecreasing(&splitted);
    }

    return 0;
}