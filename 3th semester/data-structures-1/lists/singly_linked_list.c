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



void destroy(List *list) {
    printf("Destroying list...\n");
    ListNodePtr aux;
    while(list->start != NULL) {
        aux = list->start;
        list->start = list->start->next;
        free(aux); 
    }
    
    list->count = 0;
}

int first(List *list) {
    if(isEmpty(list)) {
        printf("No first element -> List is empty\n");
        return -99;
    }
    
    return list->start->x;
}

void init(List *list) {
    list->start = NULL;
    list->count = 0;
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

int last(List *list) {
    if(isEmpty(list)) {
        printf("No last element -> List is empty\n");
        return -99;
    }

    ListNodePtr aux = list->start;
    for(aux = list->start; aux->next != NULL; aux = aux->next);
    return aux->x;
}

void printList(List *list) {
    ListNodePtr aux;
    printf("List = { ");
    for(aux = list->start; aux != NULL; aux = aux->next) {
        printf("%d ", aux->x);
    }
    printf("}\n");
}

int removeElement(List *list, int x) {
    int ret = -99;

    if(isEmpty(list)) {
        printf("Removal error -> List is empty\n");
        return ret;
    } else if(x < list->start->x) {     // Elemento menor que o primeiro (não contido na lista)
        printf("Removal error -> Key not found\n");
        return ret;
    }
    
    if(x == list->start->x) {   // Tira o primeiro elemento
        ListNodePtr aux = list->start;
        ret = aux->x;
        list->start = list->start->next;
        free(aux);
        list->count--;
        return ret;
    }

    ListNodePtr aux;
    aux = list->start;
    while(aux->next != NULL && x > aux->next->x)
        aux = aux->next;
    if(aux->next == NULL || x > aux->next->x) {     // Proximo é nulo ou elemento maior que o ultimo (não contido na lista)
        printf("Removal error -> Key not found\n");
        return ret;
    } else {
        ListNodePtr toRemove = aux->next;
        ret = toRemove->x;
        aux->next = aux->next->next;
        free(toRemove); 
        list->count--;
        return ret;
    }
}

bool searchFast(List *list, int x) {
    if(isEmpty(list)) {
        printf("Search Error -> List is empty\n");
        return false;
    }

    ListNodePtr aux = list->start;
    while(aux != NULL && x > aux->x) {
        aux = aux->next;
    }

    if(aux == NULL || aux->x > x) {
        printf("Search warning -> Key not found\n");
        return false;
    }
    else
        return true;
}

bool searchSlow(List *list, int x) {    // Nao otimizado -> pior caso
    if(isEmpty(list)) {
        printf("Search Error -> List is empty\n");
        return false;
    }

    ListNodePtr aux;
    for(aux = list->start; aux != NULL; aux = aux->next) {
        if(aux->x == x)
            return true;
    }

    printf("Search warning -> Key not found\n");
    return false;
}

int size(List *list) {
    return list->count;
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
    insert(&list, 4);
    printList(&list);
    insert(&list, 8);
    printList(&list);

    if(searchSlow(&list, 6))
        printf("6 encontrado lentamente\n");
    if(searchFast(&list, 6))
        printf("6 encontrado rapidamente\n");

    removeElement(&list, 8);
    printList(&list);
    removeElement(&list, 10);
    printList(&list);
    removeElement(&list, 54545);
    printList(&list);
    removeElement(&list, 4);
    printList(&list);
    removeElement(&list, 6);
    printList(&list);

    if(!isEmpty(&list))
        printf("Lista nao vazia\n");

    printf("Tamanho: %d\n", size(&list));

    if(searchSlow(&list, 8))
        printf("Econtrado lentamente\n");
    if(!searchFast(&list, 90))
        printf("Nao econtrado rapidamente\n");

    printf("Primeiro: %d\n", first(&list));
    printf("Ultimo: %d\n", last(&list));

    return 0;
}