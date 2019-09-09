
#ifndef STACK_H_
#define STACK_H_

#include "node.h"

typedef struct stack {
	List* list;
} Stack;

Stack* createStack();

void freeStack();

Stack* push(Stack* s, int el);

Stack* pop(Stack* s);

int top(Stack* s);

int empty(Stack* s);


#endif
