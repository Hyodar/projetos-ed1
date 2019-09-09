
#ifndef QUEUE_H_
#define QUEUE_H_

#include "node.h"

typedef struct queue {
	List* list;
} Queue;

Queue* createQueue();

void freeQueue(Queue* q);

Queue* enqueue(Queue* q, int el);

Queue* dequeue(Queue* q);

int front(Queue* q);

int empty(Queue* q);


#endif
