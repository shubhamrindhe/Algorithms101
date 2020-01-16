#include<stdio.h>
#include "../linked_list.h"

int main(){
	
	
	
	/*
	struct Node* n = create_node(0);
	if(n->next==NULL && n->prev==NULL)
		printf("its null\n");
	*/
	
	
	struct Node* r = create_linked_list();
	printf("%f",(r->data));
	push(r,1);
	printf("%f",(r->data));
	return 0;
}