#include "dynamic_stack.h"

void destroy(DynamicStack *stack) {
    printf("Destruindo a pilha\n");
    StackNodePtr aux;
    while(stack->top != NULL) {
        aux = stack->top;
        stack->top = stack->top->next;
        free(aux);
    }
    stack->size = 0;
}

void dynamicInit(DynamicStack *stack) {
    stack->top = NULL;
    stack->size = 0;
}

bool isEmptyDynamic(DynamicStack *stack) {
    return stack->size == 0;
}

int dynamicPop(DynamicStack *stack) {
    int ret = NULL;

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

void dynamicPush(DynamicStack *stack, int x) { // Talvez precisa ser modificado
    StackNodePtr aux;
    aux = (StackNodePtr)malloc(sizeof(StackNode));
    aux->x = x;
    aux->next = stack->top;
    stack->top = aux;
    stack->size++;
}

void dynamicWriteToFile(DynamicStack *stack, FILE *output) {   // Precisa ser modificado
    printf("Stack = { ");
    StackNodePtr aux;
    for(aux = stack->top; aux != NULL; aux = aux->next){
        printf("%d ", aux->x);
    }
    printf("}\n");
}