
#include "queue.h"

Queue* createQueue(int size) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->start = 0;
    queue->end = 0;
    queue->size = size;
    queue->array = (int*) malloc(size * sizeof(int));

    return queue;
}

void destroyQueue(Queue* queue) {
    free(queue->array);
    free(queue);
}

void enqueue(Queue* queue, int el) {

    if(isQueueFull(queue)) {
        printf("Full queue \n");
        exit(1);
    }

    queue->array[queue->end] = el;
    queue->end = (queue->end + 1) % queue->size;
}

int dequeue(Queue* queue) {

    if(isQueueEmpty(queue)) {
        printf("Empty queue \n");
        exit(1);
    }

    int elem = queue->array[queue->start];
    queue->start = (queue->start + 1) % queue->size;

    return elem;
}

int isQueueFull(Queue* queue) {
    return (queue->start == ((queue->end + 1) % queue->size));
}

int isQueueEmpty(Queue* queue) {
    return (queue->start == queue->end);
}
