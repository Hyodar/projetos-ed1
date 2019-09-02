
#include "../node.h"
#include "time.h"

int procura(List* l, int el) {
	while(l != NULL) {
		if(l->el == el) return l;
		l = l->next;
	}

	return NULL;
}

List* separa(List* l1, int el) {
	List* l2 = createList();
	Node* pos = procura(l1, el);

	if(pos != NULL) {
		l2 = l1->next;
		l1->next = NULL;
	}

	return l2;
}

int main() {
	 int v;
	 List* l = createList();

	 srand(time(NULL));

	 do {
		 v = rand() % 14;
		 l = listAdd(l, v);
	 } while(v != 7);

	 printf("------\n");
	 printList(l);

	 List* l2 = separa(l, 7);

	 printf("------\n");
	 printList(l);

	 printf("------\n");
	 printList(l2);

	return 0;
}

