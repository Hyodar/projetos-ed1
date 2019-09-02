
#include <stdio.h>
#include "node.h"

int main() {
	List* list = createList();
	list = listAdd(list, 1);
	list = listAdd(list, 2);
	list = listRemove(list, 2);
	
	printList(list);
	destroyList(list);

	return 0;
}
