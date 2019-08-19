
#include "queue.h"

Queue* concatena(Queue* q1, Queue* q2) {
    
    Queue* merged = createQueue(getQueueSize(q1) + getQueueSize(q2) + 1);

    for(int i = 0; i < getQueueSize(merged); i++) {
        
        if(getQueueFirstEl(q1) <= getQueueFirstEl(q2) && !isQueueEmpty(q1)) {
            enqueue(merged, dequeue(q1));
        } else if(!isQueueEmpty(q2)) {
            enqueue(merged, dequeue(q2));
        } else {
            enqueue(merged, dequeue(q1));
        }

    }

    return merged;
}

int main(int argc, char** argv) {

    Queue* q1 = createQueue(3 + 1);
    enqueue(q1, 1);
    enqueue(q1, 3);
    enqueue(q1, 5);

    Queue* q2 = createQueue(4 + 1);
    enqueue(q2, 2);
    enqueue(q2, 4);
    enqueue(q2, 6);
    enqueue(q2, 7);

    Queue* merged = concatena(q1, q2);

    printQueue(merged);
    destroyQueue(q1);
    destroyQueue(q2);
    destroyQueue(merged);

    return 0;
}
