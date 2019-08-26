  
#include "stack.h"

Stack* createStack(int size) {
	Stack* stack = malloc(sizeof(Stack));
	stack->array = malloc(size*sizeof(int));
	
	stack->top = 0;
	stack->size = size;

	return stack;
}

void destroyStack(Stack* stack) {
	free(stack->array);
	free(stack);
}

int popStack(Stack* stack) {
	if(isStackEmpty(stack)) {
		printf("Empty stack");
		exit(1);
	}

	--stack->top;
	return stack->array[stack->top];
}

void pushStack(Stack* stack, int el) {
	if(isStackFull(stack)) {
		printf("Full stack\n");
		exit(1);
	}

	stack->array[stack->top] = el;
	++stack->top;
}

int isStackEmpty(Stack* stack) {
	return !stack->top;
}

int isStackFull(Stack* stack) {
	return stack->top == stack->size;
}

