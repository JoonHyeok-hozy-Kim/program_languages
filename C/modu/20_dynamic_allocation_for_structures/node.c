#include <stdlib.h>
#include "node.h"


struct Node* create_node(int val) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = val;
	new_node->next = NULL;
	return new_node;
}


struct Node* link_node(struct Node* prev, struct Node* next) {
	prev->next = next;
	return prev;
}

void traverse_nodes(struct Node* node) {
	printf("%d ", node->data);
	if (node->next) {
		traverse_nodes(node->next);
	}
}