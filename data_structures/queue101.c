#include <stdio.h>
#include <stdlib.h>

struct Queue {
	char* data;
	unsigned size;
	int head;
	int tail;
};

struct Queue* new_queue(unsigned size) {
	struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
	queue->head = -1;
	queue->tail = -1;
	queue->size = size;
	queue->data = (char*) malloc(sizeof(char)*size);
	
	return queue;
}

void destroy (struct Queue* queue) {
	free(queue->data);
	free(queue);
}

void print_queue (struct Queue* queue) {
	printf("\n");
	for (unsigned idx = 0; idx < queue->size; ++idx) {
		printf(" %c ",queue->data[idx]);
	}
	printf("\n");
}

void enqueue(struct Queue* queue, char character) {
	if (queue->size-1 == queue->tail) {
		printf("\n\t Queue Overflow!\n");
		return;
	} else {
		if (queue->head == -1) {
			queue->head++;
		}
		queue->data[++(queue->tail)] = character;
	}
}

char dequeue(struct Queue* queue) {
	if (queue->head == queue->size) {
		printf("\n\t Queue Empty!\n");
		return -1;
	} else {
		return queue->data[(queue->head)++];
	}
}

int main () {
	struct Queue* q = new_queue(10);
	print_queue(q);
	for (unsigned i = 65; i <= 75; ++i) {
		enqueue(q,i);
		printf("\n %u %d %d %c ", q->size, q->head, q->tail, q->data[q->tail]);
	}
	
	print_queue(q);
	char ch;
	while ( (ch = dequeue(q)) != -1 ) {
		printf("\n %c ",ch);
	}
	
	print_queue(q);
	destroy(q);
	return 0;
}
