#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

typedef struct{
    int array[SIZE];    // Pilha com tamanho SIZE
    int top;    // Indexação
}StaticStack;

void init(StaticStack *stack){
    stack->top = 0;
}

bool isEmpty(StaticStack *stack){
    return stack->top == 0;
}

bool isFull(StaticStack *stack){
    return stack->top == SIZE;
}

int size(StaticStack *stack){
    return stack->top;
}

void push(StaticStack *stack, int x){
    if(!isFull(stack)){
        stack->array[stack->top] = x;
        stack->top++;
    }else
        printf("Nao e possivel inserir -> pilha cheia\n");
}

int pop(StaticStack *stack){
    int ret = -99;

    if(!isEmpty(stack)){
        ret = stack->array[stack->top - 1];
        stack->top--;
    }else
        printf("Nao e possivel excluir -> pilha esta vazia\n");

    return ret;
}

/*
    topo
*/

void printStack(StaticStack *stack){
    printf("Stack = { ");
    for(int i = 0; i < stack->top; i++)
        printf("%d ", stack->array[i]);
    printf("}\n");
}

int main(int argc, char *argv[]){
    StaticStack stack;
    
    init(&stack);

    if(isEmpty(&stack))
        printf("Pilha esta vazia\n");
    else
        printf("Pilha nao esta vazia\n");
    
    if(isFull(&stack))
        printf("Pilha esta cheia\n");
    else
        printf("Pilha nao esta cheia\n");

    pop(&stack);

    push(&stack, 9);
    printStack(&stack);
    push(&stack, 56);
    printStack(&stack);
    push(&stack, 134);
    printStack(&stack);
    push(&stack, 345);
    printStack(&stack);
    push(&stack, 567);
    printStack(&stack);
    push(&stack, 32);
    printStack(&stack);

    pop(&stack);

    printStack(&stack);

    printf("Tamaho da pilha: %d\n", size(&stack));

    return 0;
}