
#include "queue.h"

Queue* createQueue() {
	Queue* q = malloc(sizeof(Queue));
	q->list = createList();

	return q;
}

void freeQueue(Queue* q) {
	destroyList(q->list);
	free(q);
}

Queue* enqueue(Queue* q, int el) {
	
	Node* node = malloc(sizeof(Node));
	node->el = el;
	node->next = NULL;

	if(empty(q)) {
		q->list = node;
		return q;
	}

	List* aux = q->list;
	for(;aux->next; aux = aux->next);

	aux->next = node;
	return q;
}

Queue* dequeue(Queue* q) {

	if(!empty(q)) {
		Node* aux = q->list;
		q->list = q->list->next;
		free(aux);
	}

	return q;
}

int front(Queue* q) {
	return q->list->el;
}

int empty(Queue* q) {
	return q->list == NULL;
}

