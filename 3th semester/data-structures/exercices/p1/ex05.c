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

bool searchFast(List *list, int x) {
    if(isEmpty(list))
        return false;

    ListNodePtr aux = list->start;
    while(aux != NULL && x > aux->x) {
        aux = aux->next;
    }

    if(aux == NULL || aux->x > x)
        return false;
    else
        return true;
}

List* mergeLists(List *list1, List *list2) {    // Retornando um ponteiro de lista -> P1
    if(isEmpty(list1) || isEmpty(list2)) {
        printf("Erro ao unir as listas -> uma das listas é vazia");
        return NULL;
    }

    static List merged;
    init(&merged);
    ListNodePtr aux = list1->start;
    while(aux != NULL) {
        if(!searchFast(&merged, aux->x))
            insert(&merged, aux->x);
        aux = aux->next;
    }
    aux = list2->start;
    while(aux != NULL) {
        if(!searchFast(&merged, aux->x))
            insert(&merged, aux->x);
        aux = aux->next;
    }

    return &merged;
}

int main() {
    List list1;
    init(&list1);
    insert(&list1, 10);
    insert(&list1, 3);
    insert(&list1, 7);
    printListIncreasing(&list1);
    List list2;
    init(&list2);
    insert(&list2, 8);
    insert(&list2, 45);
    insert(&list2, 7);
    insert(&list2, 32);
    printListIncreasing(&list2);

    List *mergedList;
    mergedList = mergeLists(&list1, &list2);
    printListIncreasing(mergedList);
    printListDecreasing(mergedList);

    printListIncreasing(&list1);
    printListIncreasing(&list2);

    return 0;
}