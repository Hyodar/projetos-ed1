
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue {
    int start;
    int end;
    int size;
    int* array;
} Queue;

Queue* createQueue(int tam);
void destroyQueue(Queue* queue);

void enqueue(Queue* queue, int el);
int dequeue(Queue* queue);

void printQueue(Queue* queue);

int getQueueFirstEl(Queue* queue);
int getQueueSize(Queue* queue);

int isQueueFull(Queue* queue);
int isQueueEmpty(Queue* queue);

