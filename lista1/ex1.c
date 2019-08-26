
#include "queue.h"

#define TAM 6

int main(int argc, char** argv) {

    Queue* queue = createQueue(TAM + 1);

    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 1);
    dequeue(queue);
    dequeue(queue);
    enqueue(queue, 0);
    enqueue(queue, 4);
    dequeue(queue);
    dequeue(queue);
    enqueue(queue, 0);
    enqueue(queue, 2);
    enqueue(queue, 6);
    enqueue(queue, 8);

    printQueue(queue);
    destroyQueue(queue);

    return 0;
}
