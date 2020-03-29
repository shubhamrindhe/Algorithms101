#include <stdio.h>
#include <stdlib.h>

#define LINK_COUNT 26
#define CHAR_OFFSET 'a'

struct Trie {
	int leaf;
	struct Trie* links[LINK_COUNT];
	void* data;
	unsigned datasize;
};

struct Trie* new_trie() {
	struct Trie* trie = (struct Trie*) malloc(sizeof(struct Trie));
	for (unsigned idx = 0; idx < LINK_COUNT; ++idx) {
		trie->links[idx] = NULL;
	}
	trie->leaf = 0;
	trie->datasize = 0;
	trie->data = NULL;
	return trie;
}

void destroy (struct Trie* trie) {
	
}

int char_idx (char character) {
	return character - CHAR_OFFSET;
}

void insert(struct Trie* root, char* string) {
	struct Trie* crawler = root;
	while (*string) {
		int idx = char_idx(*string);
		printf(" %d ",idx);
		if ( !crawler->links[idx] ) {
			crawler->links[idx] = new_trie();
		}	
		crawler = crawler->links[idx];
		++string;
	}
	printf(" \n ");
	crawler->leaf = 1;
}

struct Trie* get_node (struct Trie* root, char* string) {
	struct Trie* crawler = root;
	while (*string) {
		if ( crawler ) {
			int idx = char_idx(*string);
			printf("\t %d %c ",idx,*string);
			crawler = crawler->links[idx];
		} else {
			printf(" breaking loop ");
			return NULL;
		}
		++string;
	}
	printf(" \n ");
	return crawler;
}

int is(struct Trie* root, char* string) {
	struct Trie* node = get_node(root, string);
	return node->leaf;
}

struct Trie* get_node (struct Trie* root, char* string) {
	struct Trie* crawler = root;
	while (*string) {
		if ( crawler ) {
			int idx = char_idx(*string);
			printf("\t %d %c ",idx,*string);
			crawler = crawler->links[idx];
		} else {
			printf(" breaking loop ");
			return NULL;
		}
		++string;
	}
	printf(" \n ");
	return crawler;
}

int main () {
	
	struct Trie* root = new_trie();
	insert(root,"shubham");
	
	printf("\t %d \n",is(root,"shubham"));
	printf("\t %d \n",is(root,"shubh"));
	printf("\t %d \n",is(root,"shubham"));
	
	printf("\t %p \n",get_node(root,"shubham"));
	printf("\t %p \n",get_node(root,"shubh"));
	printf("\t %p \n",get_node(root,"shubham"));
	
	printf("\n\n\n\n %u %u \n",sizeof(struct Trie*),sizeof(struct Trie));
	return 0;
}
