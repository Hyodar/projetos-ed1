
#include "../node.h"
#include <time.h>

List* cria_circular(List* l) {
	List* aux = l;

	if(l == NULL) return l;
	
	while(l->next != NULL) l = l->next;
	l->next = aux;
	
	return l;
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
	l= cria_circular(l);
	printList(l);

	destroyList(l);
	return 0;
}

	
