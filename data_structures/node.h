#include<stdlib.h>
#include<stdio.h>

#include "names.h"

typedef unsigned char byte;

struct Node {
	struct Node** links;
	void* data;
};

struct Node* create_node(int datasize, int linkcount) {
	struct Node* node = NULL;
	node = (struct Node*) malloc(sizeof(struct Node));
	node->links = (struct Node**) malloc(linkcount*sizeof(struct Node*));
	node->data = (void*) malloc(datasize);

	return node;
}

void setData(struct Node* node, void* data) {
	memcpy(node->data, data, sizeof(*data));
}

