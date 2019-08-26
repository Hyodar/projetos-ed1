
#include "stack.h"

int main(int argc, char** argv) {
	
	Stack* s = createStack(4);

	pushStack(s, 1);
	pushStack(s, 2);
	pushStack(s, 4);

	while(!isStackEmpty(s)) {
		printf("%d\n", popStack(s));
	}

	destroyStack(s);
	return 0;
}
