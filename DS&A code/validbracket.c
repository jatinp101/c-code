#include <stdlib.h>
#include <stdio.h>

#define MAXSIZE 1000
#define NONCHAR '\0'

struct Stack {
	char * val;
	int size;
	int sp; /* Stack pointer */
};

struct Stack * createStack(int size);
void destroyStack(struct Stack *s);

char peek(struct Stack *stack);
void push(struct Stack *stack, char newval);
char pop(struct Stack *stack);
enum Bool isEmpty(struct Stack *stack);
void displayOutcome(char str[]);

enum Bool {false, true};
enum Bool isValid(char * str);

void main()
{
displayOutcome("()[]");
displayOutcome("(()[])");
displayOutcome("([)[])");
displayOutcome("([]]()");
displayOutcome("(([])[])");
displayOutcome("(([])[]");
}

/* Modfiy this function */
enum Bool isValid(char * str)
{
	struct stack *temp = createStack(MAXSIZE);
	char x;
	int i=0;
	while (str[i] != NULL) {
		 if (str[i]=='('||str[i]=='['||str[i]=='{') {
         push(temp, str[i]);
		   i++;
         continue;
      }
      if (isEmpty(temp))
         return false;
      switch (str[i]) {
      case ')':
         x = peek(temp);
        pop(temp);
         if (x=='{' || x=='[')
            return false;
         break;
      case '}':
         x = peek(temp);
          pop(temp);
         if (x=='(' || x=='[')
            return false;
         break;
      case ']':
         x = peek(temp);
          pop(temp);
         if (x =='(' || x == '{')
            return false;
         break;
      }
	  i++;
	}
return true;
}


void displayOutcome(char str[])
{
printf("String %s is",str);
if (isValid(str) == true) {
	printf(" valid\n");
}
else {
	printf(" invalid\n");
}

}


struct Stack * createStack(int size)
{
struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));
stack->size = size;
stack->sp = -1;
stack->val = (char *) malloc(size*sizeof(char));
}

void destroyStack(struct Stack *stack)
{
free(stack->val);
free(stack);
}

char peek(struct Stack *stack)
{
if (stack->sp < 0) {
	return NONCHAR;
}
else {
	return stack->val[stack->sp];
}
}

void push(struct Stack *stack, char newval)
{
if (stack->sp < stack->size) {
	stack->sp++;
	stack->val[stack->sp] = newval;
}
}

char pop(struct Stack *stack)
{
if (stack->sp < 0) {
	return NONCHAR;
}
else {
	char c = stack->val[stack->sp];
	stack->sp--;
	return c;
}
}

enum Bool isEmpty(struct Stack *stack)
{
if (stack->sp < 0) return true;
else return false;
}



