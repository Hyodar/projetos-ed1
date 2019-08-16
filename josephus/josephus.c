
#include "queue.h"

int main(int argc, char** argv) {

    int m = atoi(argv[1]);
    int n = atoi(argv[2]);

    Queue* queue = createQueue(n + 1);

    for(int el = 1; el <= n; el++) {
        enqueue(queue, el);
    }

    while(!isQueueEmpty(queue)) {
        for(int i=0; i<m-1; i++) {
            int el = dequeue(queue);
            enqueue(queue, el);
        }
        printf("%d ", dequeue(queue));
    }

    putchar('\n');
}
