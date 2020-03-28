#include <stdio.h>
#include <stdlib.h>

struct CircularQueue {
	char* data;
	unsigned size;
	int head;
	int tail;
};

struct CircularQueue* new_queue(unsigned size) {
	struct CircularQueue* queue = (struct CircularQueue*) malloc(sizeof(struct CircularQueue));
	queue->head = -1;
	queue->tail = -1;
	queue->size = size;
	queue->data = (char*) malloc(sizeof(char)*size);
	
	return queue;
}

void destroy (struct CircularQueue* queue) {
	free(queue->data);
	free(queue);
}

void print_queue (struct CircularQueue* queue) {
	printf("\n");
	for (unsigned idx = 0; idx < queue->size; ++idx) {
		printf("\t %d %c %s \n",idx ,queue->data[idx], idx==queue->head ? (idx==queue->tail ? " <- HEAD & TAIL" : " <- HEAD ") : (idx==queue->tail ? " <- TAIL " : ".") );
	}
	printf("\n");
}

void enqueue(struct CircularQueue* queue, char character) {	
	if (queue->head == -1 && queue->tail == -1) {
		++(queue->head);
		queue->data[++(queue->tail)] = character;
	} else {
		unsigned new_tail = (queue->tail + 1) % queue->size; 
		if (queue->head != new_tail) {
			queue->tail = new_tail;
			queue->data[queue->tail] = character;
		} else {
			printf("\n\t Queue Overflow!\n");
			return;
		}
	}
}

char dequeue(struct CircularQueue* queue) {
	if (queue->head != -1 || queue->tail != -1) {
		unsigned new_head = (queue->head + 1) % queue->size;		
		char item = queue->data[queue->head];
		queue->data[queue->head] = '_';
		if (queue->head == queue->tail) {
			queue->head = -1;
			queue->tail = -1;
		} else {
			queue->head = new_head;
		}
		return item;
	} else {
		printf("\n\t Queue Empty!\n");
		return -1;
	}
}

int main () {
	struct CircularQueue* q = new_queue(5);
	print_queue(q);
	for (unsigned i = 65; i <= 70; ++i) {
		print_queue(q);
		enqueue(q,i);
		printf("\n %u %d %d %c ", q->size, q->head, q->tail, q->data[q->tail]);
	}
	
	print_queue(q);
	char ch;
	while ( 1 ) {
		print_queue(q);
		printf("Enter Choice : ");
		scanf("%c",&ch);
		switch (ch) {
			case 'e':
				printf("Enter Char : ");
				int c;
				scanf("%d",&c);
				enqueue(q,c);
				break;
			case 'd':
				printf("\n dqed : %c",dequeue(q));
				break;
		}
	}
	
	print_queue(q);
	destroy(q);
	return 0;
}
