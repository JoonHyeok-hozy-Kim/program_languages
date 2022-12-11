#include <stdio.h>
#include "arithmatic.h"
#include "bit_operation.h"
#include "loop_related.h"
#include "conditional_related.h"
#include "function_related.h"


void main(int argc, char** argv) {

	/* 1. Arithmatic Matters */
	/* 1) Avoid using float or double. */


	/* 2) Avoid calling division operation as possible */
	//int i, n=10;
	/* Using division operation */
	//for (i = 0; i < n; i++) printf("%d", inc_second_division(i));

	/* Using condition to avoid division operation as much as possible */
	//for (i = 0; i < n; i++) printf("%d", inc_second_condition(i));


	/* 3) When dividing a number with another number that is a power of 2, use shift opeartion. */
	//int n = 99, r=5;
	//printf("%d", divide_by_two_powers_r(n, r));



	/* 2. Bit Operation Application */
	/* 1) When storing multiple boolean like information  */
	//human_simulation();



	/* 3. Loop related. */
	/* 1) Find ways to avoid loop if possible */
	//summation_comparison();



	/* 4. Conditional related */
	/* 1) Use Binary Break Down if applicable. */
	//binary_break_down_comparison();

	/* 2) Or use look up table if applciable */



	/* 5. Function related */
	/* 1) Use inline function */
	func_compare();


}