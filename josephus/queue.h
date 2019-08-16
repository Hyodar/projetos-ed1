
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

void enqueue(Queue* queue, int elem);
int dequeue(Queue* queue);

int isQueueFull(Queue* queue);
int isQueueEmpty(Queue* queue);
