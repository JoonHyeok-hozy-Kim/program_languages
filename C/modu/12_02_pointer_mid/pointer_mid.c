#include <stdio.h>
int main() {

	//// Constant Pointer
	//int a = 3;
	//int b = 4;
	//const int* pa = &a;

	//printf("*pa  : %d \n", *pa);

	//a = 5;
	//printf("*pa  : %d \n", *pa);

	////*pa = 3;	// Wrong. 3 is not a constant int variable.
	//pa = &b;	// Correct. b is a constant int variable.
	//printf("*pa  : %d \n", *pa);
	////p_a = &b;


	//int* const p_a = &a;
	//printf("*p_a : %d \n", *p_a);
	////p_a = &b;	// Wrong. Cannot assign variable to a constant. 
	//printf("*p_a : %d \n", *p_a);


	//// Pointer Addition
	//int a;
	//int* pa;
	//pa = &a;

	//printf("The value of pa :       %p\n", pa);
	//printf("The value of (pa + 1) : %p\n", pa+1);	//Pushed 4 digits. Why?) int takes 4 Byte.

	//double b;
	//double* pb;
	//pb = &b;

	//printf("The value of pb :       %p\n", pb);
	//printf("The value of (pb + 1) : %p\n", pb + 1);	//Pushed 8 digits. Why?) double takes 8 Byte.

	//char c;
	//char* pc;
	//pc = &c;

	//printf("The value of pc :       %p\n", pc);
	//printf("The value of (pc + 1) : %p\n", pc + 1);	//Pushed 1 digits. Why?) char takes 1 Byte.


	//// Pointer Deduction
	//int a;
	//int* pa;
	//pa = &a;

	//printf("The value of pa :       %p\n", pa);
	//printf("The value of (pa - 1) : %p\n", pa - 1);	//Pushed 4 digits. Why?) int takes 4 Byte.



	//// Pointer address of Array Elements : adjacent!
	//int a[3] = { 1,2,3 };
	//int i;
	//int* p_a;
	//p_a = &a[0];

	///*for (i = 0; i < 3; i++) {
	//	printf("a[%d] : %p \n", i, &a[i]);
	//}*/

	//for (i = 0; i < 3; i++) {
	//	printf("Address of a[%d] : %p vs", i, &a[i]);
	//	printf("Address of (p_a + %d) : %p\n", i, p_a+i);
	//}


	// Multi-dimensional Array
	/*int a[4][3] = {
		{1,2,3}, {4,5,6}
	};
	int i, j;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 3; j++) {
			printf("a[%d][%d] %p \t", i, j, &a[i][j]);
		}
		printf("\n");
	}*/

	// The usage of the name of an array
	int arr[3] = { 1,2,3 };

	printf("First Element's Address  : %p \n", &arr[0]);
	printf("Array's Address          : %p \n", &arr);
	printf("Size of Array            : %d \n", sizeof(arr));
	printf("Third Element *(arr + 2) : %d \n", *(arr + 2));

	return 0;
}