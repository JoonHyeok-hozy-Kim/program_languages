#include "02_reference.h"
#include <iostream>

void c_pointer_review() {
	int number = 5;
	std::cout << "In c_pointer_review, number : " << number << std::endl;
	change_int_pointer_val_test(&number);
	std::cout << "In c_pointer_review, number : " << number << std::endl;

	return;
}

int change_int_pointer_val_test(int* p) {
	std::cout << "In change_int_pointer_val_test, previously pointing at : " << *p << "\n" << std::endl;
	*p = 5;
	std::cout << "In change_int_pointer_val_test, currently pointing at : " << *p << "\n" << std::endl;

	return 0;
}

void reference_usage() {
	int a = 10;
	int& ref_a = a;		// Reference should specify the target of reference when defined.

	std::cout << "a : " << a << std::endl;
	std::cout << "ref_a : " << ref_a << std::endl;

	a = 20;
	std::cout << "a : " << a << std::endl;
	std::cout << "ref_a : " << ref_a << std::endl;

	ref_a = 30;
	std::cout << "a : " << a << std::endl;
	std::cout << "ref_a : " << ref_a << std::endl;

	int b = -3;
	ref_a = b;		// This is simply equivalent to "a = b"
	std::cout << "a : " << a << std::endl;
	std::cout << "ref_a : " << ref_a << std::endl;

}


void reference_vs_pointer() {
	int a = 10;
	int* pointer_a;		// Pointer does not have to specify the target when defined.
	int& ref_a = a;		// Reference should specify the target.

	pointer_a = &a;
	std::cout << "a : " << a << std::endl;
	std::cout << "pointer_a (" << pointer_a << ") : " << *pointer_a << std::endl;
	std::cout << "ref_a : " << ref_a << std::endl;
	std::cout << "----------------------" << std::endl;


	/* Pointer can freely change the target of pointing while reference cannot */
	int b = 20;
	std::cout << "Pointer target changed to b." << std::endl;
	pointer_a = &b;
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << "pointer_a (" << pointer_a << ") : " << *pointer_a << std::endl;
	std::cout << "ref_a : " << ref_a << std::endl;
	std::cout << "----------------------" << std::endl;

	std::cout << "Reference allocation to b, which will change a as well." << std::endl;
	ref_a = b;
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << "pointer_a (" << pointer_a << ") : " << *pointer_a << std::endl;
	std::cout << "ref_a : " << ref_a << std::endl;
	std::cout << "----------------------" << std::endl;

	/* Pointer is allocated memory while referece not necessarily is not */
	std::cout << "sizeof(pointer_a) : " << sizeof(pointer_a) << std::endl;
	std::cout << "sizeof(ref_a) : " << sizeof(ref_a) << std::endl;;
	std::cout << "----------------------" << std::endl;

}

void reference_array_test() {

	/* arrays of references are illegal in C++  */
	/* illegal code example */
	//int& a[3] = {1,2,3}

	/* Instead we can make reference for array elements */
	int arr[3] = { 1,2,3 };
	int(&ref)[3] = arr;
	int i;

	for (i = 0; i < 3; i++) {
		std::cout << ref[i] << std::endl;
	}

};


/* Reference as a function input */
void reference_as_input_parameter() {
	int n = 5;

	std::cout << n << std::endl;
	change_value_input_ref(n);
	std::cout << n << std::endl;
}

int change_value_input_ref(int& n) {
	n = 3;
	return 0;
}

/* Reference as a function output : Only if the input is a reference as well */
/* Why? : In order to prevent the existence of a dangling reference! */
void reference_as_output_test() {
	int a = 10;
	std::cout << "In reference_as_output_test, a : " << a << std::endl;

	int b = ref_input_output(a);
	std::cout << "In reference_as_output_test, a : " << a << std::endl;
	std::cout << "In reference_as_output_test, b : " << b << std::endl;

	return;
}

int& ref_input_output(int& r) {
	std::cout << "In ref_input_output, r : " << r << std::endl;
	r = 6;
	std::cout << "In ref_input_output, r : " << r << std::endl;
	return r;
}