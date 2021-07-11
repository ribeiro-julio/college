// Single-linked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct ListNode *ListNodePtr;

typedef struct ListNode {
    int x;
    ListNodePtr next;
} ListNode;

typedef struct {
    ListNodePtr start;
    int count;
} List;



void init(List *list) {
    list->start = NULL;
    list->count = 0;
}

int size(List *list) {
    return list->count;
}

bool isEmpty(List *list) {
    // count == 0
    // start == NULL
    return list->count == 0; 
}

void insert(List *list, int x) {
    ListNodePtr new;
    new = (ListNodePtr)malloc(sizeof(ListNode));
    new->x = x;

    // Primeira inserção ou menor que o primeiro elemento da lista
    if(isEmpty(list) || x < list->start->x) {
        new->next = list->start;
        list->start = new;
    } else {
        ListNodePtr aux = list->start;    // Percorre e encontra o ponto de insersão
        while(aux->next != NULL && x > aux->next->x)
            aux = aux->next;

        new->next = aux->next;
        aux->next = new;
    }
    list->count++;
}

void printList(List *list) {
    ListNodePtr aux;
    printf("Lista = { ");
    for(aux = list->start; aux != NULL; aux = aux->next) {
        printf("%d ", aux->x);
    }
    printf("}\n");
}

/*bool search(List *list, int x) {    // Nao otimizado -> pior caso
    ListNodePtr aux;
    for(aux = list->start; aux != NULL; aux = aux->next) {
        if(aux->x == x)
            return true;
    }

    return false;
}*/

bool search(List *list, int x) {
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



int main() {
    List list;
    init(&list);

    printf("Tamanho: %d\n", size(&list));
    
    if(isEmpty(&list))
        printf("Lista vazia\n");

    insert(&list, 10);
    printList(&list);
    insert(&list, 4);
    printList(&list);
    insert(&list, 7);
    printList(&list);
    insert(&list, 8);
    printList(&list);
    insert(&list, 6);
    printList(&list);

    if(!isEmpty(&list))
        printf("Lista nao vazia\n");

    printf("Tamanho: %d\n", size(&list));

    if(search(&list, 8))
        printf("Econtrado\n");
    if(!search(&list, 90))
        printf("Nao econtrado\n");

    return 0;
}