#include <stdio.h>
#include "node.h"

int main () {
	
	char a = 'A';
	char b;
	
	b = 'B';
	
	memcpy(&a, &b, sizeof(a));
	printf("\n\n %c %c\n\n",a,b);
	
	char c;
	struct Node* n = create_node(1,3);
	
	link_node(n,0,n);
	link_node(n,1,n);
	link_node(n,2,n);
	
	print_links(n);
	setData(n,&a);
	/*b = (char *) */
	getData(n,&c);
	printf("\n\n %c %d",c,sizeof(n->data));
	
	
	
	
	return 0;
}
