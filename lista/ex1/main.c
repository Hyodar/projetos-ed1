
#include "../node.h"
#include "time.h"

int conta_nos(List* l) {
	int count = 0;
	
	while(l != NULL) {
		++count;
		l = l->next;
	}

	return count;
}

int main() {
	int v;
	List* l = createList();
	srand(time(NULL));

	do {
		v = rand() % 30;
		l = listAdd(l, v);
	} while(v != 12);

	printf("%d\n", conta_nos(l));
	printList(l);

	destroyList(l);
	return 0;
}
