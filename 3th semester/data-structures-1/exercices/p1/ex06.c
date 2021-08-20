#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    float weight;
    char name[100];
} Box;

typedef struct StackNode *StackNodePtr;

typedef struct StackNode {
    Box box;
    StackNodePtr next;
} StackNode;

typedef struct {
    StackNodePtr top;
    int size;
} Stack;

void init(Stack *stack) {
    stack->top = NULL;
    stack->size = 0;
}

int push(Stack *stack, int size, Box *box) {
    StackNodePtr aux;
    aux = (StackNodePtr)malloc(sizeof(StackNode));
    aux->box = *box;
    for(int i = 0; i < size; i++) {
        if((stack+i)->size == 0 || ((stack+i)->size < 8 && (stack+i)->top->box.weight > box->weight)) {
            aux->next = (stack+i)->top;
            (stack+i)->top = aux;
            (stack+i)->size++;
            return i;
        }
    }

    printf("Nao foi possivel empilhar a caixa\n");
    return -1;
}

int main() {
    int size = 5;
    Stack stacks[size];
    for(int i = 0; i < size; i++)
        init(&stacks[i]);
    
    Box box = {125.8, "caixa"};
    printf("Caixa empilhada na pilha %d\n", push(stacks, size, &box));
    box.weight = 100;
    printf("Caixa empilhada na pilha %d\n", push(stacks, size, &box));
    box.weight = 150;
    printf("Caixa empilhada na pilha %d\n", push(stacks, size, &box));
    box.weight = 200;
    printf("Caixa empilhada na pilha %d\n", push(stacks, size, &box));
    box.weight = 164;
    printf("Caixa empilhada na pilha %d\n", push(stacks, size, &box));
    box.weight = 148;
    printf("Caixa empilhada na pilha %d\n", push(stacks, size, &box));
    box.weight = 32;
    printf("Caixa empilhada na pilha %d\n", push(stacks, size, &box));
    box.weight = 45;
    printf("Caixa empilhada na pilha %d\n", push(stacks, size, &box));
    box.weight = 21;
    printf("Caixa empilhada na pilha %d\n", push(stacks, size, &box));
    box.weight = 10;
    printf("Caixa empilhada na pilha %d\n", push(stacks, size, &box));

    return 0;
}