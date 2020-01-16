#include "node.h"

/*
struct List{
	struct Node* head;
	struct Node* tail;
	char class;
}

struct List* create_list(char class){
	struct List* list = (struct List*) malloc(sizeof(struct List));
	list->head = NULL;
	list->tail = NULL;
	list->class = class;
	return list;
}
*/
struct Node* create_linked_list(){
	struct Node* root = NULL;
	//root = NULL;
	return root;
}


void push(struct Node* root,double data){
	struct Node* node = create_node(data);
	printf("%d",node->data);
	/*if(root==NULL){
		root = node;
	}else{	
	}
	*/
	return ;
}













