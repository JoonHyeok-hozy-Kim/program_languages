#include <stdio.h>

int global_var;  // Allways initialized to 0 when defined.
void add_one_to_global();

int* local_variable_test();
int* static_variable_test();


void main() {

	/* Local Variable */
	//int a = 3;
	//{
	//	int a = 4; // Available only in {} local area.
	//	printf("%d\n", a);
	//}

	//printf("%d\n", a);


	/* Global Variable Manipulation */
	//printf("global_var : %d\n", global_var); //

	//printf("Add one in main!\n");
	//global_var++;
	//printf("global_var : %d\n", global_var);

	//add_one_to_global();

	//printf("Add one in main!\n");
	//global_var++;
	//printf("global_var : %d\n", global_var);


	/* Static Variable */
	//int* pa = local_variable_test();
	int* pa = static_variable_test();
	printf("%d\n", *pa);
	printf("In main, pa at : %p\n\n", pa);

	static_variable_test();
	printf("%d\n", *pa);
	static_variable_test();
	printf("%d\n", *pa);
	static_variable_test();
	printf("%d\n", *pa);
	static_variable_test();
	printf("%d\n", *pa);

}


void add_one_to_global() {
	printf("In add_one_to_global(), add one!\n");
	global_var++;
	printf("global_var : %d\n", global_var);
};

int* local_variable_test() {
	int a = 3;
	printf("In local_variable_test, a at : %p\n", &a);
	return &a;
};

int* static_variable_test() {
	static int b = 4;
	static int cnt;
	printf("In static_variable_test, b at : %p\n", &b);
	b++;
	return &b;
};