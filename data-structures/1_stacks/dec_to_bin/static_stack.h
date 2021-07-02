#ifndef STATIC_STACK_H
#define STATIC_STACK_H

#include <stdio.h>
#include <stdbool.h>

// 32 bits + \n
#define SIZE 33

typedef struct {
    int array[SIZE];
    int top;
} StaticStack;

void staticInit(StaticStack *stack);
bool isEmptyStatic(StaticStack *stack);
void isFullStack(StaticStack *stack);
int* staticPop(StaticStack *stack);
void staticPush(StaticStack *stack, int x);
void staticWriteToFile(StaticStack *stack, FILE *output);

#endif