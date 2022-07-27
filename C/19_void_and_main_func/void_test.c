#include <stdio.h>
#include "void_test.h"

void void_test_main() {

	/* void function intro */
	//int i = 100;
	//printf("%d\n", i);//
	//add_one(&i);
	//printf("%d\n", i);


	/* void pointer */
	//void* v;
	//double d = 123.3;

	//v = &d;
	//printf("%lf at [%p]", *(double *)v, v);  // Should verify the datatype before calling void pointer.


	/* void pointer and endian tester */
	void_pointer_and_endian_tester();

}

void add_one(int* num) {
	(*num) += 1;
}

void read_char(int* p, int byte) {
	do {
		printf("%x\n", *(char*)p);
		byte--;
		p = (char*)p + 1;
	} while (p && byte);
}

void void_pointer_and_endian_tester() {
	int arr[1] = { 0x12345678 };
	printf("%x\n", arr[0]);
	read_char(arr, 4);
}