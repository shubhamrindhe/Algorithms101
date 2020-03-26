
#ifndef _STDLIB_H_
	#include <stdlib.h>
#endif


#ifndef _STDIO_H_
	#include <stdio.h>
#endif

#ifndef _STRING_H_
	#include <string.h>
#endif

typedef unsigned char byte;

enum DATATYPES {
	BYTE,
	INT,
	CHAR,
};

enum LINK_IDX {
	LEFT = 0,
	RIGHT = 1,
	LAST = 0,
	NEXT = 1,
};


struct Node {
	struct Node** links;
	unsigned linkcount;
	unsigned datasize;
	void* data;
	long value;
};

struct Node* create_node(unsigned datasize, int linkcount) {
	struct Node* node = NULL;
	node = (struct Node*) malloc(sizeof(struct Node));
	node->linkcount = linkcount;
	node->datasize = datasize;
	node->links = (struct Node**) malloc(linkcount*sizeof(struct Node*));
	node->data = (void*) malloc(datasize);

	return node;
}

void print_links (struct Node* node) {
	for (unsigned i=0; i < node->linkcount; ++i) {
		printf(" %p \n",node->links[i]);
	}
}

struct Node* link_node(struct Node* node1, unsigned idx, struct Node* node2) {
	if (idx < node1->linkcount) {
		node1->links[idx] = node2;
		return node1;
	} else {
		return NULL;
	}
}

void setData(struct Node* node, void* data) {
	memcpy(node->data, data, sizeof(node->data));
}

void* getData(struct Node* node, void* dataholder) {
	memcpy(dataholder, node->data, sizeof(node->data));
	return node->data;
}

