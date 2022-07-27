#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

struct Queue* create_queue() {
	struct Queue* new_queue = (struct Queue*)malloc(sizeof(struct Queue));
	new_queue->header = NULL;
	new_queue->trailer = NULL;
	new_queue->len = 0;

	return new_queue;
}


int len(struct Queue* q) {
	return q->len;
}

int is_empty(struct Queue* q) {
	if (q->len == 0) {
		return 1;
	}
	else {
		return 0;
	}
}


void enqueue(struct Queue* q, int e) {
	struct Node* new_node = create_node(e);

	if (is_empty(q)) {
		q->header = new_node;
	}
	else {
		q->trailer->next = new_node;
	}
	q->trailer = new_node;
	q->len++;
}


int first(struct Queue* q) {
	if (is_empty(q)) {
		return -999;
	}
	return q->header->data;
}


int dequeue(struct Queue* q) {
	int result;

	if (is_empty(q)) {
		return -999;
	}
	result = q->header->data;
	q->header = q->header->next;
	q->len--;
	return result;
}

