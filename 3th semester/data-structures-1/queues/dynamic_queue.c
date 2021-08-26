#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct QueueNode *QueueNodePtr;

typedef struct QueueNode {
    int x;
    QueueNodePtr next;
} QueueNode;

typedef struct {
    QueueNodePtr start;
    QueueNodePtr end;
    int size;
} DynamicQueue;


bool isEmpty(DynamicQueue *queue) {
    // size == 0
    // start == NULL
    return queue->size == 0;
}

void destroy(DynamicQueue *queue){
    printf("Destroying queue...\n");
    QueueNodePtr aux;
    while(queue->start != NULL){
        aux = queue->start;
        queue->start = queue->start->next;
        free(aux);
    }
    queue->size = 0;
}

void enqueue(DynamicQueue *queue, int x) {
    QueueNodePtr aux;
    aux = (QueueNodePtr)malloc(sizeof(QueueNode));
    aux->x = x;
    if(isEmpty(queue)) {
        queue->start = aux;
        queue->end = aux;
        aux->next = NULL;
    } else {
        aux->next = NULL;
        queue->end->next = aux;
        queue->end = aux;
    }
    queue->size++;
}

int dequeue(DynamicQueue *queue){
    int ret = -99;

    if(!isEmpty(queue)) {
        QueueNodePtr aux = queue->start;
        ret = aux->x;
        queue->start = queue->start->next;
        free(aux);
        queue->size--;
    } else
        printf("Dequeue error -> Queue is empty\n");

    return ret;
}

int first(DynamicQueue *queue){
    if(isEmpty(queue)){
        printf("No first element -> Queue is empty\n");
        return -99;
    }

    return queue->start->x;
}

void init(DynamicQueue *queue) {
    queue->start = NULL;
    queue->end = NULL;
    queue->size = 0;
}

int last(DynamicQueue *queue){
    if(isEmpty(queue)){
        printf("No last element -> Queue is empty\n");
        return -99;
    }

    return queue->end->x;
}

void printQueue(DynamicQueue *queue){
    printf("Queue = { ");
    QueueNodePtr aux;
    for(aux = queue->start; aux != NULL; aux = aux->next){
        printf("%d ", aux->x);
    }
    printf("}\n");
}

int size(DynamicQueue *queue) {
    return queue->size;
}


int main(){
    DynamicQueue queue;

    init(&queue);
    dequeue(&queue);

    printf("Primeiro elemento: %d\n", first(&queue));
    printf("Ultimo elemento: %d\n", last(&queue));

    printQueue(&queue);
    printf("Tamanho: %d\n", size(&queue));

    for(int i = 0; i < 12; i++){
        enqueue(&queue, i+1);
        printQueue(&queue);
    }

    printf("Primeiro elemento: %d\n", first(&queue));
    printf("Ultimo elemento: %d\n", last(&queue));

    printf("Tamanho: %d\n", size(&queue));
    
    for(int i = 0; i < 8; i++){
        dequeue(&queue);
        printQueue(&queue);
    }

    printf("Primeiro elemento: %d\n", first(&queue));
    printf("Ultimo elemento: %d\n", last(&queue));

    printf("Tamanho: %d\n", size(&queue));

    destroy(&queue);

    printf("Primeiro elemento: %d\n", first(&queue));
    printf("Ultimo elemento: %d\n", last(&queue));

    printf("Tamanho: %d\n", size(&queue));

    for(int i = 0; i < 7; i++){
        enqueue(&queue, i+1);
        printQueue(&queue);
    }

    printf("Primeiro elemento: %d\n", first(&queue));
    printf("Ultimo elemento: %d\n", last(&queue));

    printf("Tamanho: %d\n", size(&queue));
}