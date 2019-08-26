
#ifndef STACK_H_
#define STACK_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
	int top;
	int size;
	int* array;
} Stack;

Stack* createStack(int size);
void destroyStack(Stack* stack);

int isStackFull(Stack* stack);
int isStackEmpty(Stack* stack);

int popStack(Stack* stack);
void pushStack(Stack* stack, int el);

#endif // STACK_H_
