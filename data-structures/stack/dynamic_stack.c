#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct StackNode *StackNodePtr;

typedef struct StackNode {
    int x;
    StackNodePtr next;
} StackNode;

typedef struct {
    StackNodePtr top;
    int size;
} DynamicStack;

void init(DynamicStack *stack) {
    stack->top = NULL;
    stack->size = 0;
}

bool isEmpty(DynamicStack *stack) {
    // size == 0
    // top == null
    return stack->size == 0;
}

int size(DynamicStack *stack) {
    return stack->size;
}

int top(DynamicStack *stack) {
    if(isEmpty(stack)) {
        printf("Nenhum elemento no topo -> pilha vazia\n");
        return -99;
    }

    return stack->top->x;
}

void push(DynamicStack *stack, int x) {
    StackNodePtr aux;
    aux = (StackNodePtr)malloc(sizeof(StackNode));
    aux->x = x;
    aux->next = stack->top;
    stack->top = aux;
    stack->size++;
}

int pop(DynamicStack *stack) {
    int ret = -99;

    if(!isEmpty(stack)) {
        StackNodePtr aux = stack->top;
        ret = aux->x;
        stack->top = stack->top->next;
        free(aux);
        stack->size--;
    } else
        printf("Nao e possivel excluir -> pilha esta vazia\n");

    return ret;
}

void destroy(DynamicStack *stack) {
    printf("Destruindo a pilha\n");
    StackNodePtr node;
    while(stack->top != NULL) {
        node = stack->top;
        stack->top = stack->top->next;
        free(node);
    }
    stack->size = 0;
}

void printStack(DynamicStack *stack) {
    printf("Stack = { ");
    StackNodePtr temp;
    for(temp = stack->top; temp != NULL; temp = temp->next){
        printf("%d ", temp->x);
    }
    printf("}\n");
}

int main(int argc, char *argv[]) {
    DynamicStack stack;

    init(&stack);

    if(isEmpty(&stack))
        printf("Pilha esta vazia\n");
    else
        printf("Pilha nao esta vazia\n");

    int ontop = top(&stack);
    if(ontop != -99)
        printf("Topo: %d\n", ontop);

    for(int i = 0; i < 10; i++) {
        push(&stack, i+1);
        printStack(&stack);
        ontop = top(&stack);
        if(ontop != -99)
            printf("Topo: %d\n", ontop);
    }

    if(isEmpty(&stack))
        printf("Pilha esta vazia\n");
    else
        printf("Pilha nao esta vazia\n");

    printf("Size = %d\n", size(&stack));

    destroy(&stack);
    printStack(&stack);
    printf("Size = %d\n", size(&stack));

    for(int i = 0; i < 11; i++) {
        printStack(&stack);
        pop(&stack);
        ontop = top(&stack);
        if(ontop != -99)
            printf("Topo: %d\n", ontop);
    }

    return 0;
}