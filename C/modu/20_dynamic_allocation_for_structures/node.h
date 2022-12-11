#pragma once

struct Node {
	int data;
	struct Node* next;
};

struct Node* create_node(int val);
struct Node* link_node(struct Node* prev, struct Node* next);
void traverse_nodes(struct Node*);