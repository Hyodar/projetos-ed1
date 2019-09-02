
#ifndef NODE_H_
#define NODE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int el;
	struct node* next;
} Node, List;

List* createList();
List* listAdd(List* list, int el);
List* listRemove(List* list, int el);
void destroyList(List* list);
void printList(List* list);

#endif //NODE_H_
