#include "node.h"

struct Stack {
	int top;
	int size;
	Node* topPtr;
	Node* root;
	byte* data;
}

struct Stack* creat_stack(){
	struct Stack* satck = (struct Satck*) malloc(sizeof(struct Stack));
	satck->top = -1;
	
}