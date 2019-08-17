
#include "queue.h"

int main(int argc, char** argv) {

    if(argc == 1 || !strcmp(argv[1], "-help")) {
        printf("Usage: ./josephus [interval] [rebel_count]\n");
        exit(0);
    }

    int m = atoi(argv[1]);
    int n = atoi(argv[2]);

    Queue* queue = createQueue(n + 1);

    for(int el = 1; el <= n; el++) {
        enqueue(queue, el);
    }

    while(!isQueueEmpty(queue)) {
        for(int i = 0; i < m-1; i++) {
            int el = dequeue(queue);
            enqueue(queue, el);
        }
        printf("%d ", dequeue(queue));
    }

    destroyQueue(queue);

    putchar('\n');
    return 0;
}
