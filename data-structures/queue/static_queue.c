#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

typedef struct {
    int array[SIZE];
    int start;
    int end;
    int count;
} StaticQueue;

void init(StaticQueue *queue) {
    queue->start = 0;
    queue->end = -1;
    queue->count = 0;
}

bool isEmpty(StaticQueue *queue) {
    return queue->count == 0;
}

bool isFull(StaticQueue *queue) {
    return queue->count == SIZE;
}

int increaseIndex(int index) {
    return (index+1) % SIZE;
}

void enqueue(StaticQueue *queue, int x) {
    if(!isFull(queue)) {
        queue->end = increaseIndex(queue->end);
        queue->array[queue->end] = x;
        queue->count++;
    } else
        printf("Nao e possivel inserir -> fila cheia\n");
}

int dequeue(StaticQueue *queue){
    int ret = -99;

    if(!isEmpty(queue)) {
        ret = queue->array[queue->start];
        queue->start = increaseIndex(queue->start);
        queue->count--;
    } else
        printf("Nao e possivel remover -> fila vazia\n");

    return ret;
}

int first(StaticQueue *queue){

}

int last(StaticQueue *queue){

}

void printQueue(StaticQueue *queue){
    printf("Queue = { ");
    for(int i = 0; i < queue->count; i++){
        int index = (queue->start + i) % SIZE;
        printf("%d ", queue->array[index]);
    }
    printf("}\n");
}

int main(){
    StaticQueue queue;

    init(&queue);
    dequeue(&queue);

    printQueue(&queue);

    for(int i = 0; i < 12; i++)
        enqueue(&queue, i+1);

    printQueue(&queue);
    
    for(int i = 0; i < 5; i++)
        dequeue(&queue);

    printQueue(&queue);

    for(int i = 0; i < 7; i++)
        enqueue(&queue, i+1);

    printQueue(&queue);
}