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



void destroy(List *list) {
    ListNodePtr aux;
    while(list->start != NULL) {
        aux = list->start;
        list->start = list->start->next;
        free(aux); 
    }
    
    list->count = 0;
}

int first(List *list) {
    return list->start->x;
}

void init(List *list) {
    list->start = NULL;
    list->count = 0;
}

bool isEmpty(List *list) {
    // count == 0
    // start == NULL
    // end == NULL
    return list->count == 0; 
}

void insert(List *list, int x) {        // Precisa ser alterado
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

int last(List *list) {
    ListNodePtr aux;
    for(aux = list->start; aux->next != NULL; aux = aux->next);
    return aux->x;
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

int removeElement(List *list, int x) {
    int ret = -99;

    if(isEmpty(list) || x < list->start->x) {     // Lista vazia ou elemento menor que o primeiro (não contido na lista)
        printf("Erro ao remover -> Lista vazia\n");
        return ret;
    }
    
    if(x == list->start->x) {   // Tira o primeiro elemento
        ListNodePtr aux = list->start;
        ret = aux->x;
        list->start = list->start->next;
        list->start->previous = NULL;
        free(aux);
        list->count--;
        return ret;
    }

    ListNodePtr aux = list->start;
    while(aux->next != NULL && x > aux->next->x)
        aux = aux->next;

    if(aux->next == NULL || x > aux->next->x) {     // Proximo é nulo ou elemento maior que o ultimo (não contido na lista)
        printf("Erro ao remover -> Elemento nao encontrado na lista\n");
        return ret;
    } else {
        ListNodePtr toRemove = aux->next;
        ret = toRemove->x;

        if(aux->next->next == NULL && x == aux->next->x) {       // Ultimo nó -> Checar se está certo
            aux->next = NULL;
            free(toRemove);
            list->count--;
            return ret;
        }

        aux->next->next->previous = aux;
        aux->next = aux->next->next;
        free(toRemove); 
        list->count--;
        return ret;
    }
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

bool searchSlow(List *list, int x) {    // Nao otimizado -> pior caso
    ListNodePtr aux;
    for(aux = list->start; aux != NULL; aux = aux->next) {
        if(aux->x == x)
            return true;
    }

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
    printListIncreasing(&list);
    insert(&list, 4);
    printListIncreasing(&list);
    insert(&list, 7);
    printListIncreasing(&list);
    insert(&list, 8);
    printListIncreasing(&list);
    insert(&list, 6);
    printListIncreasing(&list);
    insert(&list, 4);
    printListIncreasing(&list);
    insert(&list, 8);
    printListIncreasing(&list);

    printListDecreasing(&list);

    if(searchSlow(&list, 6))
        printf("6 encontrado lentamente\n");
    if(searchFast(&list, 6))
        printf("6 encontrado rapidamente\n");

    removeElement(&list, 8);
    printListIncreasing(&list);
    removeElement(&list, 10);
    printListIncreasing(&list);
    removeElement(&list, 54545);
    printListIncreasing(&list);
    removeElement(&list, 4);
    printListIncreasing(&list);
    removeElement(&list, 6);
    printListIncreasing(&list);

    printListDecreasing(&list);

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