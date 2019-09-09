#include "queue.h"

int main () {
   int i, m, n;
   printf("Jogo de Josephus, digite o passo da morte e número de competidores: ");
   scanf("%d %d", &m, &n);
   Queue *q = createQueue ();
   for (i = 1; i <= n; i++) {
      q = enqueue (q, i);
   }
   i = 1;
   while (!empty(q)) {
       int e = front(q);
       q = dequeue(q);
       if (empty(q)){
          printf(", sobrevivente: %d\n", e);
       }
       else if ((i % m) == 0) {
          printf("%d ", e);
       }
       else {
          q = enqueue (q, e);
       }
       i++;
   }
   freeQueue (q);
   return 0;
}
