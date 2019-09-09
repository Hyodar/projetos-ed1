
#include "stack.h"

Stack* createStack() {
	Stack* s = malloc(sizeof(Stack));
	s->list = createList();

	return s;
}

void freeStack(Stack* s) {
	destroyList(s->list);
	free(s);
}

Stack* push(Stack* s, int el) {	
	s->list = listAdd(s->list, el);

	return s;
}

Stack* pop(Stack* s) {
	Node* node = s->list;
	s->list = s->list->next;
	free(node);

	return s;
}

int top(Stack* s) {

	if(empty(s)) {
		printf("Empty stack\n");
		exit(1);
	}

	return s->list->el;
}

int empty(Stack* s) {
	return s->list == NULL;
}

