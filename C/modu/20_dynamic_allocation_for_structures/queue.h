#include "node.h"

struct Queue {
	struct Node* header;
	struct Node* trailer;
	int len;
};

struct Queue* create_queue();
int len(struct Queue*);
void enqueue(struct Queue*, int e);
int first(struct Queue*);
int dequeue(struct Queue*);