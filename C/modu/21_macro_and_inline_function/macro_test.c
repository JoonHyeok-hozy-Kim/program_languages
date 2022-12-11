#include <stdio.h>
#define square(x) x*x // Executed before compiling.
#define parenthsized_square(x) (x)*(x)

void macro_square_test() {
	int i = 2;
	double j = 1.2;

	printf("%d\n", square(i));
	printf("%lf\n", square(j));


	printf("%d\n", square(i+1)); // 2 + 1 * 2 + 1 = 5
	printf("%d\n", parenthsized_square(i + 1)); // Solution!
}



#define print_var_name(var) printf(#var "\n"); // Printing the name of the variable, not the value.

void print_var_name_test() {
	int i = 1;
	float j = 1.1;
	char c = 'c';

	print_var_name(i);
	print_var_name(j);
	print_var_name(c);

}



#define concatenate(x, y) x##y

void concatenate_test() {
	int concatenate(a, b);

	ab = 3;
	printf("%d", ab);

}