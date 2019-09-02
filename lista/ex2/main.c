
#include "../node.h"
#include "time.h"

Node* procura(List* l, int el) {
	while(l != NULL) {
		if(l->el == el) return l;
		l = l->next;
	}

	return NULL;
}
	

int main() {
	int v;
	List* l = createList();
	srand(time(NULL));

	do {
		v = rand() % 30;
		l = listAdd(l, v);
	} while(v != 12);

	printList(l);
	printf("%d\n", procura(l, 30));

	destroyList(l);
	return 0;
}
