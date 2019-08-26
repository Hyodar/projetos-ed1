
#include "../stack.h"
#include <string.h>

int bemFormada(const char* str) {
	Stack* s = createStack(strlen(str));
	
	for(;*str; str++) {
		if(*str == '(' || *str == '[') {
			pushStack(s, *str);
		} else if(*str == ')') {
			if(popStack(s) != '(') return 0;
		} else if(*str == ']') {
			if(popStack(s) != '[') return 0;
		}
	}

	if(!isStackEmpty(s)) return 0;
	destroyStack(s);

	return 1;
}

int main(int argc, char** argv) {

    char seq[4][30] = {"( ( ) [ () ] )", "( [ ) ]", "(  ) [  ]", "( [  ]"};

    for(int i = 0; i < 4; i++) {
        printf("%s\n", (bemFormada(seq[i])? "Bem formada!" : "Mal formada!"));
    }

    return 0;
}
