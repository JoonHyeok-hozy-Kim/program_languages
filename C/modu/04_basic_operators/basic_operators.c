#include <stdio.h>
int main() {

	int x, y, z;
	// Assigning
	x = y = z = 5;
	//printf("x : %d, y : %d, z : %d \n", x, y, z);

	int a, b;
	a = 10;
	b = 3;
	
	// Arithmatic Operators
	/*printf("a + b = %d \n", a + b);
	printf("a - b = %d \n", a-b);
	printf("a * b = %d \n", a*b);
	printf("a / b = %d \n", a/b);
	printf("a %% b = %d \n", a%b);*/
	
	double b_d;
	b_d = 3;
	// Division in Float
	//printf("a / b = %f \n", a / b_d);

	// Addition and Assignment
	/*a = a + 1;
	printf("new_a : %d \n", a);
	a += 1;
	printf("new_a : %d \n", a);*/

	// Prefix and Postfix notation
	/*a = 1;
	printf("++a : %d \n", ++a);
	a = 1;
	printf("a++ : %d \n", a++);
	printf("after : %d \n", a);*/



	// Bit Operators
	a = 0xAF;	// 10101111
	b = 0xB5;	// 10110101

	printf("a & b = %x \n", a & b);
	printf("a | b = %x \n", a | b);
	printf("~a = %x \n", ~a);
	printf("a << 2 = %x \n", a << 2);
	printf("b >> 3 = %x \n", b >> 3);

}