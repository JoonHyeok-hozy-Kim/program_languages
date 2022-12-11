#include <stdlib.h>
#include "struct_dynamic_allocation_test.h"
#include "node.h"
#include "queue.h"
#include "memory.h"

void main() {

	/* Making array of structures */
	//struct_array_creation_test();

	/* Node Test */
	//struct Node* node_array;
	//int i, num_nodes;

	//num_nodes = 10;
	//node_array = (struct Node*)malloc(sizeof(struct Node) * num_nodes); //
	//for (i = 0; i < num_nodes; i++) {
	//	node_array[i] = *(create_node(i));
	//}

	//for (i = 0; i < num_nodes - 1; i++) {
	//	link_node(&node_array[i], &node_array[i + 1]);
	//}

	//traverse_nodes(node_array);


	/* Queue Implemented for C */
	//struct Queue* q = create_queue();
	//int i;

	//for (i = 0; i < 10; i++) {
	//	enqueue(q, i);
	//}

	//printf("%d\n", first(q));

	//for (i = 0; i < 10; i++) {
	//	printf("%d\n", dequeue(q)); //
	//}


	/* Memory related functions */
	//memcpy_test();
	//memmove_test();
	memcmp_test();

}