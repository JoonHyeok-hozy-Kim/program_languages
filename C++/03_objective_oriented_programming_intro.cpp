#include "03_objective_oriented_programming_intro.h"
#include <iostream>

/* How to allocate and free memory in C++ */
/* new : used for the dynamic memory allocation. cf.) malloc in C  */
/* delete : used for the free memory in heap occupied by new. cf.) free in C  */
void new_delete_test() {
	int* p = new int;		// new used!
	*p = 3;

	std::cout << "*p : " << *p << std::endl;
	delete p;				// free memory space in Heap occupied by p
	return;
}

/* Array allocation using new and delete syntax! */
void array_allocation_with_new() {
	int array_size;
	std::cout << "Input array size : ";
	std::cin >> array_size;
	int* list = new int[array_size];			// list size defined!

	for (int i = 0; i < array_size; i++) {		// new syntax! local variable i defined in for-loop!
		std::cout << i + 1 << "-th element : ";
		std::cin >> list[i];
	}

	std::cout << "Result : [";
	for (int i = 0; i < array_size; i++) {
		std::cout << list[i];
		if (i == array_size - 1) {
			std::cout << "]";
		}
		else {
			std::cout << ", ";
		}
	}
	

	delete[] list;								// free memory of list in Heap. Since new was used with [], delete should be used likewise.
	return;
}