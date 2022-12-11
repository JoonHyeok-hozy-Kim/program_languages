#include <stdio.h>
#include "void_test.h"

void main(int argc, char **argv) {

	/* void tests */
	//void_test_main();


	/* main function test */
	int i;
	printf("The number of input variables : %d\n", argc);
	printf("The path to this program : %s\n", argv[0]);

	for (i = 0; i < argv; i++) {
		printf("Input %d : %s\n", i+1, argv[i]);
	}


	return;
}