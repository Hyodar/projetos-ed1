#include "stack.h"

int main () {
   int i = 0;
   char *expr = "( 9 + ( ( 0 + 1 ) * ( 2 * 3 ) ) )";
   Stack *s = createStack();
   while (expr[i] != '\0') {
      if ( (expr[i] == '+') || (expr[i] == '*') ) {
         s = push(s, expr[i]);
      }
      else if (expr[i] == ')') {
         printf("%c ", top(s));
         s = pop(s);
      }
      else if ( (expr[i] >= '0') && (expr[i] <= '9') ){
         printf("%c ", expr[i]);
      }
      i++;
   }
   printf("\n");
   freeStack (s);
   return 0;
}
