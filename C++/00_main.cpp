#pragma once
#include "00_main.h"

int main() {

	/* 1-1. Hello World */
	//say_hello();			 // Test printing "Hello World" in C++.

	/* 1-2. Namespace*/
	//call_namespaces();	 // Test various ways of defining and calling namespaces.

	/* 1-3 Similarities with C */
	//variables();		// Test defining and calling various data types as variables.
	//pointers();		// Test pointing and shifting various variables using pointers.
	//user_input();		// Test user input and output functions (iostream library)


	/* 2. Reference */
	//c_pointer_review();				// Brief review on pointer related syntaxes in C
	//reference_usage();				// Define and try various operations with a reference to a variable
	//reference_vs_pointer();			// Pointer vs Reference
	//reference_array_test();			// References to array elements

	/* Reference and Function */
	//reference_as_input_parameter();	// Using reference as a function input parameter
	//reference_as_output_test();		// Reference output only allowed when the function input is a reference. In order to prevent dangling reference.


	/* 3. Introduction to the Objective Oriented Programming in C++ */
	//new_delete_test();		// syntax for new and delete
	//array_allocation_with_new();	// 

	/* 4. Objective Oriented Programming */
	/* 4-1. Class */
	//animal_class_test();
	//date_class_test();

	/* 4-2. Function Overload */
	//overload_variables_test();
	//implicit_type_change_test();
	//date_test();

	/* 4-3. Copy Constructor and Destructor */
	//destructor_test();		// Constructor and Destructor Test
	//copy_constructor_test();	// Copy Constructor Test

	/* 4-4. Constant and Static */
	//initializer_list_and_const_test();
	//this_test();
	//ref_return_test();
	//const_function_test();

	/* 4-5. [Application] Custom String Class implementation : MyString */
	//mystring_instance_test();

	/* 4-6. Explicit and Mutable */
	//explict_test();
	mutable_test();

	return 0;
}