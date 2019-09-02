
#include "node.h"

List* createList() {
	return NULL;
}

List* listAdd(List* list, int el) {
	Node* node = (Node*) malloc(sizeof(Node));
	node->el = el;
	node->next = list;
	return node;
}

List* listRemove(List* list, int el) {
	List* prev = NULL;
	List* i = list;

	for(; i != NULL && i->el != el; prev = i, i = i->next);

	if(i == NULL) return list;
	if(prev == NULL) {
		list = list->next;
		free(i);
		return list;
	}

	prev->next = i->next;
	free(i);

	return list;
}


void printList(List* list) {
	for(List* i = list; i != NULL; i = i->next) {
		printf("%d\n", i->el);
	}
}

void destroyList(List* list) {
	List* aux;

	while(list != NULL) {
		aux = list->next;
		free(list);
		list = aux;
	}
}

