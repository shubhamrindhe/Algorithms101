#include <stdio.h>
#include <stdlib.h>

struct Stack {
	char* data;
	unsigned size;
	int top;
};

struct Stack* new_stack(unsigned size) {
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
	stack->top = -1;
	stack->size = size;
	stack->data = (char*) malloc(sizeof(char)*size);
	
	return stack;
}

void destroy (struct Stack* stack) {
	free(stack->data);
	free(stack);
}

void print_stack (struct Stack* stack) {
	printf("\n");
	for (unsigned idx = 0; idx < stack->size; ++idx) {
		printf(" %c ",stack->data[idx]);
	}
	printf("\n");
}

void push(struct Stack* stack, char character) {
	if (stack->size-1 == stack->top) {
		printf("\n\t Stack Overflow!\n");
		return;
	} else {
		stack->data[++(stack->top)] = character;
	}
}

char pop(struct Stack* stack) {
	if (stack->top == -1) {
		printf("\n\t Stack Underflow!\n");
		return -1;
	} else {
		return stack->data[(stack->top)--];
	}
}

int main () {
	struct Stack* s = new_stack(10);
	print_stack(s);
	
	for (unsigned i = 65; i <= 75; ++i) {
		push(s,i);
		printf("\n %u %d %c ",s->size,s->top, s->data[s->top]);
	}
	
	print_stack(s);
	char ch;
	while ( (ch = pop(s)) != -1 ) {
		printf("\n %c ",ch);
	}
	
	print_stack(s);
	destroy(s);
	return 0;
}
