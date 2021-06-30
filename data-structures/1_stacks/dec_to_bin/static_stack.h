#ifndef STATIC_STACK_H
#define STATIC_STACK_H

#include <stdio.h>
#include <stdbool.h>

#define SIZE 15

typedef struct {
    int array[SIZE];
    int top;
} StaticStack;

void init(StaticStack *stack);
bool isEmpty(StaticStack *stack);
void isFull(StaticStack *stack);
int* pop(StaticStack *stack);
void push(StaticStack *stack, int x);
void writeToFile(StaticStack *stack, FILE *output);

#endif