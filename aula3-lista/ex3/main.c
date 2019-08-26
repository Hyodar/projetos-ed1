
#include "../stack.h"
#include <string.h>

int isLetter(char c) {
    return c >= '0' && c <= '9';
}

int isOperator(char c) {
    return c != ' ' && c != '(';
}

void posFixa(const char* str) {
	
    Stack* stack = createStack(strlen(str));

    for(;*str; str++) {
        if(isLetter(*str)) {
            putchar(*str);
            putchar(' ');
        } else {
            if(*str == ')') {
                putchar(popStack(stack));
                putchar(' ');
            } else if(isOperator(*str)) {
                pushStack(stack, *str);
            }
        }
    }

    putchar('\n');
    destroyStack(stack);
}

int main(int argc, char** argv) {

    posFixa("( 9 + ( ( 0 + 1 ) * ( 2 * 3 ) ) )");
    
	return 0;
}
