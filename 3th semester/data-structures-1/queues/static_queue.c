#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

typedef struct {
    int array[SIZE];
    int start;
    int end;
    int size;
} StaticQueue;


bool isEmpty(StaticQueue *queue) {
    return queue->size == 0;
}

bool isFull(StaticQueue *queue) {
    return queue->size == SIZE;
}

void enqueue(StaticQueue *queue, int x) {
    if(!isFull(queue)) {
        queue->end = increaseIndex(queue->end);
        queue->array[queue->end] = x;
        queue->size++;
    } else
        printf("Enqueue error -> Queue is full\n");
}

int dequeue(StaticQueue *queue){
    int ret = -99;

    if(!isEmpty(queue)) {
        ret = queue->array[queue->start];
        queue->start = increaseIndex(queue->start);
        queue->size--;
    } else
        printf("Dequeue error -> Queue is empty\n");

    return ret;
}

int first(StaticQueue *queue){
    if(isEmpty(queue)){
        printf("No first element -> Queue is empty\n");
        return -99;
    }
    
    return queue->array[queue->start];
}

int increaseIndex(int index) {
    return (index + 1) % SIZE;
}

void init(StaticQueue *queue) {
    queue->start = 0;
    queue->end = -1;
    queue->size = 0;
}

int last(StaticQueue *queue){
    if(isEmpty(queue)){
        printf("No last element -> Queue is empty\n");
        return -99;
    }
    
    return queue->array[queue->end];
}

void printQueue(StaticQueue *queue){
    printf("Queue = { ");
    for(int i = 0; i < queue->size; i++){
        int index = (queue->start + i) % SIZE;
        printf("%d ", queue->array[index]);
    }
    printf("}\n");
}

int size(StaticQueue *queue){
    return queue->size;
}


int main(){
    StaticQueue queue;

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
    
    for(int i = 0; i < 5; i++){
        dequeue(&queue);
        printQueue(&queue);
    }

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