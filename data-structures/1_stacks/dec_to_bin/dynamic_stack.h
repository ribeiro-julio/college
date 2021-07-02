#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct StackNode *StackNodePtr;

typedef struct StackNode {
    int x;
    StackNodePtr next;
} StackNode;

typedef struct {
    StackNodePtr top;
    int size;
} DynamicStack;

void destroy(DynamicStack *stack);
void dynamicInit(DynamicStack *stack);
bool isEmptyDynamic(DynamicStack *stack);
int dynamicPop(DynamicStack *stack);
void dynamicPush(DynamicStack *stack, int x);
int dynamicSize(DynamicStack *stack);
void dynamicWriteToFile(DynamicStack *stack, FILE *file);

#endif