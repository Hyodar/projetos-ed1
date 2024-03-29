
#include <time.h>
#include "queue.h"

#define QUEUE_SIZE 50

int main(int argc, char** argv) {

    srand(time(NULL));

    Queue* pares = createQueue(QUEUE_SIZE + 1);
    Queue* impares = createQueue(QUEUE_SIZE + 1);

    for(int i = 0; i < QUEUE_SIZE; i++) {
        int n = rand() % 101;
        enqueue((n & 1)? impares : pares, n);
    }

    printf("Pares: ");
    printQueue(pares);

    printf("Impares: ");
    printQueue(impares);

    destroyQueue(pares);
    destroyQueue(impares);

    return 0;
}
