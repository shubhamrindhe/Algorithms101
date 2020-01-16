#include<stdlib.h>

struct Node {
	struct Node* next;
	struct Node* prev;
	double data ;
};


struct Node* create_node(double data){
	struct Node* node = NULL;
	node = (struct Node*) malloc(sizeof(struct Node));
	node->prev = NULL;
	node->data = data;
	node->next = NULL;
	return node;
}