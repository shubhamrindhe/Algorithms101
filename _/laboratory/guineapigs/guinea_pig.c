
#include "../../DataStructures/node.h"
#include<string.h>

int main(){
	struct Node* r = create_node(sizeof(int),5);
	printf("%d\n",sizeof(r->data));
	//push(r,1);
	printf("%d\n",sizeof(r->links));
	printf("%d\n",sizeof(struct Node));
	printf("%d\n",sizeof(int));
	
	
	//struct Node* r1 = create_node(sizeof(int),5);
	int a = 40;
	//memcpy(r->data,&a,sizeof(a));
	
	setData(r,(void*)&a);
	
	printf("lol %d\n",*(int*)(r->data));
	
	
	return 0;
}