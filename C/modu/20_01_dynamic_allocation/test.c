#include "dynamic_alloc.h"

void main() {

	/* Create dynamic array using malloc function */
	//dynamic_array_creation_test();

	/* Two dimensional Arrays */
	/* 1. Using pointer array */
	//two_dim_dynamic_array_using_pointer_array_test();

	/* 2. Using array pointer */
	// This syntax is not available for Visual Studio, which uses C90 compiler.
	// VLA is supported from C99. 
	two_dim_dynamic_array_using_array_pointer_test();
}